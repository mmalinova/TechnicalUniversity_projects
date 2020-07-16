#pragma once
#include "lexicalUnitt.h"

//--------------------------------------------------------------------------------------------------------
class descriptors
{
	lexicalUnit table[100];
	int number;                        //брой лексически единици
public:
	descriptors();
	~descriptors();
	int add(lexicalUnit &lu);          // връща 1, при успешно добавяне и 0 в противен случай
	int del(char *pIdentificator);     // връща 1, при успешно изтриване и 0 в противен случай
	int search(char  *pIdentificator); // връща позицията на лексическата единица в масива или -1 в противен случай
	void print();
};