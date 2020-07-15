// GameEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GameEnginee.h"
#include "GameUnit.h"
#include "Knight.h"
#include "Monster.h"

using namespace std;
extern GameEnginee *pointer;
//-----------------------------------------------------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	GameEnginee GE;
	pointer = &GE;

	TPoint pK;       // Knight
	pK.x = 0;
	pK.y = 0;
	
	TPoint pM;       // Monster
	pM.x = 13;
	pM.y = 6;

	TPoint pN1;       // Neutral
	pN1.x = 5;
	pN1.y = 2;
	TPoint pN2;       
	pN2.x = 2;
	pN2.y = 5;
	TPoint pN3;       
	pN3.x = 8;
	pN3.y = 4;
	TPoint pN4;
	pN4.x = 11;
	pN4.y = 1;

	Knight GU1(pK, 90, 2, 0, 1, 6, 5, 6);
	Knight GU2(pK, 80, 3, 4, 1, 3, 1, 5);
	Knight GU3(pK, 75, 5, 5, 1, 4, 4, 4);

	Monster GU4(pM, 50, 2, 5, 2, 6, 7, 7);
	Monster GU5(pM, 60, 1, 3, 2, 5, 9, 10);
	Monster GU6(pM, 40, 1, 0, 2, 5, 3, 6);

	GameUnit GU7(pN1, 55, 5, 5, 1, 6);
	GameUnit GU8(pN2, 70, 1, 0, 1, 5);
	GameUnit GU9(pN3, 65, 3, 3, 2, 6);
	GameUnit GU10(pN4, 99, 4, 4, 2, 5);

	GE.Add(GU1);
	GE.Add(GU2);
	GE.Add(GU3);
	GE.Add(GU4);
	GE.Add(GU5);
	GE.Add(GU6);
	GE.Add(GU7);
	GE.Add(GU8);
	GE.Add(GU9);
	GE.Add(GU10);

	GE.Step();

	//GE.Print();

	return 0;
}