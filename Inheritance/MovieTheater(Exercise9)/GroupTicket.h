#pragma once
#include "Ticket.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class GroupTicket:public Ticket
{
	int numberOfPeople;
public:
	GroupTicket();
	~GroupTicket();
	int Sell();
};