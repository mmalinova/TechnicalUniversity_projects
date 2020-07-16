#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "SuperLongInt.h"

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt::SuperLongInt(void)
{
	for (int i = 0; i < 100; i++)
		Number[i] = '0' - 48;
	Len = 0;
	OverflowFlag = '0' - 48;
	NegativeFlag = '0' - 48;
}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt::~SuperLongInt()
{

}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt::SuperLongInt(long int a)
{
	if (a < 0)
	{
		NegativeFlag = '1' - 48;
		a = abs(a);
	} else
		NegativeFlag = '0' - 48;
	char *buffer = &ToString(a);
	Len = strnlen(buffer, 100);
	if (Len < 100)
	{
		for (int i = 0; i < Len; i++)
		{
			Number[i] = a % 10;
			a /= 10;
		}
	}
	OverflowFlag = '0' - 48;
	Number[Len] = '\0';
	for (int k = Len + 1; k <= 100; k++)
	{
		Number[k] = '0' - 48;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt::SuperLongInt(char *c)
{
	int k, i, m;
	if (c[0] == '-')
	{
		NegativeFlag = '1' - 48;
		k = 1;
	} else
	{
		NegativeFlag = '0' - 48;
		k = 0;
	}
	Len = strlen(c);
	if (Len < 100)
	{
		for (i = (Len - 1) - k, m = k; i >= 0; i--, m++)
		{
			Number[i] = c[m] - 48;
		}
	}
	Number[Len - k] = '\0';
	OverflowFlag = '0' - 48;
	for (int n = (Len - k) + 1; n <= 100; n++)
	{
		Number[n] = '0' - 48;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt::SuperLongInt(SuperLongInt &S)
{
	Len = S.Len;
	for (int i = 0; i < Len; i++)
		Number[i] = S.Number[i];
	OverflowFlag = S.OverflowFlag;
	NegativeFlag = S.NegativeFlag;
}
//-----------------------------------------------------------------------------------------------------------------------------
char &SuperLongInt::ToString(long int a)
{
	char buffer[100];
	_itoa_s(a, buffer, 10);
	return *buffer;
}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt &SuperLongInt::operator=(SuperLongInt &si)
{
	Len = si.Len;
	for (int i = 0; i < Len; i++)
	{
		Number[i] = si.Number[i];
	}
	OverflowFlag = si.OverflowFlag;
	NegativeFlag = si.NegativeFlag;
	return *this;
}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt SuperLongInt::operator+(SuperLongInt si)
{
	int EdnoNaum = 0;
	SuperLongInt Temp;
	if (Len >= si.Len)
		Temp.Len = Len;
	else
		Temp.Len = si.Len;
	for (int i = 0; i < Temp.Len; i++)
	{
		Temp.Number[i] = EdnoNaum + Number[i] + si.Number[i];
		if (Temp.Number[i] >= 10)
		{
			EdnoNaum = 1;
			Temp.Number[i] %= 10;
		}
		else
			EdnoNaum = 0;
	}
	if (EdnoNaum)
	{
		OverflowFlag = '1' - 48;
		Temp.Number[Temp.Len] = 1;
		Temp.Len++;
	}
	NegativeFlag = '0' - 48;
	return Temp;
}
//-----------------------------------------------------------------------------------------------------------------------------
SuperLongInt SuperLongInt::operator-(SuperLongInt si)
{
	int VzimamEdno = 0;
	SuperLongInt Temp;
	if (Len >= si.Len)
	{
		Temp.Len = Len;
		for (int i = 0; i < Temp.Len; i++)
		{
			if (Number[i] >= si.Number[i])
				Temp.Number[i] = Number[i] - si.Number[i];
			else
			{
				for (int j = Number[i + 1]; ; j++)
				{
					if (Number[j] == 0)
					{
						Number[j] = 9;
					}
					else
					{
						Number[j] -= 1;
						Number[i] += 10;
						Temp.Number[i] = Number[i] - si.Number[i];
					}
				}
			}
		}
		if (Temp.Number[Temp.Len - 1] == 0)
		{
			Temp.Len--;
		}
	}
	else
	{
		Temp.Len = si.Len;
		for (int i = 0; i < Temp.Len; i++)
		{
			if (Number[i] >= si.Number[i])
				Temp.Number[i] = Number[i] - si.Number[i];
			else
			{
				for (int j = Number[i + 1];; j++)
				{
					if (Number[j] == 0)
					{
						Number[j] = 9;
					}
					else
					{
						Number[j] -= 1;
						Number[i] += 10;
						Temp.Number[i] = Number[i] - si.Number[i];
					}
				}
			}
		}
		if (Temp.Number[Temp.Len - 1] == 0)
		{
			Temp.Len--;
		}
	}
	NegativeFlag = '0' - 48;
	return Temp;
}
//-----------------------------------------------------------------------------------------------------------------------------
void SuperLongInt::Print(std::ostream &os)
{
	int i;
	for (i = Len - 1; i >= 0; i--)
	{
		Number[i] = Number[i] + 48;
		os << Number[i];
	}
}
//-----------------------------------------------------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream& o, SuperLongInt & r)
{
	r.Print(o);
	return o;
}
//-----------------------------------------------------------------------------------------------------------------------------
std::istream &operator>>(std::istream& i, SuperLongInt & r)
{
	i >> r.Number;
	//r.Set();
	return i;
}