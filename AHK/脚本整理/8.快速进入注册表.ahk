#j::
send ^c
        ; ����ѡ�е�����
clipwait
        ; �ȴ����ƶ��������
StringReplace, clipboard, clipboard, ��,��\, All
        ; ����һЩ���ºܲ��Ͻ������ܡ���\�����֡��滻�������������еġ��ܡ��������ٰ��滻������ַ��͵������塣
RegWrite, REG_SZ, HKEY_CURRENT_USER, Software\Microsoft\Windows\CurrentVersion\Applets\Regedit, LastKey, �ҵĵ���\%clipboard%
        ; �Ѹ���ע�������򿪵ļ�ֵ�޸�Ϊ�������е�·�������� REG_SZ �������Ͻ�ͼƬ�� LastKey �����͡�HKEY_CURRENT_USER ����Ŀ��ע����֧�����ŵĲ�����Ŀ��·����Ȼ����Ҫ�޸ĵļ��������Ҫ�޸ĵ�ֵ��
run regedit
        ; ����ע���
return