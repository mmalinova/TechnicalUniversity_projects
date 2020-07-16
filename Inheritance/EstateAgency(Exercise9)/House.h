#pragma once
#include "Estate.h"

//----------------------------------------------------------------------------------------------------------------------------
class House:public Estate
{
	int numberOfRooms;
	int numberOfFloors;
	float yardArea;
public:
	House();
	House(int pnumberOfRooms, int pnumberOfFloors, float pyardArea, char *paddress, char *powner, double pprice, float parea);
	~House();
	void Print();
};