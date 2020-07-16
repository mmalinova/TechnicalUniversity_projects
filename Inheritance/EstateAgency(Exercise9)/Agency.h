#pragma once
#include "Estate.h"

//-------------------------------------------------------------------------------------------------------
class Agency
{
public:
	char name[50];
	Estate *A[100];
	int numberOfEstates;
public:
	Agency();
	Agency(char *pname);
	~Agency();
	int Add(Estate &Es);
	int Remove(char *paddress);
	int Search(char *paddress);
	void Search(double price1, double price2);
	friend int cf(void *el1, void *el2);
	void Print();
};