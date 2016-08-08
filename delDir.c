
#include <stdio.h>
#include <windows.h>

int main(int argc, LPTSTR argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: delDir <New Directory>\n");
	}
	RemoveDirectory(argv[1]);
	
}