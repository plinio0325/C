#include <windows.h> 

void Hide()
{
	HANDLE stealth = FindWindow("ConsoleWindowClass", NULL);
	if (stealth != INVALID_HANDLE_VALUE)
	{
		ShowWindow(stealth, FALSE);
	//	Sleep(3000);
	//	ShowWindow(stealth, TRUE);
	}
}

int main(int argc, LPTSTR argv[])
{
	Hide();
	while (TRUE)
	{
		Sleep(1000);
	}
	
	return 0;
}