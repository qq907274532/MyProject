LEFT::
MouseGetPos, x, y
        ; ������λ�ã����ѻ�õ� X��Y ����ֱ�ֵ�� x��y
Mousemove, x-1, y
        ; �ƶ���꣬���� y ���겻�䣬�����ƶ�һ�����ء�
Return

UP::
MouseGetPos, x, y
Mousemove, x, y-1
Return

RIGHT::
MouseGetPos, x, y
Mousemove, x+1, y
Return

DOWN::
MouseGetPos, x, y
Mousemove, x, y+1
Return

