#c::
MouseGetPos, mouseX, mouseY
        ; �������������꣬������ X ���긳ֵ������ mouseX ��ͬ�� mouseY
PixelGetColor, color, %mouseX%, %mouseY%, RGB
        ; ���� PixelGetColor ��������������������� RGB ֵ������ֵ�� color
StringRight color,color,6
        ; ��ȡ color���ڶ��� color�� �ұߵ� 6 ���ַ�����Ϊ��õ�ֵ�������ģ�#RRGGBB��һ������ֻ��Ҫ RRGGBB ���֡��ѽ�ȡ����ֵ�ٸ��� color����һ�� color����
clipboard = %color%
        ; �� color ��ֵ���͵�������
tooltip, ���������ɫֵ�ѷ��͵������塣`nС����� - appinn.com`n��ϵ�н̳����ߣ�sfufoet
        ; tooltip ���������ʾ������������Ҫ��ʾ����䡣�м�� `n ��ʾ�س�
sleep 2000
        ; ʱ����ͣ ����
tooltip,
        ; �ر������ʾ
return

