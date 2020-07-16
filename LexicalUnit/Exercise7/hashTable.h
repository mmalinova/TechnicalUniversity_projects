#pragma once
#include "lexicalUnitt.h"

#pragma once

//--------------------------------------------------------------------------------------------------------
class HashTable
{
	lexicalUnit table[128];
	int number;
public:
	HashTable();
	~HashTable();
	int hashFunction(char *pIdentificator);
	int search(char  *pIdentificator);      
	int add(lexicalUnit &lu);              // връща 1, при успешно добавяне и -1 в противен случай
	int del(char *pIdentificator);         // връща 1, при успешно изтриване и -1 в противен случай
	void print();
};