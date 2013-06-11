// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "res.h"

class CMainDlg 
	: public CBkDialogImpl<CMainDlg>
	,public CWHRoundRectFrameHelper<CMainDlg>
{
public:
	CMainDlg();
	~CMainDlg();

public:

	BK_NOTIFY_MAP(IDC_RICHVIEW_WIN)
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_CLOSE, OnClose)
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_MAX, OnMaxWindow)
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_MIN, OnMinWindow)
	BK_NOTIFY_MAP_END()

	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_BK_NOTIFY(IDC_RICHVIEW_WIN)
		CHAIN_MSG_MAP(CBkDialogImpl<CMainDlg>)
		CHAIN_MSG_MAP(CWHRoundRectFrameHelper<CMainDlg>)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

	LRESULT OnClose();
	LRESULT OnMaxWindow();
	LRESULT OnMinWindow();

};
