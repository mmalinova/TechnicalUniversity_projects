#include "stdafx.h"
#include "hashTable.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------------------
HashTable::HashTable()
{
	number = 0;
}
//--------------------------------------------------------------------------------------------------------
HashTable::~HashTable()
{
}
//--------------------------------------------------------------------------------------------------------
int HashTable::hashFunction(char *pIdentificator)
{
	int index = 0, sum = 0;
	int i = 0, j = 0;
	while (pIdentificator[i] != '\0')
	{
		j = int(pIdentificator[i]);
		sum += j;
		i++;
	}
	index = sum & 127;
	return index;
}
//--------------------------------------------------------------------------------------------------------
int HashTable::search(char  *pIdentificator)
{
	char m;
	int index = hashFunction(pIdentificator);
	int i;
	for (i = index;; i++)
	{
		if (strcmp(table[i].getIdentificator(), pIdentificator) == 0)
			return i;                  //връщаме позицията, на която я има лекс. единица
		if (strcmp(table[i].getIdentificator(), "") == 0)
			return -i;                //единицата я няма
		if (i == 128)
			i = 0;
		if (i = index - 1)
			return 1001;
	}
}
//--------------------------------------------------------------------------------------------------------
int HashTable::add(lexicalUnit &lu)
{
	int index = search(lu.getIdentificator());
	if (index <= 0)
	{
		index = index * -1;
		table[index] = lu;
		number++;
		return 1;
	}
	else
		return 0;
}
//--------------------------------------------------------------------------------------------------------
int HashTable::del(char *pIdentificator)
{
	if (number == 0)
		return 0;
	int index = search(pIdentificator);
	if (index < 0)
		return 0;
	lexicalUnit p("", "");
	table[index] = p;
	number--;
	return 1;
}
//--------------------------------------------------------------------------------------------------------
void HashTable::print()
{
	for (int i = 0; i < 128; i++)
	{
		cout << i << "\t";
		table[i].print();
	}
}
//--------------------------------------------------------------------------------------------------------