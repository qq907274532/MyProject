// AFK.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "AFK.h"
#include "CMainFrame.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{	
	// ������ʵ����Ƥ�����ƹ������ҹ�
	CPaintManagerUI::SetInstance(hInstance);

	// ����Ƥ�������Դ·������Դ��ͼƬ��xml�ļ���
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("../Skin"));
	//CPaintManagerUI::SetResourceZip(CPaintManagerUI::GetInstancePath() + _T("Skin.zip"));

	// newһ���̳���CWindowWnd��
	CMainFrame* lpFrame = new CMainFrame();
	if( lpFrame == NULL ) 
		return 0;

	// �������Create�����������ڣ���HandleMessage�����д���WM_CREATE��Ϣ
	lpFrame->Create(NULL, _T("KingBon"), UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE | WS_EX_APPWINDOW);

	// ������ʾ����
	lpFrame->CenterWindow();
	lpFrame->ShowWindow();

	// ��������������ʾ��ͼ��
	//SetIcon(IDI_SMALL);

	// Ȼ�����CPaintManagerUI::MessageLoop()��������Ϣѭ��
	CPaintManagerUI::MessageLoop();

	//�˳������ͷ�COM��
	::CoUninitialize();


	return 0;
}
