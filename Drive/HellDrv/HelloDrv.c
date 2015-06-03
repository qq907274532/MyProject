//__stdcall   WinAPI调用约定 #define WINAPI __stdcall
//__cdecl     VC默认适用调用约定
//__fastcall  参数应该存放到寄存器中 ecx edx

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