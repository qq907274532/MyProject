#Persistent

count = 1

SetTimer, CloseSkyNet, 50
return

CloseSkyNet:
IfWinExist, �빺��������ǽ���˰�
        ; orz, ��Ȼ���˸������֡�ÿ�����ڶ���һ�����֣��� AHK ������ window spy �Ϳ������ɻ�ô�����������
{
sleep 1000
WinClose, �빺��������ǽ���˰�
ExitApp
        ; �������˳���������
}
else
{
sleep 1000
count := count + 1
if count = 60
ExitApp
}
return

