@echo off

rem ����� Masm32 ������İ�װĿ¼�޸������ Masm32Dir ����������
rem ml /c /coff < *.asm file name > ���� [ is return *.obj file ]
rem rc < *.rc file name > ���� [ is return *.res file ]
rem Link /subsystem:windows < *.ojb and *.res file name > ���� [ is return *.exe file ]

set Masm32Dir=D:\Teach\Tools\masm615
set include=%Masm32Dir%\Include;%include%
set lib=%Masm32Dir%\lib;%lib%
set path=%Masm32Dir%\Bin;%Masm32Dir%;%PATH%
set Masm32Dir=
echo on