; ��ʾ / ���� �ļ���չ����
; ���ߣ� iLEMONed
; http://cn.ilemoned.com/

^!+e::
If value = 0
value = 1
Else
value = 0
RegWrite, REG_DWORD, HKEY_CURRENT_USER, Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\, HideFileExt, %Value%
send { AppsKey } e
        ; ��������ϵ� AppsKey �������Ҽ���ѡ��ˢ��(e)�� ��
return
