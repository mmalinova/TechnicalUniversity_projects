#include "stdafx.h"
#include "GameUnit.h"
#include <iostream>
#include <float.h>
#include "GameEnginee.h"

using namespace std;
int k = 1;
extern GameEnginee *pointer;
//-----------------------------------------------------------------------------------------------------------------------
GameUnit::GameUnit()
{
	Condition = 1;
	MoveSpeed = 1;
	TactMoveSpeed = 5 - MoveSpeed;
	AttackSpeed = 1;
	TactAttackSpeed = 5 - AttackSpeed;
	Team = NULL;
	AttackRange = 0;
}
//-----------------------------------------------------------------------------------------------------------------------
GameUnit::~GameUnit()
{

}
//-----------------------------------------------------------------------------------------------------------------------
GameUnit::GameUnit(TPoint PositionInit, /*TPoint TargetInit,*/ int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int TeamInit, int AttackRangeInit)
{
	Position.x = PositionInit.x;
	Position.y = PositionInit.y;
	Target = MinDistance();
	Condition = ConditionInit;
	MoveSpeed = MoveSpeedInit;
	TactMoveSpeed = 5 - MoveSpeed;
	AttackSpeed = AttackSpeedInit;
	TactAttackSpeed = 5 - AttackSpeed;
	Team = TeamInit;
	AttackRange = AttackRangeInit;
}
//-----------------------------------------------------------------------------------------------------------------------
int GameUnit::Attack()
{
	int AttackStrength = (Condition / 20 + 1);
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
int GameUnit::Move()
{
	if (MoveSpeed <= 0 || Condition <= 0)
		return -1;
	else
	{
		int restart = TactMoveSpeed;
		if (!TactMoveSpeed)
		{
			if (abs(Position.x - MinDistance().x < 2))
				Position.x = MinDistance().x;
			if (Position.x > MinDistance().x)
				Position.x -= 2;
			else
				Position.x += 2;
			if (Position.y > MinDistance().y)
				Position.y--;
			else
				Position.y++;
			TactMoveSpeed = restart;
			return 1;
		}
		else
			TactMoveSpeed--;
		return 0;
	}
}
//-----------------------------------------------------------------------------------------------------------------------
void GameUnit::Print()
{
	if (k == 1)
		cout << "\n\tFirst Neutral:" << endl;
	else if (k == 2)
		cout << "\n\tSecond Neutral:" << endl;
	else if (k ==3)
		cout << "\n\tThird Neutral:" << endl;
	else
		cout << "\n\tFour Neutral:" << endl;
	cout << '(' << Position.x << ';' << Position.y << ')';
	if (Attack() == 1)
		cout << "Attack!";
	k++;
}
//-----------------------------------------------------------------------------------------------------------------------
void GameUnit::Defend(int AttackStrength)
{
	Condition = Condition - AttackStrength;
}
//-----------------------------------------------------------------------------------------------------------------------
TPoint GameUnit::MinDistance()
{
	double min = DBL_MAX;
	double dis = 0.0;
	for (int i = 0; i < pointer->CountUnits; i++)
	{
		if (Team != pointer->Units[i]->Team)
		{
			dis = sqrt((Position.x - pointer->Units[i]->Position.x) * (Position.x - pointer->Units[i]->Position.x) + (Position.y - pointer->Units[i]->Position.y) + (Position.y - pointer->Units[i]->Position.y));
			if (dis < min)
			{
				min = dis;
				Target.x = pointer->Units[i]->Position.x;
				Target.y = pointer->Units[i]->Position.y;
			}
		}
	}
	return Target;
}
//-----------------------------------------------------------------------------------------------------------------------
int GameUnit::GetCondition()
{
	return Condition;
}
//-----------------------------------------------------------------------------------------------------------------------
GameUnit &GameUnit::operator=(GameUnit &G)
{
	Position.x = G.Position.x;
	Position.y = G.Position.y;
	Target.x = G.Target.x;
	Target.y = G.Target.y;
	Condition = G.Condition;
	MoveSpeed = G.MoveSpeed;
	TactMoveSpeed = 5 - MoveSpeed;
	AttackSpeed = G.AttackSpeed;
	TactAttackSpeed = 5 - AttackSpeed;
	Team = G.Team;
	AttackRange = G.AttackRange;
	return *this;
}
//-----------------------------------------------------------------------------------------------------------------------