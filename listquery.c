#include <windows.h>
#include <stdio.h>


#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

HKEY Open(HKEY root, LPTSTR path, REGSAM permission)
{
	HKEY hKey;
	LONG lResult = RegOpenKeyEx(
		root, //HKEY_LOCAL_MACHINE,  HKEY_USERS,  HKEY_CURRENT_CONFIG,  HKEY_CLASSES_ROOT,  HKEY_CURRENT_USER
		path, // the path of the key
		0,    // must be 0
		permission, //KEY_WRITE, KEY_READ, KEY_ALL_ACCESS, KEY_QUERY_VALUE, KEY_ENUMERATE_SUB_KEYS
		&hKey // OUT : The result [pass by refrence]
		);

	if (lResult == ERROR_SUCCESS)
		return hKey;
	return INVALID_HANDLE_VALUE;
}

void Close(HKEY hKey)
{
	RegCloseKey(hKey);
}

void ListValues(HKEY hKey)
{
	DWORD index = 0, ValueNameLen = MAX_KEY_LENGTH, DataLen = MAX_VALUE_NAME;
	CHAR ValueName[MAX_KEY_LENGTH], Data[MAX_VALUE_NAME];
	DWORD type;
	while (ERROR_SUCCESS == RegEnumValue(hKey, //opened key
		index, // incremental counter
		ValueName, // OUT : return value name
		&ValueNameLen, // IN & OUT : return value lenght
		NULL, // Reserved
		&type, // OUT : return REG_BINARY,REG_DWORD , REG_SZ
		Data, // OUT : return data of the value
		&DataLen // OUT : return data length
		))
	{
		if (type == REG_DWORD)
			printf("%s : %x\n", ValueName, (DWORD)*Data);
		else if (type == REG_SZ)
			printf("%s : %s\n", ValueName, Data);

		ValueNameLen = MAX_VALUE_NAME;
		DataLen = MAX_VALUE_NAME;
		index++;
	}
}

void QueryValue(HKEY hKey, LPTSTR path)
{
	DWORD  DataLen = MAX_VALUE_NAME;
	CHAR Data[MAX_VALUE_NAME];
	DWORD type;
	if (ERROR_SUCCESS == RegQueryValueEx(hKey, //opened key
		path, // the path of the key
		NULL, // Reserved
		&type, // OUT : return REG_BINARY,REG_DWORD , REG_SZ
		Data, // OUT : return data of the value
		&DataLen // OUT : return data length
		))
	if (type == REG_DWORD)
		printf("%s : %x\n", path, (DWORD)*Data);
	else if (type == REG_SZ)
		printf("%s : %s\n", path, Data);
}

int main()
{
	HKEY hKey = Open(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", KEY_ALL_ACCESS);
	if (hKey != INVALID_HANDLE_VALUE)
	{
		//do your job
		//ListValues(hKey);
		QueryValue(hKey, "YPU");
	}
	Close(hKey);
	return 0;
}