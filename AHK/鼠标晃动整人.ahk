;��������ͼ��
#NoTrayIcon

;�жϼ��̻�����곬��50����û��
Loop{
    If A_TimeIdle>50
    {
	;�������������ڣ�-15��15���������
        Random, x, -15, 15
        Random, y, -15, 15

	;����������ƶ����
        MouseMove, %x%, %y%, 0, r
    }
}
return

;�����˳�����Ŀ�ݼ�Ϊ ESC
Esc::
exitapp 