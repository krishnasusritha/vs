// Expandenvstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;

int main()
{
	TCHAR env_var[] =L"%TEMP%";
	TCHAR buff[34];
	int n=ExpandEnvironmentStringsW(env_var, buff, 34);
	printf("%S  %d",buff,n);
	getchar();
}

