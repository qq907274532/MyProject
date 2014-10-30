// AFK.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "AFK.h"
#include "CMainFrame.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{	
	// 将程序实例与皮肤绘制管理器挂钩
	CPaintManagerUI::SetInstance(hInstance);

	// 设置皮肤库的资源路径，资源有图片、xml文件等
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("../Skin"));
	//CPaintManagerUI::SetResourceZip(CPaintManagerUI::GetInstancePath() + _T("Skin.zip"));

	// new一个继承自CWindowWnd类
	CMainFrame* lpFrame = new CMainFrame();
	if( lpFrame == NULL ) 
		return 0;

	// 调用类的Create函数创建窗口，在HandleMessage函数中处理WM_CREATE消息
	lpFrame->Create(NULL, _T("KingBon"), UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE | WS_EX_APPWINDOW);

	// 创建显示窗口
	lpFrame->CenterWindow();
	lpFrame->ShowWindow();

	// 设置任务栏上显示的图标
	//SetIcon(IDI_SMALL);

	// 然后调用CPaintManagerUI::MessageLoop()，进入消息循环
	CPaintManagerUI::MessageLoop();

	//退出程序并释放COM库
	::CoUninitialize();


	return 0;
}
