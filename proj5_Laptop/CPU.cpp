#include "CPU.h"
#include "main.h"
#include <iostream>
using namespace std;

CPU::CPU()
{
	model = nullptr;
	price = NULL;
	cores = NULL;
}
CPU::CPU(const char* userModel, double userPrice, int userCores)
{
	model = new char[strlen(userModel) + 1];
	strcpy_s(model, strlen(userModel) + 1, userModel);

	price = userPrice;
	cores = userCores;
}
CPU::~CPU()
{
	delete[]model;
}
CPU::CPU(const CPU& point)
{
	model = new char[strlen(point.model) + 1];
	strcpy_s(model, strlen(point.model) + 1, point.model);

	price = point.price;
	cores = point.cores;
}

void CPU::input()
{
	char buff[30];

	delNullptr(model);

	cout << "Enter model: ";
	cin >> buff;
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);

	cout << "Enter price: ";
	cin >> price;

	cout << "Enter cores: ";
	cin >> cores;
}
void CPU::print()
{
	cout << "Model: ";
	isValid(model);

	cout << "Price: " << price << endl;
	cout << "Cores: " << cores << endl;
}

char* CPU::getModel()
{
	if (model == nullptr)
	{
		model = new char[strlen("empty") + 1];
		strcpy_s(model, strlen("empty") + 1, "empty");
		return model;
	}
	else
	{
		return model;
	}
}
double CPU::getPrice()
{
	return price;
}
double CPU::getCores()
{
	return cores;
}

void CPU::setModel(const char* value)
{
	delNullptr(model);
	model = new char[strlen(value) + 1];
	strcpy_s(model, strlen(value) + 1, value);
}
void CPU::setPrice(double value)
{
	price = value;
}
void CPU::setCores(int value)
{
	cores = value;
}