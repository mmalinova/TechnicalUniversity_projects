#pragma once
#include "Ticket.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class StudentTicket:public Ticket
{
	int numberOfPeople;
public:
	StudentTicket();
	~StudentTicket();
	int Sell();
};