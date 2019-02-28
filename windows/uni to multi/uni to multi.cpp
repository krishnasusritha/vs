// uni to multi.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;

int main()
{
	wchar_t w[] = L"తెలుగు లిపి";
	//char c[] = ";
	int r = WideCharToMultiByte(CP_UTF8, 0, w, -1, NULL,0, NULL,NULL);
	char *c_t = new char[r];
	int r1 = WideCharToMultiByte(CP_UTF8, 0, w, -1, c_t, r,NULL,NULL);
	if (0 == r1)
		printf("multi byte not bulit");
	else
		printf(" %s  multi byte", c_t);
	printf(" %S  multi byte", w);
	getchar();
	return 0;
}



