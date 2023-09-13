#pragma once
#include "CPU.h"
#include "SSD.h"
#include "RAM.h"
class Laptop
{
private:
	char* model;
	double priceComponents;
	char* color;
	CPU cpu;
	SSD ssd;
	RAM ram;
	static unsigned int s_count;
public:
	Laptop();
	Laptop(const char*, const char*, CPU, SSD, RAM);
	~Laptop();
	Laptop(const Laptop&);

	void input();
	void print();
	void printCPU();
	void printSSD();
	void printRAM();
	void sumPrice();

	static int getStatic();
	static void incrStatic();
};