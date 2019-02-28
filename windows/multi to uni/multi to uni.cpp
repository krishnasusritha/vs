// multi to uni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <windows.h>
//#include <tchar.h>
using namespace std;

int main()
{
	//wchar_t w[] = L"krishhua";
	char c[] = "hie hie";
	int r = MultiByteToWideChar(CP_UTF8, 0, c, -1, NULL, 0);
	WCHAR *c_t = new WCHAR[r];
	int r1= MultiByteToWideChar(CP_UTF8, 0, c, -1, c_t, r);
	if (0 == r1)
		printf( "wide char not bulit");
	else
	printf( " %S   wide char",c_t);
	getchar();
    return 0;
}

