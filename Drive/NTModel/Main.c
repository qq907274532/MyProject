#include <ntddk.h>

#define		DEVICE_NAME					L"\\device\\NTModelDrv"
#define		LINK_NAME					L"\\dosDevices\\NTModelDrv"

#define IOCTL_BASE	0x8000
#define MY_CTL_CODE(i) CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_BASE+i, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_HELLO	MY_CTL_CODE(0)

typedef struct _DEVICE_EXTENSION 
{
  PDEVICE_OBJECT pDevice;
  UNICODE_STRING ustrDeviceName;	//�豸����
  UNICODE_STRING ustrSymLinkName;	//����������
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

VOID DriverUnload (IN PDRIVER_OBJECT pDriverObject);

NTSTATUS DispatchIoctl(PDEVICE_OBJECT pDevObj, PIRP pIrp);
NTSTATUS DispatchOK(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS DispatchWrite(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);
NTSTATUS DispatchRead (IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp)

NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObject, IN PUNICODE_STRING pRegistryPath)
{
  UNICODE_STRING 	DeviceName;
  UNICODE_STRING 	LinkName;  
  NTSTATUS 		status; 
  PDEVICE_OBJECT 	pDriverDeviceObject;  
  PDEVICE_EXTENSION 	pDevExt;
  ULONG i;
  
  //DbgPrint("Driver loaded.");
  pDriverObject->DriverUnload = DriverUnload;   
  
  // init strings
  RtlInitUnicodeString(&DeviceName, DEVICE_NAME);
  RtlInitUnicodeString(&LinkName, LINK_NAME);
  
  // to communicate with usermode, we need a device
  status = IoCreateDevice(pDriverObject, sizeof(DEVICE_EXTENSION), &DeviceName, FILE_DEVICE_UNKNOWN, 0, FALSE, &pDriverDeviceObject);
  
  if ( !NT_SUCCESS(status) ) 
    return STATUS_NO_SUCH_DEVICE;
  
  pDriverDeviceObject-> Flags |= DO_BUFFERED_IO;
  pDevExt = (PDEVICE_EXTENSION)pDriverDeviceObject->DeviceExtension;
  pDevExt->pDevice = pDriverDeviceObject;
  pDevExt->ustrDeviceName = DeviceName;
  
  // we also need a symbolic link
  status = IoCreateSymbolicLink(&LinkName,&DeviceName);
  if( !NT_SUCCESS(status) ) 
  {
    IoDeleteDevice( pDriverDeviceObject );
    return STATUS_NO_SUCH_DEVICE;
  }  
  
  pDevExt->ustrSymLinkName = LinkName;
  
  for (i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
    pDriverObject->MajorFunction[i] = DispatchOK; 
  
  // handle IRPs
  pDriverObject->MajorFunction[IRP_MJ_READ] = DispatchRead;
  pDriverObject->MajorFunction[IRP_MJ_WRITE] = DispatchWrite;
  pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DispatchIoctl; 
  
  //Do other things...   
  
  return STATUS_SUCCESS;
}

// function to dispatch the IRPs
NTSTATUS DispatchOK(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
  Irp->IoStatus.Status = STATUS_SUCCESS;
  IoCompleteRequest(Irp,IO_NO_INCREMENT);
  return STATUS_SUCCESS;
}

VOID DriverUnload (IN PDRIVER_OBJECT pDriverObject)
{
  UNICODE_STRING strLink;
  RtlInitUnicodeString(&strLink, LINK_NAME);
  
  IoDeleteSymbolicLink(&strLink);
  IoDeleteDevice(pDriverObject->DeviceObject);
  DbgPrint("[NTModelDrv] Unloaded\n"); 
}

NTSTATUS DispatchIoctl(PDEVICE_OBJECT pDevObj, PIRP pIrp)
{
  NTSTATUS status = STATUS_INVALID_DEVICE_REQUEST;
  PIO_STACK_LOCATION pIrpStack;
  ULONG uIoControlCode;
  PVOID pIoBuffer;
  ULONG uInSize;
  ULONG uOutSize;
  
  pIrpStack = IoGetCurrentIrpStackLocation(pIrp);
  uIoControlCode = pIrpStack->Parameters.DeviceIoControl.IoControlCode;
  pIoBuffer = pIrp->AssociatedIrp.SystemBuffer;
  uInSize = pIrpStack->Parameters.DeviceIoControl.InputBufferLength;
  uOutSize = pIrpStack->Parameters.DeviceIoControl.OutputBufferLength;
  
  switch(uIoControlCode) 
  {
		case IOCTL_HELLO: 
      {
        DbgPrint("[NTModelDrv] Hello\n");
        status = STATUS_SUCCESS;
      }
      break;
  }
  
  if(status == STATUS_SUCCESS)
    pIrp->IoStatus.Information = uOutSize;
  else
    pIrp->IoStatus.Information = 0;
  
  /////////////////////////////////////
  pIrp->IoStatus.Status = status;
  IoCompleteRequest(pIrp, IO_NO_INCREMENT);
  
  return status;
}

//����Ӧ�ò��write()����
NTSTATUS DispatchWrite(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp)
{
  NTSTATUS 	status = STATUS_SUCCESS;
  PVOID 		userBuffer;
  PVOID 		drvBuffer;
  ULONG 		xferSize;
  
  //���IRP��ջ�ĵ�ǰλ��
  PIO_STACK_LOCATION pIrpStack = IoGetCurrentIrpStackLocation(pIrp);
  
  //��õ�ǰд�ĳ��Ⱥͻ���
  xferSize = pIrpStack->Parameters.Write.Length;
  userBuffer = pIrp->AssociatedIrp.SystemBuffer;
  drvBuffer = ExAllocatePoolWithTag(PagedPool, xferSize, 'tseT');
  if (drvBuffer == NULL)
  {
    status = STATUS_INSUFFICIENT_RESOURCES;
    xferSize = 0;
  }
  //����ǰ�����е�����д��
  RtlCopyMemory( drvBuffer, userBuffer, xferSize );
  
  //���IO����д���״̬�ʹ�������ݳ���
  ExFreePool(drvBuffer);
  drvBuffer = NULL;
  pIrp->IoStatus.Status = status;
  pIrp->IoStatus.Information = xferSize;

  //���IRP�������²㴫��
  IoCompleteRequest( pIrp, IO_NO_INCREMENT );
  return status;
}

//����Ӧ�ò��read()����
NTSTATUS DispatchRead (IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp)
{
  NTSTATUS 	status = STATUS_SUCCESS;
  PVOID 		userBuffer;
  ULONG 		xferSize;
  
  //��ȡIRP��ջ�ĵ�ǰλ��
  PIO_STACK_LOCATION pIrpStack =
    IoGetCurrentIrpStackLocation( pIrp );
  //��ȡ������ֽ����ͻ���
  xferSize = pIrpStack->Parameters.Read.Length;
  userBuffer = pIrp->AssociatedIrp.SystemBuffer;	
  //�������ж�����
  RtlCopyMemory( userBuffer, L"Hello, world", xferSize );
  //��дIRP�е����״̬������IRP�����������²㷢��
  pIrp->IoStatus.Status = status;
  pIrp->IoStatus.Information = xferSize;
  IoCompleteRequest( pIrp, IO_NO_INCREMENT );
  return status;
}
