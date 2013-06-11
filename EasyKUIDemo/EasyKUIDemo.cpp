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

	//获取资源路径
	CString strResPath;
	GetModuleFileName((HMODULE)&__ImageBase, strResPath.GetBuffer(MAX_PATH + 10), MAX_PATH);
    strResPath.ReleaseBuffer();
    strResPath.Truncate(strResPath.ReverseFind(L'\\') + 1);
    strResPath += L"res";

	//strResPath.Format(L"DoModal returns %d", 0);
	//MessageBox(strResPath);
	//设置UI资源路径
	BkResManager::SetResourcePath(strResPath);
	BkFontPool::SetDefaultFont(L"字体", -12); // 设置字体
	BkString::Load(IDR_BK_STRING_DEF); // 加载字符串
	BkSkin::LoadSkins(IDR_BK_SKIN_DEF); // 加载皮肤
	BkStyle::LoadStyles(IDR_BK_STYLE_DEF); // 加载风格

	int nRet = 0;
	//处理程序初始化
	CMainDlg dlgMain;
	nRet = dlgMain.DoModal(NULL);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}