#pragma once


#include <iostream>
#include <string>
#include<ostream>
#include<istream>
#include<iomanip>
#include<iostream>
#include<cctype>
using namespace std;

class Product {
public:
	int getId()const;
	void setId(int i);
	string getName()const;
	void setName(string n);
	float getWeight()const;
	void setWeight(float w);
	float getPrice()const;
	void setPrice(float p);
	string getType()const;
	void setType(string t);
	Product();
	Product(int i, string n, float w, float p, string t);
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Product&);

private:
	int id;
	string name;
	float weight;
	float price;
	string type;

};