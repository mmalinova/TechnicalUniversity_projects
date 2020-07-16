#pragma once
#include "Film.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Ticket
{
protected:
	int numberOfRow;
	int place;
	char date[20];
	Film *film;
	double price;
public:
	Ticket();
	~Ticket();
};