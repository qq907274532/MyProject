//__stdcall   WinAPI����Լ�� #define WINAPI __stdcall
//__cdecl     VCĬ�����õ���Լ��
//__fastcall  ����Ӧ�ô�ŵ��Ĵ����� ecx edx

#include <ntddk.h>

VOID DriverUnload(PDRIVER_OBJECT pDriverObject);

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegPath)
{
  __asm{int 3}

  DbgPrint("Hello Word!\r\n");
  pDriverObject->DriverUnload = DriverUnload;

  return STATUS_SUCCESS;
}

VOID DriverUnload(PDRIVER_OBJECT pDriverObject)
{
  DbgPrint("Goodbye Word\r\n");
}