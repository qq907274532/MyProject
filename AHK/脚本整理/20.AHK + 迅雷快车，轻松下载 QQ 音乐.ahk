#Persistent
settimer,copy,1
return
        ; С��ʾ������㿴������Щ�������ͷ���� AHK ��͵�ϵ�����¡�

copy:
FileCopy,D:\QQ\QQMusicData\Temp\UserList*.tmp, E:\����\temp, 1
        ; ��ע���޸� QQ ��·��������� E:\����\temp ���ļ����Ƶ�����ȥ��1��������ͬ���ļ�����֮���� 0��
IfExist E:\����\temp\UserList.tmp
        ; E:\����\temp\UserList.tmp ����ļ��������� UserList7.tmp ֮��ġ�
{
settimer,copy, off
        ; �رռ�ʱ��
Loop
{
FileReadLine, line, E:\����\temp\UserList.tmp, %A_Index%
        ; ��ȡ�ļ���ÿһ�У��ŵ����� line ����
if ErrorLevel
break
        ; ����Ҳ����ļ��Ļ�������ѭ����
RegExMatch(line, ��http://(.*).wma��,URL)
        ; ����������ʽ��ȡ line �еĵ�ַ����ȡ��ĵ�ַ���� URL �С�
if (StrLen(URL)<>0)
URLs=%URLs%%URL%`n
        ; ��� URL �ĳ��Ȳ����� 0 ��˵���ҵ���ַ�ˣ�����һ���س���`n������ ÿһ�� URL �ϲ��� URLs ����
}
FileAppend , %URLs%, E:\����\temp\MusicURL.lst
        ; �� URLs ��ֵд�� MusicURL.lst ����
}
return

