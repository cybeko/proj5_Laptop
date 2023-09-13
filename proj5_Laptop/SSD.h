#pragma once
class SSD
{
private:
	char* model;
	double price;
	unsigned int capacity;
public:
	SSD();
	SSD(const char*, double, unsigned int);
	~SSD();
	SSD(const SSD&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getCapacity();

	void setModel(const char*);
	void setPrice(double);
	void setCapacity(unsigned int);
};