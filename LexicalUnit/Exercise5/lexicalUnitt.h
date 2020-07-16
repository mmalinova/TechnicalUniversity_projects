#pragma once

//--------------------------------------------------------------------------------------------------------
class lexicalUnit
{
	char identificator[20];
	char type[20];
	char descriptor[5];
	int address;
public:
	static int newAddress;        // статична променлива, указваща адреса, на който да се запише текущата единица
	static int newDescriptor;     // статична променлива, указваща текущия дескриптор
	lexicalUnit();
	lexicalUnit(char *pIdentificator, char *pType);
	lexicalUnit& operator=(lexicalUnit& lu);
	~lexicalUnit();
	int setAddress(char *type);  // метод, който задава адреса и генерира следващия свободен адрес,
	//според типа,който има тази лексическа единица
	void setDescriptor();         // метод, който задава дескриптора и генерира следващия
	char* getIdentificator();      // метод, който връща идентификатора
	void print();
	int isValid();
};
