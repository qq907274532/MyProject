~RButton::
Hotkey, MButton, Paste
Keywait, LButton, d, t0.2
        ; ���� d ��down����ʾ�������ڰ���״̬��t0.2 �ǵȴ� 0.2 �롣
if errorlevel = 0
        ; ������صĴ����루errorlevel���ܶ�� AHK ����᷵�ش����룬��������� AHK �Դ��ġ����� 0 ��Ҳ����˵����� Keywait ����ִ�гɹ�������� 1 �Ļ���˵�� Keywait ִ��ʧ�ܡ�ʧ��˵�����ǰ������Ҽ�֮��û���� 0.2 ���ڰ��������
{
KeyWait, LButton, U
        ; ���� norchy ���޸� http://ahk.5d6d.com/viewthread.php?tid=211���� word��LButton + RButton �� Ctrl + C ��û��Ч���ģ���ʱ������ܻ�ʧ�ܡ�����һ�� KeyWait, LButton, U �ɽ�������⡣
send ^c
Hotkey, MButton, on
}
return

Paste:
send ^v
Hotkey, MButton, off
return

^MButton::
send ^v
return

