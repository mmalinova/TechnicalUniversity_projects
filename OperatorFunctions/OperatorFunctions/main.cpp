// OperatorFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include "SuperLongInt.h"

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	SuperLongInt s(45567897);
	SuperLongInt a(354781);
	SuperLongInt m("354781");
	SuperLongInt c = s + a;
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------