#include <iostream>
#include "Laptop.h"
#include "CPU.h"
#include "SSD.h"
#include "RAM.h"
#include "main.h"
using namespace std;

Laptop::Laptop()
{
	model = nullptr;
	color = nullptr;
	priceComponents = NULL;
	cpu;
	ssd;
	ram;
	incrStatic();
}
Laptop::Laptop(const char* userModel, const char* userColor, CPU userCpu, SSD userSsd, RAM userRam) :cpu(userCpu), ssd(userSsd), ram(userRam)
{
	model = new char[strlen(userModel) + 1];
	strcpy_s(model, strlen(userModel) + 1, userModel);

	color = new char[strlen(userColor) + 1];
	strcpy_s(color, strlen(userColor) + 1, userColor);
	sumPrice();
	incrStatic();
}
Laptop::~Laptop()
{
	//cout << "\nDestr." << endl;
	delete[]model;
	delete[]color;
}
Laptop::Laptop(const Laptop& point) :cpu(point.cpu), ssd(point.ssd), ram(point.ram)
{
	model = new char[strlen(point.model) + 1];
	strcpy_s(model, strlen(point.model) + 1, point.model);
	priceComponents = point.priceComponents;
	color = new char[strlen(point.color) + 1];
	strcpy_s(color, strlen(point.color) + 1, point.color);
	incrStatic();
}

void Laptop::input()
{
	char buff[30];

	delNullptr(model);
	delNullptr(color);

	cout << "\nEnter model: ";
	cin >> buff;
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);

	cout << "Enter color: ";
	cin >> buff;
	color = new char[strlen(buff) + 1];
	strcpy_s(color, strlen(buff) + 1, buff);

	cout << "\nCPU: " << endl;
	cpu.input();
	cout << "\nSSD: " << endl;
	ssd.input();
	cout << "\nRAM: " << endl;
	ram.input();
	sumPrice();
}
void Laptop::print()
{
	cout << "\tLaptop info: " << endl;
	cout << "Model: ";
	isValid(model);
	cout << "Total price of components: " << priceComponents << endl;
	cout << "Color: ";
	isValid(color);

	cout << "\n\tList of all components " << endl;
	cout << "\tCPU" << endl;
	cpu.print();
	cout << "\n\tSSD" << endl;
	ssd.print();
	cout << "\n\tRAM" << endl;
	ram.print();
}
void Laptop::printCPU()
{
	cout << "CPU:" << endl;
	cpu.print();
}
void Laptop::printSSD()
{
	cout << "\nSSD:" << endl;
	ssd.print();
}
void Laptop::printRAM()
{
	cout << "\nRAM:" << endl;
	ram.print();
}
void Laptop::sumPrice()
{
	priceComponents += cpu.getPrice();
	priceComponents += ssd.getPrice();
	priceComponents += ram.getPrice();
}
int Laptop::getStatic()
{
	return Laptop::s_count;
}
void Laptop::incrStatic()
{
	Laptop::s_count++;
}