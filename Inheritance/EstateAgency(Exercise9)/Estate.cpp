#include "stdafx.h"
#include "Estate.h"
#include <iostream>
#include <string.h>

using namespace std;
//------------------------------------------------------------------------------------------------
Estate::Estate()
{
	address[0] = 0;
	owner[0] = 0;
	price = 0;
	area = 0;
}
//------------------------------------------------------------------------------------------------
Estate::Estate(char *paddress, char *powner, double pprice, float parea)
{
	strcpy_s(address, paddress);
	strcpy_s(owner, powner);
	price = pprice;
	area = parea;
}
//------------------------------------------------------------------------------------------------
Estate::~Estate()
{
}
//------------------------------------------------------------------------------------------------
Estate &Estate::operator=(Estate &pEs)
{
	strcpy_s(address, pEs.address);
	strcpy_s(owner, pEs.owner);
	price = pEs.price;
	area = pEs.area;
	return *this;
}
//------------------------------------------------------------------------------------------------
char *Estate::getAddress()
{
	return address;
}
//------------------------------------------------------------------------------------------------
double Estate::getPrice()
{
	return price;
}
//------------------------------------------------------------------------------------------------
void Estate::Print()
{
	cout << address << "\t" << owner << "\t" << price << "\t" << area << endl;
}
//------------------------------------------------------------------------------------------------
