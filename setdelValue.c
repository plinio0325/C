#include <windows.h>

//Setando e Deletando Valores em chaves do registro

HKEY Open(HKEY root,LPTSTR path, REGSAM permission)
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

void SetValueString(HKEY hKey, LPTSTR path, LPTSTR data)
{
	RegSetValueEx(
		hKey,
		path,
		NULL, //Reserved
		REG_SZ, 
		(const BYTE*)data,
		strlen(data)
		
		);
}

void SetValueDWORD(HKEY hKey, LPTSTR path, DWORD data)
{
	RegSetValueEx(
		hKey,
		path,
		NULL, //Reserved
		REG_SZ, 
		(const BYTE*)&data,
		sizeof(data)
		);
}

void DeleteValue(HKEY hKey, LPTSTR path)
{
	RegDeleteValue(hKey, path);
}


int main()
{
	HKEY hKey = Open(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", KEY_ALL_ACCESS);
	if (hKey != INVALID_HANDLE_VALUE)
	{
		//do your job
		SetValueString(hKey, "qqqw", "ABCDEFG");
		SetValueDWORD(hKey, "HideFileExt", 0);
	}
	Close(hKey);
	return 0;
}