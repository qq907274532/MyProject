; �򿪽ű�,������Ϸ��,��С�����ϵ� * ,�ͽ�����,����һ�ξ�����.��¼��game_list.txt CODELoop, Read,game_list.txt
GroupAdd,game,%A_LoopReadLine%
NumpadMult::
WinGetClass, class, A
FileAppend,ahk_class %class%`n,game_list.txt
RELOAD
return
#IfWinActive,ahk_group game
LWin::return
; ���ߣ�Helfee
; http://hi.baidu.com/helfee/blog/item/a8c5b78f3ade1dedf01f36cd.html