#pragma once
class RAM
{
private:
	char* model;
	double price;
	unsigned int capacity;
public:
	RAM();
	RAM(const char*, double, unsigned int);
	~RAM();
	RAM(const RAM&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getCapacity();

	void setModel(const char*);
	void setPrice(double);
	void setCapacity(unsigned int);
};
