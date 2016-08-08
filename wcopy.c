
#include <stdio.h>
#include <windows.h>

int main(int argc, LPTSTR argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: wcopy file1 file2\n");
		return 1;
	}
	
	if (!CopyFile(argv[1], argv[2], FALSE))
	{
		fprintf(stderr, "CopyFile Error: %x\n", GetLastError());
		return 1;
	}
	
	
	return 0;
}