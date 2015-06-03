;隐藏托盘图标
#NoTrayIcon

!w::
send {!Tab::}
return

;判断键盘或者鼠标超过10分钟没动
Loop
{
    If A_TimeIdle>600000
    {
	Send,{Click}
    }
}

;设置退出程序的快捷键为 ESC
Esc::
exitapp 
