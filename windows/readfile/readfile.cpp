#include "stdafx.h"
#include<iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;
#define BUFF_SIZE 200

int _tmain(int argc,LPTSTR argv[])
{
	HANDLE hfread;
	DWORD nbr;
	TCHAR buff[BUFF_SIZE];
	ZeroMemory(buff, BUFF_SIZE);
	hfread = CreateFile(argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (INVALID_HANDLE_VALUE == hfread)
	{
		printf("not handled properly");

	}
	else
		printf("file open");

	BOOL ret = ReadFile(hfread, buff, BUFF_SIZE,&nbr, NULL);
	if (ret == 0)
		printf("file not found");


	
		_tprintf(_T(" %LS %d"), buff,nbr);
	getchar();

	return 0;
}