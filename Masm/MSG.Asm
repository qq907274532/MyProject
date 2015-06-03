.386
.model flat, stdcall
option casemap:none

include windows.inc
include user32.inc
include kernel32.inc

includelib user32.lib
includelib kernel32.lib

.data
    szCaption byte "Hello Word!", 0
    szTitle byte "MSG", 0

.code
start:
    invoke MessageBox, NULL, addr szCaption, addr szTitle, MB_OK
    invoke ExitProcess, NULL
end start