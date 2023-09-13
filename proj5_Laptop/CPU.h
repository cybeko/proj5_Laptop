#pragma once
class CPU
{
private:
	char* model;
	double price;
	int cores;
public:
	CPU();
	CPU(const char*, double, int);
	~CPU();
	CPU(const CPU&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getCores();

	void setModel(const char*);
	void setPrice(double);
	void setCores(int);
};