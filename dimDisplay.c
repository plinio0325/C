#include <windows.h>

// Desligar a tela temporiarimente
void Dim_Display()
{
	while(TRUE)
	{
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, 2);
		Sleep(20000);
	}
}

int main(int argc, LPTSTR argv[])
{
	Dim_Display();
	return 0;
}