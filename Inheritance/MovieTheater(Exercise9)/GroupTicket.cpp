#include "stdafx.h"
#include "GroupTicket.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GroupTicket::GroupTicket():Ticket()
{

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GroupTicket::~GroupTicket()
{

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int GroupTicket::Sell()
{
	if (numberOfPeople > 10 && numberOfPeople <= 20)
		price *= 0.90;
	else if (numberOfPeople > 20)
		price *= 0.80;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------