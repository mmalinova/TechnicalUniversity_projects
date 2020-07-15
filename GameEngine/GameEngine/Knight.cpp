#include "stdafx.h"
#include "Knight.h"
#include <iostream>
#include "GameEnginee.h"

using namespace std;
int m = 1;
extern GameEnginee *pointer;
//-----------------------------------------------------------------------------------------------------------------------
Knight::Knight():GameUnit()
{
	Sword = 1;
	Armor = 1;
}
//-----------------------------------------------------------------------------------------------------------------------
Knight::~Knight()
{

}
//-----------------------------------------------------------------------------------------------------------------------
Knight::Knight(TPoint PositionInit, /*TPoint TargetInit,*/ int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int TeamInit, int AttackRangeInit, int SwordInit, int ArmorInit) :GameUnit(PositionInit, /*TargetInit,*/ ConditionInit, MoveSpeedInit, AttackSpeedInit, TeamInit, AttackRangeInit)
{
	Sword = SwordInit;
	Armor = ArmorInit;
}
//-----------------------------------------------------------------------------------------------------------------------
void Knight::Print()
{
	if (m == 1)
		cout << "\n\tFirst Knight:" << endl;
	else if (m == 2)
		cout << "\n\tSecond Knight:" << endl;
	else 
		cout << "\n\tThird Knight:" << endl;
	cout << '(' << Position.x << ';' <<Position.y << ')';
	if (Attack() == 1)
		cout << "Attack!";
	m++;
}
//-----------------------------------------------------------------------------------------------------------------------
int Knight::Attack()
{
	int AttackStrength = (Condition / 20 + 1) * (Sword / 2 + 1);
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
void Knight::Defend(int AttackStrength)
{
	Condition = Condition - (AttackStrength - Armor * 2);
}
//-----------------------------------------------------------------------------------------------------------------------