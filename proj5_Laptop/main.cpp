#include <iostream>
#include "CPU.h"
#include "RAM.h"
#include "SSD.h"
#include "main.h"
#include "Laptop.h"
using namespace std;
unsigned int Laptop::s_count = 0;

int main()
{
	CPU cpu("Intel Core i5-10400F", 450, 4);
	SSD ssd("Kingston FURY Renegade", 300, 850);
	RAM ram("Corsair DDR4-3200", 280, 12600);
	Laptop A("Dell Latitude 3520", "Black", cpu, ssd, ram);
	A.print();


	Laptop copyA = A;
	copyA.print();

	Laptop B;
	B.input();
	B.print();

	cout << "\nLaptops total: " << Laptop::getStatic();
}

void isValid(char* var)
{
	if (var == nullptr)
	{
		cout << "Unspecified" << endl;
	}
	else
	{
		cout << var << endl;
	}
}
void delNullptr(char* ptr)
{
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
}