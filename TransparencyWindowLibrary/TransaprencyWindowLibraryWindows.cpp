#include <windows.h>
#include <string>

HWND createWindow(std::string windowName, bool transparent, bool clickthrough) {
	std::wstring stemp = std::wstring(windowName.begin(), windowName.end());
	LPCWSTR title = stemp.c_str();
	HWND hWnd = CreateWindowEx(WS_EX_LAYERED | WS_EX_TRANSPARENT, title, title, NULL, 0, 0, 640, 480, NULL, 0, GetModuleHandle(NULL), 0);
	SetLayeredWindowAttributes(hWnd, 0, 100, LWA_ALPHA);
	return hWnd;
}