; �ر���ʾ�������ݴ���A�̵�ϵͳ��
DriveGet, DriverList, list,REMOVABLE
	; ����ƶ��豸���̷���������������ƶ��豸�����ǵ��̷��ֱ��� H: �� I: �Ļ�����ô���� DriverList ��ֵ�ǣ�HI��
StringSplit, DriverListArray, DriverList
	; �� DriverList ��ֵ�����ַ����ֽ⣬���治���κ�Ҫ�ָ�ķ��ŵĻ�����ʾ����һ����ĸһ����ĸ���ֽ⣬�������ǾͿ��Եõ�ÿһ���̷��ˡ�
loop %DriverListArray0%
{
RegRead, UnlockerPath, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unlocker, DisplayIcon
	; ��ȡע������ Unlocker.exe ����·����
target = % DriverListArray%A_Index% . ":"
	; �Ӻ��濪ʼ���ͣ�
	; . ":"������һ���ַ���������
	; %A_Index%����ʾ��ǰѭ�����ڼ���
	; % DriverListArray%A_Index%����ʾ�� N ���ƶ�����
runwait %UnlockerPath% %target% /s
run %A_ScriptDir%\unplug.exe %target%
	; %A_ScriptDir%������ǰ�ű����ڵ��ļ���
}
TrayTip,,�����ƶ��豸ȫ��������,3000
	; ����������ʾ��3 ���������ʧ��TrayTip �������﷨�ǣ�TrayTip [, ����, ����, ʱ��, Options]

sleep 3000