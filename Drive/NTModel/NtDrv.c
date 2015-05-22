#include <ntddk.h>

#define DEVICE_NAME L"\\devices\\ntmodeldrv"
#define LINK_NAME L"\\dosdevices\\ntmodeldrv"

#define IOCTL_BASE 0X8000

#define MY_CTRL_CODE(i) CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_BASE+i, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_HELLO MY_CTRL_CODE(1)
#define IOCTL_BYE MY_CTRL_CODE(2)
#define IOCTL_PRINT MY_CTRL_CODE(3)

VOID DriverUnload(PDRIVER_OBJECT pDriveObjcet);

NTSTATUS DispatchCreate(PDEVICE_OBJECT pDeviceObject, PIRP pIrp); // 创建
NTSTATUS DispatchRead(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);   // 读取
NTSTATUS DispatchWrite(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);  // 写入
NTSTATUS DispatchClose(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);  // 关闭
NTSTATUS DispatchClean(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);  // 清理
NTSTATUS DispatchCommon(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)  // 
NTSTATUS DispatchIoctrl(PDEVICE_OBJECT pDeviceObject, PIRP pIrp); // IO控制

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegPath)
{
  UNICODE_STRING uDevicesName = {0};
  UNICODE_STRING uLinkName = {0};

  NTSTATUS ntStaus = STATUS_SUCCESS;
  PDEVICE_OBJECT pDeviceObject = NULL;

  ULONG i = 0;
	DbgPrint("Driver Load Begin\n");

  RtlInitUnicodeString(&uDevicesName, DEVICE_NAME);
  RtlInitUnicodeString(&uLinkName, LINK_NAME);

  ntStaus = IoCreateDevice(pDriverObject, 0, &uDevicesName, FILE_DEVICE_UNKNOWN, 0, TRUE, &pDeviceObject);
  if(!NT_SUCCESS(ntStaus))
    return ntStaus;
  
  pDeviceObject->Flags |= DO_BUFFERED_IO;
  ntStaus = IoCreateSymbolicLink(&uLinkName, &uDevicesName);
  if(!NT_SUCCESS(ntStaus))
    return ntStaus;

  for(i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
  {
    pDriverObject->MajorFunction[i] = DispatchCommon;
  }
  pDriverObject->MajorFunction[IRP_MJ_CREATE] = DispatchCreate;
  pDriverObject->MajorFunction[IRP_MJ_READ] = DispatchRead;
  pDriverObject->MajorFunction[IRP_MJ_WRITE] = DispatchWrite;
  pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DispatchIoctrl;
  pDriverObject->MajorFunction[IRP_MJ_CLOSE] = DispatchClose;
  pDriverObject->MajorFunction[IRP_MJ_CLEANUP] = DispatchClean;
  
  pDriverObject->DriverUnload = DriverUnload;
  DbgPrint("Driver Load Success\n");
	return STATUS_SUCCESS;
}

VOID DriverUnload(PDRIVER_OBJECT pDriveObjcet)
{
  UNICODE_STRING uLinkName = {0};
  RtlInitUnicodeString(&uLinkName, LINK_NAME);
  IoDeleteSymbolicLink(&uLinkName);
  DbgPrint("Driver Unloaded!\r\n");
}

NTSTATUS DispatchCreate(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
	pIrp->IoStatus.Status = STATUS_SUCCESS;
  PIRP->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);

  DbgPrint("Dispatch Create Called\n");

	return STATUS_SUCCESS;
}

NTSTATUS DispatchRead(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{  
  DbgPrint("Dispatch Read Called\n");

  ULONG ulSize = 0;
  ULONG ulMinSize = 0;
	PVOID pReadBuffer = NULL;
	ULONG ulReadLength = 0;

	PIO_STACK_LOCATION pStack = NULL;
	pReadBuffer = pIrp->AssociatedIrp.SystemBuffer;

	pStack = IoGetCurrentIrpStackLocation(pIrp);
	ulReadLength = pStack->Parameters.Read.Length;

	ulSize = wcslen(L"Hello world!")*sizeof(WCHAR);
	ulMinSize = ulSize>ulReadLength?ulReadLength:ulSize;

	RtlCopyMemory(pReadBuffer, L"Hello world!", ulMinSize);

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = ulMinSize;

	IoCompleteRequest(pIrp, IO_NO_INCREMENT);

	return STATUS_SUCCESS;
}

NTSTATUS DispatchWrite(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
  DbgPrint("Dispatch Write Called\n");

	PVOID pWriteBuffer = NULL;
	ULONG ulWriteLength = 0;
  
	PVOID pStoreBuffer = NULL;
	PIO_STACK_LOCATION pStack = NULL;
	pWriteBuffer = pIrp->AssociatedIrp.SystemBuffer;
	pStack = IoGetCurrentIrpStackLocation(pIrp);
	ulWriteLength = pStack->Parameters.Write.Length;

	pStoreBuffer = ExAllocatePoolWithTag(PagedPool, ulWriteLength+2, 'TN');
	if (pStoreBuffer == NULL)
	{
		pIrp->IoStatus.Status = STATUS_UNSUCCESSFUL;
		pIrp->IoStatus.Information = 0;

		IoCompleteRequest(pIrp, IO_NO_INCREMENT);
		return STATUS_UNSUCCESSFUL;
	}

	RtlZeroMemory(pStoreBuffer, ulWriteLength+2);
	RtlCopyMemory(pStoreBuffer, pWriteBuffer, ulWriteLength);

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = ulWriteLength;
	
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

NTSTATUS DispatchClose(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
  DbgPrint("Dispatch Close Called\n");

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}
NTSTATUS DispatchClean(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
  DbgPrint("Dispatch Clean Called\n");

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

NTSTATUS DispatchCommon(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
  DbgPrint("Dispatch Common Called\n");

  pIrp->IoStatus.Status = STATUS_SUCCESS;
  IoCompleteRequest(pIrp, IO_NO_INCREMENT);
  return STATUS_SUCCESS;
}

NTSTATUS DispatchIoctrl(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{  
  DbgPrint("Dispatch Ioctrl Called\n");

  PVOID pInputBuffer = NULL;
  PVOID pOutputBuffer = NULL;
  
  ULONG ulInputLength = 0;
  ULONG ulOutputLength = 0;
  ULONG ulIoCtrlCode = 0;

  PIO_STACK_LOCATION pStack = NULL;
  pInputBuffer = pOutputBuffer = pIrp->AssociatedIrp.SystemBuffer;
  
  pStack = IoGetCurrentIrpStackLocation(pIrp);
  ulInputLength = pStack->Parameters.DeviceIoControl.InputBufferLength;
  ulOutputLength = pStack->Parameters.DeviceIoControl.OutputBufferLength;
  ulIoCtrlCode = pStack->Parameters.DeviceIoControl.IoControlCode;
  
  switch(ulIoCtrlCode)
  {
  case IOCTL_HELLO:
    DbgPrint("Hello world\n");
    break;

  case IOCTL_BYE:
    DbgPrint("Goodbye world\n");
    break;

  case IOCTL_PRINT:
    DbgPrint("%s",pInputBuffer);
    break;

  default:
    DbgPrint("Unkown code!\n");
    break;
  }
  
  pIrp->IoStatus.Status = STATUS_SUCCESS;
  IoCompleteRequest(pIrp, IO_NO_INCREMENT);

  return STATUS_SUCCESS;
}