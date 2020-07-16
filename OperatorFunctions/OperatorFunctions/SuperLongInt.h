#pragma once
#include <iostream>

//-----------------------------------------------------------------------------------------------------------------------------
class SuperLongInt
{
	char Number[100];
	int Len;
	char OverflowFlag;
	char NegativeFlag;
public:
	SuperLongInt(void);
	SuperLongInt(long int a);
	SuperLongInt(char *c);
	SuperLongInt(SuperLongInt &S);
	~SuperLongInt();
	char &ToString(long int a);
	SuperLongInt &operator=(SuperLongInt &si);
	SuperLongInt operator+(SuperLongInt si);
	SuperLongInt operator-(SuperLongInt si);
	friend std::ostream &operator<<(std::ostream& o, SuperLongInt &r);
	friend std::istream &operator>>(std::istream& i, SuperLongInt &r);
	void Print(std::ostream &os);
};