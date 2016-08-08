#include <windows.h> 

// Fecha uma janela do Windows

void EndTaskManeger()
{
	while (TRUE)
	{
		HANDLE TaskMgr = FindWindow(NULL, "Calculadora");
		if(TaskMgr !=  INVALID_HANDLE_VALUE)
		{
			SendMessage(TaskMgr, WM_SYSCOMMAND, SC_CLOSE, FALSE);
		}
		Sleep(100);
	}
}

int main(int argc, LPTSTR argv[])
{
	EndTaskManeger();
	return 0;
}