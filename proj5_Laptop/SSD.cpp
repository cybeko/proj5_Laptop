#include "SSD.h"
#include "main.h"
#include <iostream>
using namespace std;

SSD::SSD()
{
	model = nullptr;
	price = NULL;
	capacity = NULL;
}
SSD::SSD(const char* userModel, double userPrice, unsigned int userCapacity)
{
	model = new char[strlen(userModel) + 1];
	strcpy_s(model, strlen(userModel) + 1, userModel);

	price = userPrice;
	capacity = userCapacity;
}
SSD::~SSD()
{
	delete[]model;
}
SSD::SSD(const SSD& point)
{
	model = new char[strlen(point.model) + 1];
	strcpy_s(model, strlen(point.model) + 1, point.model);

	price = point.price;
	capacity = point.capacity;
}

void SSD::input()
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
void SSD::print()
{
	cout << "Model: ";
	isValid(model);
	cout << "Price: " << price << endl;
	cout << "Capacity: " << capacity << endl;
}

char* SSD::getModel()
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
double SSD::getPrice()
{
	return price;
}
double SSD::getCapacity()
{
	return capacity;
}

void SSD::setModel(const char* value)
{
	delNullptr(model);
	model = new char[strlen(value) + 1];
	strcpy_s(model, strlen(value) + 1, value);
}
void SSD::setPrice(double value)
{
	price = value;
}
void SSD::setCapacity(unsigned int value)
{
	capacity = value;
}