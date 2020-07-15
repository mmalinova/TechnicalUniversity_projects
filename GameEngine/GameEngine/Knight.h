#pragma once
#include "GameUnit.h"

//-----------------------------------------------------------------------------------------------------------------------
class Knight:public GameUnit
{
	int Sword;   //(меч) – стойности от 1 до 10
	int Armor;   //(броня) – стойности от 1 до 10
public:
	Knight();
	Knight(TPoint PositionInit, /*TPoint TargetInit,*/ int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int TeamInit, int AttackRangeInit, int SwordInit, int ArmorInit);
	~Knight();
	void Print();
	int Attack();
	void Defend(int AttackStrength);
};