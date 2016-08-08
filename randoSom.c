
#include <windows.h>

void RandomSound()
{
	Beep(1000, 2000);
}

int main(int argc, LPTSTR argv[])
{
	RandomSound();
	return 0;
}