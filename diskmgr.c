#include <windows.h> 

BOOL ejectDisk(char driveLetter[]) //char driveLetter[]
{
	char tmp[10] = "\\\\.\\G";
	HANDLE handle = CreateFile( 
		strcat(tmp, driveLetter), GENERIC_READ, 
		FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
		
	if(handle != INVALID_HANDLE_VALUE)
	{
		DWORD bytes = 0;	
		DeviceControl(handle, IOCTL_STORAGE_EJECT_MEDIA,
			0, 0, 0, 0, &bytes, 0);
		CloseHandle(handle);
		return TRUE;
	}
	return FALSE;
}

void EjectCDROMs()
{
	//GetDriveType
	//GetLogicalDriveStrings
	DWORD dwSize = MAX_PATH;
	char szLogicalDrives[MAX_PATH] = { 0 };
	
	DWORD dwResult = GetLogicalDriveStrings(dwSize, szLogicalDrives);
	
	if (dwResult > 0)
	{
		char* szSingleDrive = szLogicalDrives;//Split szLogicalDrives by <null>
		while (*szSingleDrive)
		{
			CHAR drive[3];
			substr(szSingleDrive, drive, 0, 2);
			if (GetDriveType(drive) == DRIVE_CDROM)//DRIVE_REMOVABLE ==> USB //DRIVE_FIXED ==> C: D: //DRIVE_CDROM ==> CDROM
				ejectDisk(drive);
			// get the next drive
			szSingleDrive += strlen(szSingleDrive) + 1;
		}
	}
		
}

int main(int argc, LPTSTR argv[])
{
	//ejectDisk("G:");
	EjectCDROMs();
	return 0;
}