#pragma once
#include "Estate.h"

//----------------------------------------------------------------------------------------------------------------------------
class Parcel:public Estate
{
	bool water;
	bool electricity;
	bool nearnessToTheRoad;
public:
	Parcel();
	Parcel(bool pwater, bool pelectricity, bool pnearnessToTheRoad, char *paddress, char *powner, double pprice, float parea);
	~Parcel();
	void Print();
};