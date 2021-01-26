#undef UNICODE
#define UNICODE
#define MIN_ALL        419
#define MIN_ALL_UNDO   416
#include <windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{

	bool HIDDEN_MODE = false;

	while (true)
	{
		if ((GetKeyState(VK_CONTROL) & 0x8000) && (GetKeyState(VK_MENU) & 0x8000))
		{
			HWND lHwnd = FindWindow(L"Shell_TrayWnd", NULL);
			SendMessage(lHwnd, WM_COMMAND, HIDDEN_MODE ? MIN_ALL_UNDO : MIN_ALL, 0);
			HIDDEN_MODE = !HIDDEN_MODE;
			Sleep(500);
		}
		Sleep(1);
	}
	
	return 0;
}
