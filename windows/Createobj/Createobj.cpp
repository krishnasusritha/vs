// Createobj.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
int main()
{
	HANDLE hmutex;
	hmutex = CreateMutex(NULL, FALSE, TEXT("KSHUID"));
	if (hmutex == NULL)
		printf("mutex not created");
	else
		printf("mutex created successfuly");
	hmutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, TEXT("KSHUID"));
	if (hmutex == NULL)
		printf("mutex not created");
	else
		printf("mutex created successfuly");
	getchar();
	return 0;
}

