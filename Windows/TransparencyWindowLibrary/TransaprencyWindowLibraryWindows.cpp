#include <windows.h>
#include <string>

HWND hWnd;


void createWindow(std::string windowName, bool transparent, bool clickthrough) {
	std::wstring stemp = std::wstring(windowName.begin(), windowName.end());
	LPCWSTR title = stemp.c_str();

	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);

	hWnd = CreateWindowEx(WS_EX_COMPOSITED | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST, title, title, NULL, 0, 0, width, height, NULL, 0, GetModuleHandle(NULL), 0);
	SetLayeredWindowAttributes(hWnd, 0, 100, LWA_ALPHA);
	ShowWindow(hWnd, SW_SHOW);
}

void drawImage(std::string image, int x, int y) {
	std::wstring stemp = std::wstring(image.begin(), image.end());
	LPCWSTR imagePath = stemp.c_str();

	HDC hdc = GetDC(hWnd);
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hbm = (HBITMAP)LoadImage(NULL, imagePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HGDIOBJ old_obj = SelectObject(hdcMem, hbm);
	BITMAP bm;
	GetObject(hbm, sizeof(bm), &bm);
	BitBlt(hdc, x, y, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
	SelectObject(hdcMem, old_obj);
	DeleteDC(hdcMem);
	ReleaseDC(hWnd, hdc);
}

bool checkKeyPress(int key) {
	if (GetAsyncKeyState(key) & 0x8000) {
		return true;
	}
	return false;
}
