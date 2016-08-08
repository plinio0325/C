#include <stdio.h>
#include <windows.h>

int main(int argc, LPTSTR argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: myFind pattern\n");
		return 1;
	}
	HANDLE hFind;
	WIN32_FIND_DATA FindData;
	//Get Search Handle
	hFind = FindFirstFile(argv[1], &FindData);
	printf(FindData.cFileName);
	printf("\n");
	//LOOP
	while (FindNextFile(hFind, &FindData))
	{
		//Get file Info
		printf(strcat( FindData.cFileName, "\n"));
	}	
	//Close Handle
	FindClose(hFind);

	
	
	
	return 0;
}