#include "stdafx.h"
#include "StudentTicket.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
StudentTicket::StudentTicket():Ticket()
{
	numberOfPeople = 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
StudentTicket::~StudentTicket()
{

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int StudentTicket::Sell()
{
	price *= 0.80;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------