#include "stdafx.h"
#include "dihotTablee.h"
#include <string.h>

//--------------------------------------------------------------------------------------------------------
DihotTable::DihotTable()
{
	number = 0;
}
//--------------------------------------------------------------------------------------------------------
DihotTable::~DihotTable()
{
}
//--------------------------------------------------------------------------------------------------------
int DihotTable::add(lexicalUnit &lu)
{
	int i, j;
	if (number >= 100)
		return 0;
	i = search(lu.getIdentificator());
	if (i > 0)
		return 0;
	else {
		i = -i;
		for (j = number; j > i; j--)
			table[j] = table[j - 1];
		table[j] = lu;
		number++;
		return 1;
	}
}
//--------------------------------------------------------------------------------------------------------
int DihotTable::del(char *pIdentificator)
{
	if (number == 0)
		return 0;
	if (search(pIdentificator) >= 0)
	{
		for (int i = search(pIdentificator); i < number - 1; i++)
		{
			table[i] = table[i + 1];
		}
		number--;
		return 1;
	}
	return 0;
}
//--------------------------------------------------------------------------------------------------------
int DihotTable::search(char *pIdentificator)
{
	int low, high, middle;
	low = 0;
	high = number;
	while (low <= high)
	{
		middle = low + (high - low) / 2;
		if (strcmp(pIdentificator, table[middle].getIdentificator()) < 0)
			high = middle - 1;
		else if (strcmp(pIdentificator, table[middle].getIdentificator()) > 0)
			low = middle + 1;
		else
			return middle;
	}
	return -middle;
}
//--------------------------------------------------------------------------------------------------------
void DihotTable::print()
{
	for (int i = 0; i < number; i++)
		table[i].print();
}
//--------------------------------------------------------------------------------------------------------