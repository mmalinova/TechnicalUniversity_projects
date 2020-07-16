#pragma once
#include "Estate.h"

//-------------------------------------------------------------------------------------------------------
class Apartament:public Estate
{
	int numberOfRooms;
	int floor;
public:
	Apartament();
	Apartament(int pnumberOfRooms, int pfloor, char *paddress, char *powner, double pprice, float parea);
	~Apartament();
	void Print();
};