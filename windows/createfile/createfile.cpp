#include "stdafx.h"
#include<iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;
#define BUFF_SIZE 200

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfwrite,hfread;
	DWORD nbw,nbr;
	//char buff[]="this is krishna, say hi";
	TCHAR buff[] = TEXT("this is krishna, say hi");
	//ZeroMemory(buff, sizeof(buff));
	hfwrite = CreateFile(argv[1],
		GENERIC_WRITE|GENERIC_READ,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	if (INVALID_HANDLE_VALUE == NULL)
	{
		printf("not handled properly");
	}
	else
		printf("file open");
	BOOL ret = WriteFile(hfwrite, buff, sizeof(buff), &nbw, NULL);
	if (ret == 0)
		printf("file not found");
	else
		ZeroMemory(buff, sizeof(buff));
	hfread = CreateFile(argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
		BOOL ret1 = ReadFile(hfread, buff, BUFF_SIZE, &nbr, NULL);
	if (ret1 == 0)
		printf("file not found");



	_tprintf(_T(" %s %d"), buff, nbr);
		//_tprintf(_T("   Text from %s\n%d"), buff, BUFF_SIZE);
	getchar();
	return 0;
}