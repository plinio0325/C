#include <stdio.h>
#include <windows.h>
#include <time.h>



DWORD WINAPI f1(LPVOID params)
{
	int x = *((int *)params);
	for(size_t i = 0; i < x; i++)
	{
		printf("f2: Local Counter%02d, clock: %09d\n", i, clock());
		Sleep(1000);//Sleep for 1 second ==
	}
}

DWORD WINAPI f2(LPVOID params)
{
	int x = *((int *)params);
	for(size_t i = 0; i < x; i++)
	{
		printf("f2: Local Counter%02d, clock: %09d\n", i, clock());
		Sleep(1000);//Sleep for 1 second ==
	}
}

DWORD WINAPI f3(LPVOID params)
{
	int x = *((int *)params);
	for(size_t i = 0; i < x; i++)
	{
		printf("f3: Local Counter%02d, clock: %09d\n", i, clock());
		Sleep(1000);//Sleep for 1 second ==
	}
	
}

int main()
{
	int x1 = 4, x2 = 8, x3 =10;
	HANDLE f1_thread = CreateThread(NULL, 0, f1, &x1, 0, NULL);
	HANDLE f2_thread = CreateThread(NULL, 0, f2, &x2, 0, NULL);
	HANDLE f3_thread = CreateThread(NULL, 0, f3, &x3, 0, NULL);
	
	HANDLE array_of_thread[3];
	array_of_thread[0] = f1_thread;
	array_of_thread[1] = f2_thread;
	array_of_thread[2] = f2_thread;
	array_of_thread[3] = f2_thread;
	
	WaitForMultipleObjects(3, array_of_thread, TRUE, INFINITE);
	CloseHandle(f1_thread);
	CloseHandle(f2_thread);
	CloseHandle(f3_thread);

	system("pause");
	return 0;
}