.386
.Model Flat, StdCall
Option Casemap :None

include windows.inc
include user32.inc
include Kernel32.inc

includelib user32.lib
includelib Kernel32.lib


.const
  g_szHello db 'Hello world!', 0
  g_szTitle db "Hello", 0


.code
WndProc proc hWnd:HWND, nMsg:UINT, wParam:WPARAM, lParam:LPARAM

  .if nMsg == WM_DESTROY 
    invoke PostQuitMessage, 0
  .elseif nMsg == WM_LBUTTONDOWN
    invoke MessageBox, hWnd, offset g_szHello, offset g_szTitle, MB_OK
  .else
    invoke DefWindowProc, hWnd, nMsg, wParam, lParam
  ret
  .endif
  ret

WndProc endp


InitInstance  proc hInst:HINSTANCE, nCmdShow:UINT
  
  local @hWnd:HWND
  invoke CreateWindowEx, NULL, offset g_szHello, offset g_szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInst, NULL
  mov @hWnd, eax
  
  .if !@hWnd
    xor eax, eax
    ret
  .endif

  invoke ShowWindow, @hWnd, nCmdShow
  mov eax, TRUE
  ret

InitInstance endp


MyRegisterClass proc hInst:HINSTANCE 

  local @wcex:WNDCLASSEX
  
  mov @wcex.cbSize, sizeof WNDCLASSEX 
  mov @wcex.style, CS_HREDRAW or CS_VREDRAW;
  mov @wcex.lpfnWndProc, WndProc
  mov @wcex.cbClsExtra, 0;
  mov @wcex.cbWndExtra, 0;
  mov eax, hInst
  mov @wcex.hInstance, eax
  mov @wcex.hIcon, NULL
  mov @wcex.hCursor, NULL
  mov @wcex.hbrBackground,  COLOR_WINDOW+1
  mov @wcex.lpszMenuName, NULL
  mov @wcex.lpszClassName, offset g_szHello
  mov @wcex.hIconSm, NULL
  
  invoke RegisterClassEx, addr @wcex
  ret

MyRegisterClass endp


WinMain proc hInst:HINSTANCE

  local @msg:MSG 
  
  invoke MyRegisterClass, hInst
  
  .if eax == NULL 
    xor eax, eax
    ret
  .endif
  
  invoke InitInstance, hInst, SW_SHOW

  .if eax == NULL 
    xor eax, eax
    ret
  .endif
  
  invoke GetMessage, addr @msg, NULL, 0, 0
  
  .while eax
    invoke DispatchMessage, addr @msg
    invoke GetMessage, addr @msg, NULL, 0, 0
  .endw
  
  mov eax, @msg.wParam
  ret
  
WinMain endp


START proc

  invoke GetModuleHandle, NULL 
  invoke WinMain, eax
  invoke ExitProcess, eax
  invoke GetLocalTime, eax

START endp

end START