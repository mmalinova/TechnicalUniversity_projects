// Ex3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "iostream"

using namespace std;

struct Client
{
	char Type[20];
	char IBAN[24];
	double Suma;
};
//---------------------------------------------------------------------------
class ClientBank
{
	char Name[20];
	char Fam[20];
	int CountForOnePerson;
	int ClientNum;
	Client Info[10];
public:
	ClientBank(void) { CountForOnePerson = ClientNum = 0; }
	ClientBank(char *AName, char *AFam, int ACountForOnePerson, Client info);
	ClientBank(ClientBank &cl);
	int Add(Client info);
	int Remove(char *IBAN);
	Client *Search(char *IBAN);
	int AddSuma(double Suma, char *IBAN);
	double AllSuma(void);
	void Print(void);
	unsigned long ReadId(){ return ClientNum; };
};
class Bank {
	ClientBank *Table;
	int TableEnd;
	int Size;
public:
	Bank(void) { TableEnd = 0; Size = 3; Table = new ClientBank[Size]; }
	Bank(int ATableEnd);
	~Bank(void);
	int Append(ClientBank &Person);
	int Delete(int ClientNum);
	int PrintClients();
};
//---------------------------------------------------------------------------
Bank::Bank(int ATableEnd) {
	Table = new  ClientBank[ATableEnd];
	TableEnd = 0;
	Size = ATableEnd;
}
//---------------------------------------------------------------------------
Bank:: ~Bank(void) {
	delete[] Table;
	Size = TableEnd = 0;
}
//---------------------------------------------------------------------------
int Bank::Append(ClientBank &Person){
	if (TableEnd == Size){
		ClientBank *temp = new ClientBank[Size * 2];
		memcpy(temp, Table, sizeof(ClientBank)*Size);
		delete[] Table;
		Table = temp;
		Size *= 2;
	}
	memcpy(&Table[TableEnd], &Person, sizeof(ClientBank));
	TableEnd++;
	return 1;
}
//---------------------------------------------------------------------------
int Bank::Delete(int ClientNum){
	for (int i = 0; i < TableEnd; i++){
		if (Table[i].ReadId() == ClientNum){
			while (i < TableEnd - 1){
				Table[i] = Table[i + 1];
				i++;
			}
			TableEnd--;
			return 1;
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
int Bank::PrintClients(){
	for (int i = 0; i < TableEnd; i++)
		Table[i].Print();
	return 1;
}
//---------------------------------------------------------------------------
ClientBank::ClientBank(char *AName, char *AFam, int AClientNum, Client info){
	strcpy_s(Name, AName);
	strcpy_s(Fam, AFam);
	ClientNum = AClientNum;
	CountForOnePerson = 0;
	strcpy_s(Info[CountForOnePerson].Type, info.Type);
	strcpy_s(Info[CountForOnePerson].IBAN, info.IBAN);
	Info[CountForOnePerson].Suma = info.Suma;
	CountForOnePerson++;
}
//---------------------------------------------------------------------------
ClientBank::ClientBank(ClientBank &cl){
	strcpy_s(Name, cl.Name);
	strcpy_s(Fam, cl.Fam);
	CountForOnePerson = cl.CountForOnePerson;
	ClientNum = cl.ClientNum;
	for (int i = 0; i < CountForOnePerson; i++){
		strcpy_s(Info[i].Type, cl.Info[i].Type);
		strcpy_s(Info[i].IBAN, cl.Info[i].IBAN);
		Info[i].Suma = cl.Info[i].Suma;
	}
}
//---------------------------------------------------------------------------
int ClientBank::Add(Client info){
	if (CountForOnePerson >= 10) return 0;
	strcpy_s(Info[CountForOnePerson].Type, info.Type);
	strcpy_s(Info[CountForOnePerson].IBAN, info.IBAN);
	Info[CountForOnePerson].Suma = info.Suma;
	CountForOnePerson++;
	return 1;
}
//---------------------------------------------------------------------------
int ClientBank::Remove(char *IBAN){
	Client *p = Search(IBAN);
	if (p == NULL)
		return 0;
	for (int i = 0; i < CountForOnePerson; i++){
		if (!strcmp(Info[i].IBAN, p->IBAN)){
			if (p->Suma < 0)
				return 0;
			while (i <= CountForOnePerson - 1)
				Info[i++] = Info[i + 1];
			CountForOnePerson--;
			cout << "Account - deleted!\n";
			return 1;
		}
	}
	return NULL;
}
//---------------------------------------------------------------------------
Client *ClientBank::Search(char *IBAN){
	for (int i = 0; i < CountForOnePerson; i++){
		if (!strcmp(Info[i].IBAN, IBAN))
			return &Info[i];
	}
	return NULL;
}
//---------------------------------------------------------------------------
int ClientBank::AddSuma(double Suma, char *IBAN){
	Client *p = Search(IBAN);
	if (p == NULL)
		return NULL;
	p->Suma += Suma;
	return 1;
}
//---------------------------------------------------------------------------
double ClientBank::AllSuma(void){
	double Sum = 0.0;
	for (int i = 0; i < CountForOnePerson; i++)
		Sum += Info[i].Suma;
	return Sum;
}
//---------------------------------------------------------------------------
void ClientBank::Print(void){
	cout << "\tName: " << Name << "\tFam: " << Fam << endl;
	cout << "Number of accounts: " << CountForOnePerson << endl;
	for (int i = 0; i < CountForOnePerson; i++){
		cout << "Account: " << i << endl;
		cout << "Type: " << Info[i].Type << endl;
		cout << "IBAN: " << Info[i].IBAN << endl;
		cout << "Sum: " << Info[i].Suma << endl;
	}
	cout << endl;
}
//---------------------------------------------------------------------------
int main(void)
{
	Bank b(1);
	Client info1 = { "Debitna", "NCIE53022", 1536 };
	Client info2 = { "Kreditna", "KOFEK343", 3661 };
	Client info3 = { "Debitna", "KFPO53443", 4293 };
	Client info4 = { "Debitna", "542DJIE", 493 };
	Client info5 = { "Kreditna", "54225JIE", 429 };

	ClientBank c[3];
	c[0] = ClientBank("Peter", "Petrov", 11111, info1);
	c[1] = ClientBank("Harry", "Styles", 22222, info2);
	c[2] = ClientBank("Little", "Mix", 33333, info3);

	c[0].Add(info4);
	c[1].Add(info4);

	b.Append(c[0]);
	b.Append(c[1]);
	b.Append(c[2]);

	b.PrintClients();

	if (b.Delete(11111))
		b.PrintClients();
	else cout << "No Client\n";

	if (b.Delete(43233))
		b.PrintClients();
	else cout << "No Client\n";

	return 0;
}
//---------------------------------------------------------------------------



