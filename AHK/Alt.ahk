;��������ͼ��
#NoTrayIcon

!w::
send {!Tab::}
return

;�жϼ��̻�����곬��10����û��
Loop
{
    If A_TimeIdle>600000
    {
	Send,{Click}
    }
}

;�����˳�����Ŀ�ݼ�Ϊ ESC
Esc::
exitapp 
