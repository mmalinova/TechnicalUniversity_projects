// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EOT -1
#define BOT -1

struct BelRow
{
	char Name[12];
	char Fam[15];
	unsigned long Tel;
};
class Bel
{
	BelRow Table[100];
	int TableEnd;
	int CurrentRecord;
public:
	Bel(void) { TableEnd = 0; }
	int Append(char *Name, char *Fam, unsigned long Tel);
	int Append(BelRow *ARow);
	BelRow *FindRowByName(char *Name);
	void First(void) { CurrentRecord = 0; }
	int Next(void);
	int Prev(void);
	void Last(void) { CurrentRecord = TableEnd - 1; }
	BelRow *Get(void);
};
int Bel::Append(char *Name, char *Fam, unsigned long Tel)
{
	if (TableEnd >= 100) return 0;
	strcpy_s(Table[TableEnd].Name, Name);
	strcpy_s(Table[TableEnd].Fam, Fam);
	Table[TableEnd].Tel = Tel;
	TableEnd++;
	return 1;
}
int Bel::Append(BelRow *ARow)
{
	if (TableEnd >= 100) return 0;
	memcpy(&Table[TableEnd], ARow, sizeof(BelRow));
	TableEnd++;
	return 1;
}
BelRow *Bel::FindRowByName(char *Name)
{
	for (int i = 0; i < TableEnd; i++)
	if (!strcmp(Table[i].Name, Name)) return &Table[i];
	return NULL;
}
int Bel::Next(void)
{
	int NextRecord = CurrentRecord++;
	if (TableEnd >= 100 - 1) return EOT;
	return NextRecord;
}
int Bel::Prev(void)
{
	int PrevRecord = CurrentRecord--;
	if (CurrentRecord <= 0) return BOT;
	return PrevRecord;
}
BelRow *Bel::Get(void)
{
	return &Table[CurrentRecord];
}
void printBelRow(BelRow *ARow)
{
	printf("\nName = %s, Fam = %s, Tel = %lu\n", ARow->Name, ARow->Fam, ARow->Tel);
}
int main(void)
{
	int x, y;
	Bel Tef1;
	Tef1.Append("Ivan", "Petrov", 342123L);
	Tef1.Append("Stefan", "Stojanov", 547323L);
	Tef1.Append("Milena", "Angelova", 126598L);
	Tef1.Append("Georgi", "Georgiev", 447619L);
	Tef1.Append("Minka", "Hadjieva", 983234L);

	printf("\tFirst is:");
	Tef1.First();
	Tef1.Get();
	printBelRow(Tef1.Get());
	for (int i = 1; i < 5; i++)
	{
		printf("\tNext is:");
		Tef1.Next();
		printBelRow(Tef1.Get());
	}
	printf("\tLast is:");
	Tef1.Last();
	Tef1.Get();
	printBelRow(Tef1.Get());
	printf("\tPrevious is:");
	Tef1.Prev();
	Tef1.Get();
	printBelRow(Tef1.Get());

	return 0;
}
