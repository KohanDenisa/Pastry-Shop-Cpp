#pragma once
#include "product.h"
#include<ostream>
#include<vector>
#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class PastryShop {
public:
	PastryShop();//default constructor
	PastryShop(Product* prl, int np, int c);//constructor

	PastryShop(const PastryShop& other);//copy constructor
	PastryShop& operator=(const PastryShop& other);//asignment operator
	~PastryShop();//free the allocated memory

	inline unsigned int getNrprod() const { return nrprod; }//function that gets the number of products from the Pastry Shop
	inline unsigned int getCapacity() const { return capacity; }//function that gets the capacity of the Pastry Shop
	inline Product* getProduct_list() { return product_list; }//function that returns all the products from the Pastry Shop

	void append(Product p);//add an element at the end of the repository
	void update(int id, string n, float w, float p, string t);//updating an element chosen by id
	Product remove(unsigned int id);	// remove an element given by id
	Product& get_i(unsigned int i)const;// get the element on a position
	Product& get_by_id(unsigned int id)const;// get the element by a given id


	PastryShop filterByType(string t);//filtering the Pastry Shop by type
	PastryShop filterByPrice(float p);//filtering the Pastry Shop by price

	std::string toString() const;//function that transforms a Pastry Shop object into a string
	friend ostream& operator<<(ostream& s, const PastryShop& arr);
	friend bool operator==(const PastryShop& a, const PastryShop& b);


	void read_it();
	void save_it();
	void iterateAndSave_it();

private:
	Product* product_list;
	int nrprod;
	int capacity;
	void resize(unsigned int newCapacity);
	int it;//used for saveIterate
};