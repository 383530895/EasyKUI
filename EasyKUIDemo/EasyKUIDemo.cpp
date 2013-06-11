#include "stdafx.h"
#include <bkres/bkres.h>
#include "MainDlg.h"

CAppModule _Module;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR /*lpstrCmdLine*/, int /*nCmdShow*/)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);
	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	BkWinManager bkwinmgr;

	//��ȡ��Դ·��
	CString strResPath;
	GetModuleFileName((HMODULE)&__ImageBase, strResPath.GetBuffer(MAX_PATH + 10), MAX_PATH);
    strResPath.ReleaseBuffer();
    strResPath.Truncate(strResPath.ReverseFind(L'\\') + 1);
    strResPath += L"res";

	//strResPath.Format(L"DoModal returns %d", 0);
	//MessageBox(strResPath);
	//����UI��Դ·��
	BkResManager::SetResourcePath(strResPath);
	BkFontPool::SetDefaultFont(L"����", -12); // ��������
	BkString::Load(IDR_BK_STRING_DEF); // �����ַ���
	BkSkin::LoadSkins(IDR_BK_SKIN_DEF); // ����Ƥ��
	BkStyle::LoadStyles(IDR_BK_STYLE_DEF); // ���ط��

	int nRet = 0;
	//��������ʼ��
	CMainDlg dlgMain;
	nRet = dlgMain.DoModal(NULL);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}