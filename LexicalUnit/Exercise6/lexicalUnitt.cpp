#include "stdafx.h"
#include "lexicalUnitt.h"
#include <string.h>
#include <iostream>

using namespace std;

lexicalUnit::lexicalUnit()
{
	identificator[0] = 0;
	type[0] = 0;
	descriptor[0] = 0;
	address = 0;
}
//--------------------------------------------------------------------------------------------------------
lexicalUnit::~lexicalUnit()
{
}
//--------------------------------------------------------------------------------------------------------
int lexicalUnit::setAddress(char *type)
{
	address = newAddress; //полето на класа получава стойността на статичната променлива, след което тя се променя според типа
	int size = 0;
	if (strcmp(type, "int") == 0)
		size = 2;
	else if (strcmp(type, "char") == 0)
		size = 1;
	else if (strcmp(type, "float") == 0)
		size = 4;
	else if (strcmp(type, "double") == 0)
		size = 8;

	newAddress += size;
	return newAddress;
}
//--------------------------------------------------------------------------------------------------------
void lexicalUnit::setDescriptor()
{
	sprintf_s(descriptor, "V%d", newDescriptor);
	newDescriptor++;
}
//--------------------------------------------------------------------------------------------------------
lexicalUnit::lexicalUnit(char *pIdentificator, char *pType)
{
	strcpy_s(identificator, pIdentificator);
	strcpy_s(type, pType);
	setDescriptor();
	setAddress(pType);
}
//--------------------------------------------------------------------------------------------------------
lexicalUnit &lexicalUnit::operator=(lexicalUnit& lu)
{
	strcpy_s(identificator, lu.identificator);
	strcpy_s(type, lu.type);
	strcpy_s(descriptor, lu.descriptor);
	address = lu.address;

	return *this;
}
//--------------------------------------------------------------------------------------------------------
char *lexicalUnit::getIdentificator()
{
	return identificator;
}
//--------------------------------------------------------------------------------------------------------
void lexicalUnit::print()
{
	cout << identificator << "\t" << type << "\t" << descriptor << "\t" << address << endl;
}
//--------------------------------------------------------------------------------------------------------
int lexicalUnit::isValid()
{
	if (strcmp(type, "int") == 0)
		return 1;
	else if (strcmp(type, "char") == 0)
		return 1;
	else if (strcmp(type, "float") == 0)
		return 1;
	else if (strcmp(type, "double") == 0)
		return 1;
	else
		return 0;
}
//--------------------------------------------------------------------------------------------------------