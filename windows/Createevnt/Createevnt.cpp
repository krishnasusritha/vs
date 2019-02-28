// Createevnt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
int _tmain()
{
	HANDLE hevent;
	hevent = CreateEvent(NULL, FALSE, FALSE, TEXT("KRISHNA"));
	if (hevent == NULL)
		printf("event not creaqted");
	else
		printf("event created");
	getchar();
    return 0;
}

