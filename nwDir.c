
#include <stdio.h>
#include <windows.h>

int main(int argc, LPTSTR argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: nwDir <New Directory>\n");
	}
	CreateDirectory(argv[1], NULL);
	
}