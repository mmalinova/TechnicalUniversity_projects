#include "stdafx.h"
#include "descriptor.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------------------------------
descriptors::descriptors()
{
	number = 0;
}
//--------------------------------------------------------------------------------------------------------
descriptors::~descriptors()
{
}
//--------------------------------------------------------------------------------------------------------
int descriptors::add(lexicalUnit &lu)
{
	if (number >= 100)
		return 0;
	if (!lu.isValid())
		return 0;
	if (search(lu.getIdentificator()) >= 0)
		return 0;
	else {
		table[number] = lu;
		number++;
		return 1;
	}
}
//--------------------------------------------------------------------------------------------------------
int descriptors::del(char *pIdentificator)
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
int descriptors::search(char  *pIdentificator)
{
	for (int i = 0; i < number; i++)
	{
		if (strcmp(table[i].getIdentificator(), pIdentificator) == 0)
			return i;
	}
	return -1;
}
//--------------------------------------------------------------------------------------------------------
void descriptors::print()
{
	for (int i = 0; i < number; i++)
		table[i].print();
}
//--------------------------------------------------------------------------------------------------------