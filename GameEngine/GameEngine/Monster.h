#pragma once
#include "GameUnit.h"

//-----------------------------------------------------------------------------------------------------------------------
class Monster:public GameUnit
{
	int Nails;   //(нокти) – стойности от 1 до 10
	int Teeth;   //(зъби) – стойности от 1 до 10
public:
	Monster();
	Monster(TPoint PositionInit, /*TPoint TargetInit,*/ int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int TeamInit, int AttackRangeInit, int NailsInit, int TeethInit);
	~Monster();
	void Print();
	int Attack();
	void Defend(int AttackStrength);
};