#include "stdafx.h"
#include "Parcel.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Parcel::Parcel():Estate()
{
	water = false;
	electricity = false;
	nearnessToTheRoad = false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Parcel::Parcel(bool pwater, bool pelectricity, bool pnearnessToTheRoad, char *paddress, char *powner, double pprice, float parea):Estate(paddress, powner, pprice, parea)
{
	water = pwater;
	electricity = pelectricity;
	nearnessToTheRoad = pnearnessToTheRoad;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Parcel::~Parcel()
{

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Parcel::Print()
{
	cout << address << "\t" << owner << "\t" << price << "\t" << area << "\t" << water << "\t" << electricity << "\t" << nearnessToTheRoad << "\t" << endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------