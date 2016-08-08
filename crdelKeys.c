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

HKEY CreateKey(HKEY hKey, LPTSTR path)
{
	HKEY hKeyResult;
	DWORD result;
	RegCreateKeyEx(
		hKey, 
		path, 
		NULL, 
		NULL,
		0,  
		permission,
		NULL,
		&hKeyResult, //OUT
		&result //OUT
		);
	if(result == REG_CREATED_NEW_KEY)
	{
		return hKeyResult;
	}
	return INVALID_HANDLE_VALUE;
}

void DeleteKey(HKEY hKey, LPTSTR path)
{
	RegDeleteKey(hKey, path);
}

int main(int argc, LPTSTR argv[])
{
	//Win API +  C
	//key + value + data [type]
	//1-open key A
	HKEY hKey = Open(
		HKEY_CURRENT_USER,
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced",
		KEY_ALL_ACCESS
		);
	if(hKey != INVALID_HANDLE_VALUE)
	{
		//do you job
		if(createKey(hKey, "xyz", KEY_ALL_ACCESS) == INVALID_HANDLE_VALUE)
		{
			DeleteKey(hKey, "xyz");
		}
		
	}

	//3-close key A
	Close(hKey);
	return 0;
}