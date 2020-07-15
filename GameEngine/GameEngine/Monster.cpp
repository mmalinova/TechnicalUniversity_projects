#include "stdafx.h"
#include "Monster.h"
#include <iostream>
#include "GameEnginee.h"

using namespace std;
int n = 1;
extern GameEnginee *pointer;
//-----------------------------------------------------------------------------------------------------------------------
Monster::Monster() :GameUnit()
{
	Nails = 1;
	Teeth = 1;
}
//-----------------------------------------------------------------------------------------------------------------------
Monster::~Monster()
{
}
//-----------------------------------------------------------------------------------------------------------------------
Monster::Monster(TPoint PositionInit, /*TPoint TargetInit,*/ int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int TeamInit, int AttackRangeInit, int NailsInit, int TeethInit) :GameUnit(PositionInit, /*TargetInit,*/ ConditionInit, MoveSpeedInit, AttackSpeedInit, TeamInit, AttackRangeInit)
{
	Nails = NailsInit;
	Teeth = TeethInit;
}
//-----------------------------------------------------------------------------------------------------------------------
void Monster::Print()
{
	if (n == 1)
		cout << "\n\tFirst Monster:" << endl;
	else if (n == 2)
		cout << "\n\tSecond Monster:" << endl;
	else
		cout << "\n\tThird Monster:" << endl;
	cout << '(' << Position.x << ';' << Position.y << ')';
	if (Attack() == 1)
		cout << "Attack!";
	n++;
}
//-----------------------------------------------------------------------------------------------------------------------
int Monster::Attack()
{
	int AttackStrength = (Condition / 20 + 1) * ((Nails + Teeth) / 5 + 1);
	if (AttackSpeed <= 0 || Condition <= 0)
		return -1;
	else
	{
		int restart = TactAttackSpeed;
		if (!TactAttackSpeed)
		{
			for (int i = 0; i < pointer->CountUnits; i++)
			{
				if (Team != pointer->Units[i]->Team)
				{
					if (((pointer->Units[i]->Position.x > Position.x - AttackRange) && (pointer->Units[i]->Position.x < Position.x + AttackRange)) && ((pointer->Units[i]->Position.y > Position.y - AttackRange) && (pointer->Units[i]->Position.y < Position.y + AttackRange)))
						pointer->Units[i]->Defend(AttackStrength);
				}
			}
			TactAttackSpeed = restart;
			return 1;
		}
		else
			TactAttackSpeed--;
		return 0;
	}
}
//-----------------------------------------------------------------------------------------------------------------------
void Monster::Defend(int AttackStrength)
{
	Condition = Condition - AttackStrength;
}
//-----------------------------------------------------------------------------------------------------------------------