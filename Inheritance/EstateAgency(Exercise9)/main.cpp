// EstateAgency(Exercise9).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "Agency.h"
#include "Apartament.h"
#include "Estate.h"
#include "House.h"
#include "Parcel.h"
#include "BubleSort.h"

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	Agency *Ag = new Agency; /*("The best real estate agency");
	char agencyName[50];
	strcpy_s(agencyName, Ag->name);
	cout  << agencyName;
	*/
	Estate *Es = new Estate("Sofia, bul.Osvobojdenie", "Maria Spasova", 10000, 150);
	Ag->Add(*Es);
	Apartament *Ap = new Apartament(3, 4, "Plovdiv, bul.Sankt Petenburg", "Vasil Vasilev", 100000, 200);
	Ag->Add(*Ap);
	House *H = new House(4, 3, 100, "Plovdiv, bul.Maritza", "Milka Atanasova", 50000, 100);
	Ag->Add(*H);
	Parcel *P = new Parcel(true, true, true, "Sofia, bul.Bulgaria", "Atanas Simeonov", 10000, 150);
	Ag->Add(*P);
	
	Apartament Apar(3, 4, "Plovdiv, bul.Sankt Petenburg", "Vasil Vasilev", 100000, 200);
	House Ho(4, 3, 100, "Plovdiv, bul.Maritza", "Milka Atanasova", 50000, 100);
	Parcel Pa(true, true, true, "Sofia, bul.Bulgaria", "Atanas Simeonov", 10000, 150);
	Estate Est("Sofia, bul.Osvobojdenie", "Maria Spasova", 10000, 150);

	Ag->Print();
	cout << endl;

	char type[20];
	cout << "Enter the type of estate you want -> ";
	cin >> type;

	if (strcmp(type, "Apartament") == 0)
	{
		Es = &Apar;
		Es->Print();
	}
	else if (strcmp(type, "House") == 0)
	{
		Es = &Ho;
		Es->Print();
	}
	else if (strcmp(type, "Parcel") == 0)
	{
		Es = &Pa;
		Es->Print();
	}
	else if (strcmp(type, "Estate") == 0)
	{
		Es = &Est;
		Es->Print();
	}
	else
		cout << "Sorry, we don't have that type of estate!" << endl;

	double minPrice, maxPrice;
	cout << endl;
	cout << "Enter min price: ";
	cin >> minPrice;
	cout << "Enter max price: ";
	cin >> maxPrice;

	cout << "\n\tEstates between\t" << minPrice << " - " << maxPrice << " is/are:\n" << endl;
	Ag->Search(minPrice, maxPrice);

	Ag->Remove("Sofia, bul.Osvobojdenie");
	cout << endl;

	Ag->Print();
	cout << endl;

	delete Ag;
	//delete Es;
	delete Ap;
	delete H;
	delete P;
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//void BubleSort(void *base, int nrec, int reclen, int(*cmp)(byte *el1, byte *el2))