#pragma once

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class MovieTheater
{
	int places[11][17];
	int numberSellTickets;
public:
	MovieTheater();
	~MovieTheater();
	void Reserve();
};