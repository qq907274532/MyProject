CoordMode Mouse, Screen
	;������������ϵͳ������ĻΪ�������ꡣ

^LButton::
MouseGetPos x0, y0, id0                    ; ��꿪ʼ�϶���λ��
Loop
{
Sleep 20                            ; ��ͣ 20 ����
GetKeyState, keystate, LButton, p         ; �������İ���״̬
IfEqual, keystate, U, {
MouseGetPos, x1, y1                 ; �������ɿ�ʱ���λ��
WinActivate Appinn.com         ; ���������� Appinn.com �ĳ���
        ; �������Ѿ��ڵ�һ���������
clipboard = %x0%, %y0%
clipwait
send ^v
send {tab}
        ; ����������������Ĵ����ҾͲ��г��ˣ������в��ꡣ
break        ; ���Ҫ��������ѭ��Ŷ��
}
}
return

