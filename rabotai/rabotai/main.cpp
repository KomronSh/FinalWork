#include <windows.h>
#include "resource.h"

HWND hEdit1;
HWND hEdit2;
HWND hList;
INT num;
INT size;
CHAR string1[] = { 0 };
CHAR string2[] = { 0 };

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
		hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
		hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
		hList = GetDlgItem(hwnd, IDC_LIST1);
		//SetFocus(hEdit1);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
		{
			SendMessage(hEdit1, WM_GETTEXT, (WPARAM)255, (LPARAM)string1);
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)string1);
			SendMessage(hEdit1, WM_SETTEXT, 0, 0);
		}
			break;
		case IDC_BUTTON2:
		{
			SendMessage(hEdit2, WM_GETTEXT, (WPARAM)255, (LPARAM)string2);
			size = SendMessage(hList, LB_GETCOUNT, 0, 0L);
			for (int i = 0; i < size; i++) {
				num = SendMessage(hList, LB_FINDSTRING, 0, (LPARAM)string2);
				SendMessage(hList, LB_DELETESTRING, (WPARAM)num, 0L);
			}
			SendMessage(hEdit2, WM_SETTEXT, 0, 0);
			break;
		}
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return FALSE;
	}
	return FALSE;
}