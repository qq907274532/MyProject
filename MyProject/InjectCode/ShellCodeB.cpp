#include <windows.h>

int main(void)
{
	__asm
	{
		XOR     EDX, EDX
		MOV     DL, 0x30
		MOV     EDX, DWORD PTR FS:[EDX]
		MOV     EDX, DWORD PTR DS:[EDX+0xC]
		MOV     EDX, DWORD PTR DS:[EDX+0x1C]
		lab1:
		MOV     EAX, DWORD PTR DS:[EDX+0x8]
		MOV     ESI, DWORD PTR DS:[EDX+0x20]
		MOV     EDX, DWORD PTR DS:[EDX]
		CMP     BYTE PTR DS:[ESI+0xC], 0x33
		JNZ		lab1;SHORT InjectCo.00422A3E
		MOV     EDI, EAX
		ADD     EDI, DWORD PTR DS:[EAX+0x3C]
		MOV     EDX, DWORD PTR DS:[EDI+0x78]
		ADD     EDX, EAX
		MOV     EDI, DWORD PTR DS:[EDX+0x20]
		ADD     EDI, EAX
		XOR     EBP, EBP
		lab2:
		MOV     ESI, DWORD PTR DS:[EDI+EBP*0x4]
		ADD     ESI, EAX
		INC		EBP
		CMP     DWORD PTR DS:[ESI], 0x61746146
		JNZ		lab2;SHORT InjectCo.00422A5D
		CMP     DWORD PTR DS:[ESI+8], 0x74697845
		JNZ		lab2;SHORT InjectCo.00422A5D
		MOV     EDI, DWORD PTR DS:[EDX+0x24]
		ADD     EDI, EAX
		MOV     BP, WORD PTR DS:[EDI+EBP*0x2]
		MOV     EDI, DWORD PTR DS:[EDX+0x1C]
		ADD     EDI, EAX
		MOV     EDI, DWORD PTR DS:[EDI+EBP*4-4]
		ADD     EDI, EAX
		PUSH    0x01657479
		PUSH    0x426E656B
		PUSH    0x6F724220
		MOV     ECX, ESP
		DEC     BYTE PTR DS:[ECX+0xB]
		XOR     EAX, EAX
		PUSH    ECX
		PUSH    EAX
		CALL    NEAR EDI
 	}
}
