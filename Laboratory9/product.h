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
	int getId()const;//gets the id of the product
	void setId(int i);//sets the id of the product
	string getName()const;//gets the name of the product
	void setName(string n);//sets the name of the product
	float getWeight()const;//gets the weight of the product
	void setWeight(float w);//sets the weight of the product
	float getPrice()const;//gets the price of the product
	void setPrice(float p);//sets the price of the product
	string getType()const;//gets the type of the product
	void setType(string t);//sets the type of the product
	Product();//default constructor
	Product(int i, string n, float w, float p, string t);//constructor
	std::string toString() const;//transforms an object of type Product into a string 
	friend std::ostream& operator<<(std::ostream& out, const Product&);
	Product& operator=(const Product& other);
	friend bool operator==(const Product& a, const Product& b);

private:
	int id;
	string name;
	float weight;
	float price;
	string type;

};
//fara pointer