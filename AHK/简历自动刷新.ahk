;隐藏托盘图标
#NoTrayIcon

;判断键盘或者鼠标超过1分钟没动
Loop
{
    If A_TimeIdle>2000
    {
		;Send, {Alt down}{Tab}
		;Send, {Alt up}
		;Sleep, 100    
		Send, {Click}
    }
}

^!p::Pause

return

;设置退出程序的快捷键为 ESC
Esc::
exitapp 
