// Exercise7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "descriptor.h"
#include "lexicalUnitt.h"
#include "hashTable.h"

using namespace std;

int lexicalUnit::newAddress = 0;     // инициализация на статична променлива
int lexicalUnit::newDescriptor = 1;  // инициализация на статична променлива

int isValid(char *type);
//--------------------------------------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	HashTable D;

	FILE* inFile;
	char buffer[50];
	char typ[20];
	char ident[20];
	errno_t err;

	err = fopen_s(&inFile, "C:\\Users\\malin\\Desktop\\Elly\\OOP\\LexicalUnit\\file.txt", "r");
	if (err != 0) {
		cout << "Unable to open file file.txt" << endl;
		exit(1);   // call system to stop
	}

	while (!feof(inFile)) {
		fgets(buffer, 49, inFile);
		int i = 0;
		while (buffer[i] != ' ') {
			typ[i] = buffer[i];
			i++;
		}
		typ[i] = '\0';
		i++;
		int j = 0;
		while (buffer[i] != ';') {
			ident[j] = buffer[i];
			i++;
			j++;
		}
		ident[j] = '\0';
		if (isValid(typ))
		{
			lexicalUnit lu(ident, typ);
			D.add(lu);
		}
	}

	D.print();
	D.del("a");
	cout << endl;
	D.print();
	cout << endl;
	fclose(inFile);
	return 0;
}
//--------------------------------------------------------------------------------------------------------
int isValid(char *type)
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