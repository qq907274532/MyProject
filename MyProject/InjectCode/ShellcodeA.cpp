#include <windows.h>

void* WINAPI Func(LPVOID* p)
{
// 	HMODULE hModule = ::GetModuleHandle("user32.dll");	
// 	LPTHREAD_START_ROUTINE lpStartAddress = (LPTHREAD_START_ROUTINE)::GetProcAddress(hModule, "MessageBoxA");

// 	__asm
// 	{
// 		int 3
// 	}
	char szHello[16];
	szHello[0]='H';
	szHello[1]='e';
	szHello[2]='l';
	szHello[3]='l';
	szHello[4]='o';
	szHello[5]=' ';
	szHello[6]='W';
	szHello[7]='o';
	szHello[8]='r';
	szHello[9]='d';
	szHello[10]='!';
	szHello[11]='\0';

	int* dwTemp = (int*)0x7e4507ea;

	__asm
	{
		push ecx
		push 0
		push 0
		lea ecx, szHello
		push ecx
		push 0
		call dwTemp
		pop ecx
	}

	return NULL;
}

int main(void)
{
	Func(NULL);
	return 0;
}
