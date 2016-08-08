#include <windows.h>
#include <stdio.h>

#define MAX_KEY_LENGTH 255

HKEY Open(HKEY root, LPTSTR path,  REGSAM permission)
{
	HKEY hKey;
	LONG lResult = RegOpenKeyEx(
		root, //HKEY_CURRENT_USER, HEKY_CURRENT_MACHINE, //HKEY_CLASSES_ROOT
		path, //"SOFTWARE\\MICROSOFT\\"
		0, //MUST be 0
		permission, //KEY_WRITE, KEY_READ, KEY_ALL_ACCESS
		&hKey
		);

	if(lResult == ERROR_SUCCESS)
	{
		return hKey;
	}
	return INVALID_HANDLE_VALUE;
}

void Close(HKEY hKey)
{
	RegCloseKey(hKey);
}

void ListKeys(HKEY hKey)
{
	DWORD index = 0, SubKNameLen = MAX_KEY_LENGTH;
	CHAR SubkName[MAX_KEY_LENGTH];
	
	while (ERROR_SUCCESS == RegEnumKeyEx(
		hKey,
		index,
		SubkName,
		&SubKNameLen,  //IN & OUT
		NULL,
		NULL, 
		NULL,
		NULL
		)
	)
	{
		printf("%s\n", SubkName);
		SubKNameLen = MAX_KEY_LENGTH;
		index++;
	}
	
}

int main(int argc, LPTSTR argv[])
{
	//Win API +  C
	//key + value + data [type]
	//1-open key A
	HKEY hKey = Open(
		HKEY_CURRENT_USER,
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer",
		KEY_ALL_ACCESS
		);
	if(hKey != INVALID_HANDLE_VALUE)
	{
		//2-create key A->B + create value A->1 + edit value + lis
		//do you job
		//printf("Key opned...\n");
		//printf(hKey);
		ListKeys(hKey);
	}
	else
	{
		printf("key not opend...");
	}
	//3-close key A
	Close(hKey);
	return 0;
}