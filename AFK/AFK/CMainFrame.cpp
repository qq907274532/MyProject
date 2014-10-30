#include "StdAfx.h"
#include "CMainFrame.h"
#include <Strsafe.h>

CMainFrame::CMainFrame(void)
{
}

CMainFrame::~CMainFrame(void)
{
}

void CMainFrame::Init(void)
{
	m_pBtnClearAll = static_cast<CButtonUI *>(m_pm.FindControl(_T("BtnClearAll")));
	if (m_pBtnClearAll == NULL)
		return;

	m_pAskQty = static_cast<CLabelUI *>(m_pm.FindControl(_T("AskQty")));
	if (m_pAskQty == NULL)
		return;

}


/************************************************************************/
LRESULT CMainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// 把自己的窗口句柄与窗口绘制管理器挂接在一起
	m_pm.Init(m_hWnd);	
	CDialogBuilder builder;

	// 调用XML文件创建控件
	CControlUI* pRoot = builder.Create(_T("MainFrame.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pRoot && "Failure to parse XML");
	m_pm.AttachDialog(pRoot);	// 把上面的控件绘制到本窗口上，之前有把m_hWnd传给m_pm
	m_pm.AddNotifier(this);		// 把自己加入到CPaintManagerUI的m_aNotifiers数组中，用于处理Notify函数
	//Init();
	return 0;
}

/************************************************************************/
/*  功能:通过鼠标点击客户区拖动窗口位置										*/
/*                                                                      */
/************************************************************************/
LRESULT CMainFrame::OnNcHitTest( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
	::ScreenToClient(*this, &pt);

	RECT rcClient;
	::GetClientRect(*this, &rcClient);

	if( !::IsZoomed(*this) )
	{
		RECT rcSizeBox = m_pm.GetSizeBox();
		if( pt.y < rcClient.top + rcSizeBox.top )
		{
			if( pt.x < rcClient.left + rcSizeBox.left ) return HTTOPLEFT;
			if( pt.x > rcClient.right - rcSizeBox.right ) return HTTOPRIGHT;
			return HTTOP;
		}
		else if( pt.y > rcClient.bottom - rcSizeBox.bottom )
		{
			if( pt.x < rcClient.left + rcSizeBox.left ) return HTBOTTOMLEFT;
			if( pt.x > rcClient.right - rcSizeBox.right ) return HTBOTTOMRIGHT;
			return HTBOTTOM;
		}

		if( pt.x < rcClient.left + rcSizeBox.left ) return HTLEFT;
		if( pt.x > rcClient.right - rcSizeBox.right ) return HTRIGHT;
	}

	RECT rcCaption = m_pm.GetCaptionRect();
	if( pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right \
		&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom ) {
			CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
			if( pControl && _tcsicmp(pControl->GetClass(), _T("ButtonUI")) != 0 && 
				_tcsicmp(pControl->GetClass(), _T("OptionUI")) != 0 &&
				_tcsicmp(pControl->GetClass(), _T("TextUI")) != 0 &&
				_tcsicmp(pControl->GetClass(), _T("EditUI")) != 0 &&
				_tcsicmp(pControl->GetClass(), _T("ComboBoxUI")) != 0 )
				return HTCAPTION;
	}

	return HTCLIENT;
}

/************************************************************************/
/* 功能:处理鼠标点击和移动消息												*/
/*                                                                      */
/************************************************************************/
LRESULT CMainFrame::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	SIZE szRoundCorner = m_pm.GetRoundCorner();	// GetRoundCorner用来获取xml中的Window标签中roundcorner属性值，该值指示圆角的长宽
	if( !::IsIconic(*this) && (szRoundCorner.cx != 0 || szRoundCorner.cy != 0) ) 
	{
		CDuiRect rcWnd;
		::GetWindowRect(*this, &rcWnd);
		rcWnd.Offset(-rcWnd.left, -rcWnd.top);	// rcWnd.right就成为了窗口的宽度了
		rcWnd.right++; rcWnd.bottom++;
		HRGN hRgn = ::CreateRoundRectRgn(rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, szRoundCorner.cx, szRoundCorner.cy);
		::SetWindowRgn(*this, hRgn, TRUE);		// 窗口圆角化处理
		::DeleteObject(hRgn);
	}
	bHandled = FALSE;
	return 0;
}


LRESULT CMainFrame::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if( ::IsIconic(*this) ) bHandled = FALSE;
	return (wParam == 0) ? TRUE : FALSE;
}


LRESULT CMainFrame::OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	MONITORINFO oMonitor = {};
	oMonitor.cbSize = sizeof(oMonitor);
	::GetMonitorInfo(::MonitorFromWindow(*this, MONITOR_DEFAULTTOPRIMARY), &oMonitor);
	CDuiRect rcWork = oMonitor.rcWork;
	rcWork.Offset(-rcWork.left, -rcWork.top);

	LPMINMAXINFO lpMMI = (LPMINMAXINFO) lParam;
	lpMMI->ptMaxPosition.x	= rcWork.left;
	lpMMI->ptMaxPosition.y	= rcWork.top;
	lpMMI->ptMaxSize.x		= rcWork.right;
	lpMMI->ptMaxSize.y		= rcWork.bottom;

	bHandled = FALSE;
	return 0;
}


LRESULT CMainFrame::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (wParam == SC_CLOSE)
	{
		bHandled = TRUE;
		SendMessage(WM_CLOSE);
		return 0;
	}
#if defined(WIN32) && !defined(UNDER_CE)
	BOOL bZoomed = ::IsZoomed(*this);
	LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	if( ::IsZoomed(*this) != bZoomed )
	{
	}
#else
	LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
#endif
	return lRes;
}

LRESULT CMainFrame::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0;
}








LPCTSTR CMainFrame::GetWindowClassName() const 
{
	return _T("UIMainFrame");
}

UINT CMainFrame::GetClassStyle() const
{
	return UI_CLASSSTYLE_FRAME | CS_DBLCLKS;
}

void CMainFrame::OnFinalMessage(HWND /*hWnd*/)
{
	delete this;
}

void CMainFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == TEXT("click"))	  
	{
		if (msg.pSender->GetName() == _T("SkinBtn"))
			PostQuitMessage(0);	

		if (msg.pSender->GetName() == _T("BtnClearAll"))
		{
			CLabelUI* m_pAskQty = static_cast<CLabelUI*>(m_pm.FindControl(_T("AskQty")) );

			TCHAR szData[MAX_PATH] = {0};

			StringCbCopy(szData, sizeof(szData), m_pAskQty->GetText().GetData());

			int nNum = _tstoi( szData );
			nNum++;

			_stprintf_s(szData, sizeof(szData), _T("%d"), nNum);
			m_pAskQty->SetText(szData);

		}

	}
	else if(msg.sType==_T("selectchanged"))
	{
		CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_pm.FindControl(_T("switch")));

		if(msg.pSender->GetName() ==_T("行情列表"))
			OnTabA();

		else if(msg.pSender->GetName() ==_T("帐户/持仓"))
			OnTabB();

		else if(msg.pSender->GetName() ==_T("委托"))
			OnTabC();

		else if(msg.pSender->GetName() ==_T("已成"))
			OnTabD();

		else if(msg.pSender->GetName() ==_T("已撒"))
			OnTabE();

		else if(msg.pSender->GetName() ==_T("帮助"))
			OnTabF();
	}
	else if( msg.sType == _T("itemselect") ) 
	{
		if( msg.pSender->GetName() == _T("ComboAdd") ) 
		{
			CEditUI* pAccountEdit = static_cast<CEditUI*>(m_pm.FindControl(_T("EditAdd")));
			if( pAccountEdit ) pAccountEdit->SetText(msg.pSender->GetText());
		}
	}
}

LRESULT CMainFrame::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;
	switch (uMsg)
	{
	case WM_CREATE:
		lRes = OnCreate(uMsg ,wParam, lParam, bHandled);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		bHandled = FALSE;
		break;

	case WM_NCHITTEST:
		lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		if(wParam == VK_F1)
			MessageBox(NULL, _T("帮助文档"), _T("提示"), MB_OK);

		break;

	case WM_SIZE:
		lRes = OnSize(uMsg, wParam, lParam, bHandled);
		break;

	case WM_NCACTIVATE:
		lRes = OnNcActivate(uMsg, wParam, lParam, bHandled);
		break;

	case WM_GETMINMAXINFO:
		lRes = true;
		OnGetMinMaxInfo(uMsg, wParam, lParam, bHandled);		
		break;

	case WM_SYSCOMMAND:
		lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); 
		break;

	case WM_NCCALCSIZE:		// 取消窗口非客户区部分消息响应
		lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); 
		break;

	case WM_NCPAINT:		// 取消窗口非客户区部分绘制
		break;

	case WM_TIMER:
		//lRes = OnTimer(uMsg, wParam, lParam, bHandled);
		bHandled = FALSE;
		break;

	default:
		bHandled = FALSE; 
		break;
	}

	if (bHandled) 
		return lRes;

	if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes) != 0)
		return lRes;

	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}


void CMainFrame::OnTabA(void)
{
	CDialogBuilder BuilderA;
	CControlUI* pTabA = BuilderA.Create(_T("TabA.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pTabA && "FailuCMyFirstDuilib::Notifyre to parse XML");
	m_pm.AttachDialog(pTabA);
}


void CMainFrame::OnTabB(void)
{
	CDialogBuilder BuilderB;
	CControlUI* pTabB = BuilderB.Create(_T("TabB.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pTabB && "Failure to parse XML");
	m_pm.AttachDialog(pTabB);
}

void CMainFrame::OnTabC(void)
{
	CDialogBuilder BuilderC;
	CControlUI* pTabC = BuilderC.Create(_T("TabC.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pTabC && "Failure to parse XML");
	m_pm.AttachDialog(pTabC);
}

void CMainFrame::OnTabD(void)
{
	CDialogBuilder BuilderD;
	CControlUI* pTabD = BuilderD.Create(_T("TabD.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pTabD && "Failure to parse XML");
	m_pm.AttachDialog(pTabD);
}

void CMainFrame::OnTabE(void)
{
	CDialogBuilder BuilderE;
	CControlUI* pTabE = BuilderE.Create(_T("TabE.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pTabE && "Failure to parse XML");
	m_pm.AttachDialog(pTabE);
}

void CMainFrame::OnTabF(void)
{
	CDialogBuilder BuilderF;
	CControlUI* pTabF = BuilderF.Create(_T("TabF.xml"), (UINT)0, NULL, &m_pm);
	ASSERT(pTabF && "Failure to parse XML");
	m_pm.AttachDialog(pTabF);
}