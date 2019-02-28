// prg1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

int main()
{
	char c []= "sxzjhasuihs";
	//CHAR ch = 'S';
	WCHAR w[] = L"krishna";
	bool n = IsTextUnicode(w,wcslen(w), NULL);
	if (n != 0)
		printf("unicode");
	else
		printf("not uniocde");
	getchar();
	return 0;
}
