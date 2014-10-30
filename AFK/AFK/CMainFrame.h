#pragma once

#include "stdafx.h"

class CMainFrame :
	public CWindowWnd,
	public INotifyUI,
	public CListUI
{
public:
	CMainFrame(void);
	~CMainFrame(void);

public:
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	void Init(void);
	LPCTSTR GetWindowClassName() const;
	UINT GetClassStyle() const;
	void OnFinalMessage(HWND /*hWnd*/);
	void Notify(TNotifyUI& msg);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	void OnTabA(void);
	void OnTabB(void);
	void OnTabC(void);
	void OnTabD(void);
	void OnTabE(void);
	void OnTabF(void);

public:
	CButtonUI*		m_pBtnClearAll;			//全平
	CButtonUI*		m_pBtnCancelAll;		//全撤

	CLabelUI*		m_pAskQty;				//卖出量

	CPaintManagerUI m_pm;
	CButtonUI*		m_pBtnClose;
};
