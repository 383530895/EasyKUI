#include "stdafx.h"
#include "MainDlg.h"

CMainDlg::CMainDlg():CBkDialogImpl<CMainDlg>(IDR_BK_MAIN_DIALOG) // ��������ؽ�����
{
	// ���� Load xx ������Ǳ���ģ�����Ƥ����������ʾ
	//BkFontPool::SetDefaultFont(BkString::Get(IDS_APP_FONT), -12); // ��������
	//BkString::Load(IDR_BK_STRING_DEF); // �����ַ���
	//BkSkin::LoadSkins(IDR_BK_SKIN_DEF); // ����Ƥ��
	//BkStyle::LoadStyles(IDR_BK_STYLE_DEF); // ���ط��


	//BkFontPool::SetDefaultFont(_T("����"), -12);
	//BkSkin::LoadSkins(IDR_BK_SKIN_DEF);
 //   BkStyle::LoadStyles(IDR_BK_STYLE_DEF);
 //   BkString::Load(IDR_BK_STRING_DEF);
}

CMainDlg::~CMainDlg()
{

}

LRESULT CMainDlg::OnClose()
{
	EndDialog(0);
	return 0;
}

LRESULT CMainDlg::OnMaxWindow()
{
	if (WS_MAXIMIZE == (GetStyle() & WS_MAXIMIZE))
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE | HTCAPTION, 0);
		SetItemAttribute(IDC_BTN_SYS_MAX, "skin", "maxbtn");
	}
	else
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE | HTCAPTION, 0);
		SetItemAttribute(IDC_BTN_SYS_MAX, "skin", "restorebtn");
	}

	return 0;
}

LRESULT CMainDlg::OnMinWindow()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
	return 0;
}