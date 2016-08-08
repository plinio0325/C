                                                                                                         
#include <stdio.h>
#include <windows.h>
#define BUF_SIZE 16384

//#if define UNICODE
	//#define CreateFile  CreateFileW
//#else
	//#define CreateFile  CreateFileA
//#endif

int main(int argc, LPTSTR argv[])
{
	//Init file_Point 
	HANDLE hIn, hOut;
	//Init Counter
	DWORD nIn, nOut;
	//Init buffer
	CHAR buffer[BUF_SIZE];

	
	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file1 file2\n");
		return 1;
	}

	//Open file1
	hIn = CreateFile(
		argv[1], //LPCTSTR
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 
		NULL
		);
		
	if ( hIn == INVALID_HANDLE_VALUE)
	{
		fprintf(stderr, "Can't open input file. Erro:  %x\n", GetLastError());
		return 1;	
	}

	//Create File2
	hOut = CreateFile(
		argv[2], 
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL
		);
	
	if ( hOut == INVALID_HANDLE_VALUE)
	{
		fprintf(stderr, "Can't open output file. Erro:  %x\n", GetLastError());
		CloseHandle(hIn);
		return 3;	
	}
	
	//Loop until EOF
	//Read part of File1 -> Buffer
	while (
		ReadFile (
			hIn,
			buffer,
			BUF_SIZE, 
			&nIn,
			NULL
		) && nIn > 0 )
		{
			
		//Write Buffer -> file2
		WriteFile(
			hOut,
			buffer,
			nIn,
			&nOut,
			//nOut,
			NULL		
			);
		
		if (nIn != nOut)
			{
				fprintf(stderr, "Fatal write | Error: %x\n", GetLastError());
				CloseHandle(hIn); 	
				CloseHandle(hOut);
				return 1;
			}
			
		}
		
	

	
	//close File1 File2
	CloseHandle(hIn);
	CloseHandle(hOut);
 

	return 0;

}