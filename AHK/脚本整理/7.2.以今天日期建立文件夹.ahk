#+f::
        ; ��һ�����ӿ�ݼ�
Click right
Send, wf
Sleep, 125
        ; ����ͣʱ���С
clipboard = %A_YYYY%-%A_MM%-%A_DD%
        ; ����������䣬�ѵ�ǰ��ϵͳ���ڷ��͵�������
Send, ^v{Enter}
        ; ���� Ctrl + v �ͻس�
return