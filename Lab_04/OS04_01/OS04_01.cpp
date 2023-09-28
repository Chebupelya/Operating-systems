#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

	for (short i = 1; i <= 10000; ++i)
	{
		cout << i << ". PID = " << pid << "       TID = " << tid << "\n";
		Sleep(1000);
	}
	system("pause");
	return 0;
}

// 1. Powershell ISE:		(Get-Process OS04_01).Threads