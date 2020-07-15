#pragma once

//-----------------------------------------------------------------------------------------------------------------------
class TPoint
{
public:
	int x, y;
	TPoint() { x = 0, y = 0; }
	TPoint(int xi, int yi) { x = xi, y = yi; }
};
//-----------------------------------------------------------------------------------------------------------------------
class GameUnit
{
protected:
	TPoint Target;                        //наредена двойка координати оказваща позицията към която ще се придвижва игралната единица
	int Condition;                        //от 1 до 100. Ако стане 0, то единицата "умира"
	int MoveSpeed;                        //от 1 до 5. На колко такта на часовника да прави едно движение
	int TactMoveSpeed = 5 - MoveSpeed;    //Броят тактове, които трябва да се пропуснат и да се направи една крачка
	int AttackSpeed;                      //от 1 до 5. На колко такта на часовника да атакува
	int TactAttackSpeed = 5 - AttackSpeed;//Броят тактове, които трябва да се пропуснат и да се направи една атака
	int AttackRange;                      //Полетата, които игралната единица може да достигне при атака
public:
	TPoint Position;                      //наредена двойка координати оказваща текущата позиция на игралната единиа
	int Team;                             //Номер на отбор
	GameUnit();
	GameUnit(TPoint PositionInit, /*TPoint TargetInit,*/ int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int TeamInit, int AttackRangeInit);
	~GameUnit();
    virtual int Attack();
	virtual int Move();
	virtual void Print();
	virtual void Defend(int AttackStrength);
	TPoint MinDistance();
	int GetCondition();
	GameUnit& operator=(GameUnit &G);
};