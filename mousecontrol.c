#include <windows.h> 

//Manipulando o mouse

void CrazyMouse()
{
	int i = 0;
	while (i++ < 50)
	{
		int x = rand() % 800;
		int y = rand() % 600;
		SetCursorPos(x, y);
		Sleep(200);
		
	}
}

void ShiftMouse()
{
	while (TRUE)
	{
		POINT mouse;
		if (GetCursorPos(&mouse))
		{
			int X = mouse.x + rand() % 50;
			int Y = mouse.y + rand() % 50;
			SetCursorPos(X, Y);
		}
		Sleep(1000);
	}
}

int main(int argc, LPTSTR argv[])
{
	//CrazyMouse();
	ShiftMouse(rand() % 5000);
	return 0;
}