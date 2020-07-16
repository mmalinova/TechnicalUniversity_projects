#pragma once

//------------------------------------------------------------------------------------------------
class Estate
{
protected:
	char address[50];
	char owner[50];
	double price;
	float area;
public:
	Estate();
	Estate(char *paddress, char *powner, double pprice, float parea);
	~Estate();
	Estate& operator=(Estate &pEs);
	char *getAddress();
	double getPrice();
	virtual void Print();
	friend int cf(void *el1, void *el2);
};