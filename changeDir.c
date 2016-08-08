
#include <stdio.h>
#include <windows.h>

int main(int argc, LPTSTR argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: changeDir <New Directory>\n");
	}
	SetCurrentDirectory(argv[1]);
	CHAR pwdBuffer[MAX_PATH];
	DWORD x = GetCurrentDirectory(MAX_PATH, pwdBuffer);
	printf(pwdBuffer);
	
	return 0;
	
}