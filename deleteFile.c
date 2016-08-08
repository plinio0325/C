
#include <stdio.h>
#include <windows.h>

//#define DeleteFile DeleteFileA


int main(int argc, LPTSTR argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: deleteFile <filename>\n");
	}
	DeleteFile(argv[1]);
	
}