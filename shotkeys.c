#include <windows.h> 
#include <stdio.h>

#define GetMessage GetMessageA


void ShortKeys()
{
	RegisterHotKey(NULL, 1, MOD_ALT | MOD_CONTROL, 0x61);
	MSG msg = {0};
	while(GetMessage(&msg, NULL, 0, 0 ) != 0)
	{
		if (msg.message == WM_HOTKEY)
		{
			printf("Shortkeys Pressed\n");
		}
	}
}

int main(int argc, LPTSTR argv[])
{
	ShortKeys();
	return 0;
}