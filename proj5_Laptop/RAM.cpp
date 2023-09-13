#include "RAM.h"
#include "main.h"
#include <iostream>
using namespace std;

RAM::RAM()
{
	model = nullptr;
	price = NULL;
	capacity = NULL;
}
RAM::RAM(const char* userModel, double userPrice, unsigned int userCapacity)
{
	model = new char[strlen(userModel) + 1];
	strcpy_s(model, strlen(userModel) + 1, userModel);

	price = userPrice;
	capacity = userCapacity;
}
RAM::~RAM()
{
	delete[]model;
}
RAM::RAM(const RAM& point)
{
	model = new char[strlen(point.model) + 1];
	strcpy_s(model, strlen(point.model) + 1, point.model);

	price = point.price;
	capacity = point.capacity;
}

void RAM::input()
{
	char buff[30];

	delNullptr(model);

	cout << "Enter model: ";
	cin >> buff;
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);

	cout << "Enter price: ";
	cin >> price;

	cout << "Enter capacity: ";
	cin >> capacity;
}
void RAM::print()
{
	cout << "Model: ";
	isValid(model);

	cout << "Price: " << price << endl;
	cout << "Capacity: " << capacity << endl << "\n\n\n\n";
}

char* RAM::getModel()
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
double RAM::getPrice()
{
	return price;
}
double RAM::getCapacity()
{
	return capacity;
}

void RAM::setModel(const char* value)
{
	delNullptr(model);
	model = new char[strlen(value) + 1];
	strcpy_s(model, strlen(value) + 1, value);
}
void RAM::setPrice(double value)
{
	price = value;
}
void RAM::setCapacity(unsigned int value)
{
	capacity = value;
}