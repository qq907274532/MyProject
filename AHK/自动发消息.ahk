;隐藏托盘图标
#NoTrayIcon

;判断键盘或者鼠标超过50毫秒没动
Loop{
    If A_TimeIdle>200
    {
	send ^v
	;粘贴
	Send,{Enter}
	;这里我想回车发送怎么写
    }
}
return

;设置退出程序的快捷键为 ESC
Esc::
exitapp 