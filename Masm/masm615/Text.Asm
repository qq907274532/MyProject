assume cs:MyCode

MyCode segment

g_strHello db 'HelloWord!$'

ENTRY:
	mov dx, offset g_strHello
	;lea dx, g_strHello
	mov ah, 11 
	int 21h
	mov ax, 4c00h
	int 21h

MyCode ends

end ENTRY
