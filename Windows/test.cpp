#include "windows.h"
#include <string>

int main()
{
    std::string windowName = "test";
    std::wstring stemp = std::wstring(windowName.begin(), windowName.end());
	LPCWSTR title = stemp.c_str();

	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);

	HWND hWnd = CreateWindowEx(WS_EX_COMPOSITED | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST, title, title, NULL, 0, 0, width, height, NULL, 0, GetModuleHandle(NULL), 0);
	SetLayeredWindowAttributes(hWnd, 0, 100, LWA_ALPHA);
	ShowWindow(hWnd, SW_SHOW);
    return 0;
}