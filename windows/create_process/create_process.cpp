// create_process.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<Windows.h>
#include <tchar.h>
int _tmain(DWORD argc,TCHAR * argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (argc >= 2)
	{
		printf("enter process name");
	}
	if (!CreateProcess(NULL,   // No module name (use command line)
		argv[1],        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());

	}

	printf("Thread Id  %d", pi.dwThreadId);
	printf("Process Id  %d", pi.dwProcessId);
//	CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);
	//system("pause");
	getchar();
	return 0;
}
