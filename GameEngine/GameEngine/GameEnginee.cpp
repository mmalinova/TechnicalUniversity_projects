#include "stdafx.h"
#include <iostream>
#include "GameEnginee.h"

using namespace std;
extern int k, m, n;
GameEnginee *pointer;
//-----------------------------------------------------------------------------------------------------------------------
GameEnginee::~GameEnginee()
{
}
//-----------------------------------------------------------------------------------------------------------------------
int GameEnginee::Add(GameUnit &GU)
{
	if (CountUnits >= 100)
		return 0;
	else
	{
		Units[CountUnits] = &GU;
		CountUnits++;
		return 1;
	}
}
//-----------------------------------------------------------------------------------------------------------------------
int GameEnginee::Step()
{
	for (int i = 1; i <= 5; i++)
	{
		cout << "\n\t\tTact number:" << i << endl;
		for (int j = 0; j < CountUnits; j++)
			Units[j]->Move();
		//Print();                               //преместването е отразено в принта след атаката и то е абсолютно същото
		Clear();
		for (int j = 0; j < CountUnits; j++)
			Units[j]->Attack();
		Print();
	}
	return 1;
}
//-----------------------------------------------------------------------------------------------------------------------
void GameEnginee::Print()
{
	for (int i = 0; i < CountUnits; i++)
		Units[i]->Print();
	k = m = n = 1;
}
//-----------------------------------------------------------------------------------------------------------------------
void GameEnginee::Clear()
{
	int i;
	for (i = 0; i < CountUnits; ++i)
	{
		if (!Units[i]->GetCondition())
		{
			Units[i] = Units[i + 1];
			CountUnits--;
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------