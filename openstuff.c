#include <windows.h>


void OpenStuff()
{
//	ShellExecute(NULL, "open", "notepad", NULL, NULL, SW_SHOWDEFAULT);  // SW_MAXMIZE
	ShellExecute(NULL, "open", "calc", NULL, NULL, SW_MAXIMIZE);
//	ShellExecute(NULL, "open", "cmd", "/k ping google.com", NULL, SW_MAXIMIZE);
	ShellExecute(NULL, "open", "cmd", "/k ipconfig > ip", NULL, SW_HIDE);
}

int main(int argc, LPTSTR argv[])
{
	OpenStuff();	
	return 0;
	
}