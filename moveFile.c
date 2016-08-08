
#include <stdio.h>
#include <windows.h>

//#define DeleteFile DeleteFileA


int main(int argc, LPTSTR argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: moveFile <filename1> <filename2>\n");
	}
	MoveFile(argv[1], argv[2]);
	
}