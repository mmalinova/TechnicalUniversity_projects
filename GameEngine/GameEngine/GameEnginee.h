#pragma once
#include "GameUnit.h"

//-----------------------------------------------------------------------------------------------------------------------
class GameEnginee
{
public:
	GameUnit *Units[100];  //масив от указатели към обекти от базовия клас GameUnit
	int CountUnits;
	GameEnginee() { CountUnits = 0; }
	~GameEnginee();
	int Add(GameUnit &GU);
	int Step();
	void Print();
	void Clear();
};

