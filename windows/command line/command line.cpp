// command line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;

int main()
{
	LPWSTR *w;
	int n, i;
	w = CommandLineToArgvW(GetCommandLine(), &n);
	if (NULL == w)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	else
		for (i = 0; i < n; i++) printf("%d: %S\n", i, w[i]);
	printf("%d", n);
	// Free memory allocated for CommandLineToArgvW arguments.
	getchar();
	LocalFree(w);
}

