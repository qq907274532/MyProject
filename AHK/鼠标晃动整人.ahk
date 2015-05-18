;隐藏托盘图标
#NoTrayIcon

;判断键盘或者鼠标超过50毫秒没动
Loop{
    If A_TimeIdle>50
    {
	;生成两个区间在（-15，15）的随机数
        Random, x, -15, 15
        Random, y, -15, 15

	;以相对坐标移动鼠标
        MouseMove, %x%, %y%, 0, r
    }
}
return

;设置退出程序的快捷键为 ESC
Esc::
exitapp 