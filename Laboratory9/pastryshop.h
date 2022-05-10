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
	PastryShop();
	PastryShop(Product* prl, int np, int c);

	PastryShop(const PastryShop& other);//copy constructor
	PastryShop& operator=(const PastryShop& other);//asignment operator
	~PastryShop();//free the allocated memory

	inline unsigned int getNrprod() const { return nrprod; }
	inline unsigned int getCapacity() const { return capacity; }
	inline Product* getProduct_list() { return product_list; }

	void append(Product p, bool* err = nullptr);//add an element at the end of the repository
	void insert(Product p, int index);//insert an element at a given index in the repository
	void update(int index, int id, string n, float w, float p, string t);

	// remove the element from the end
	Product pop_back();

	// remove an element from position i
	Product remove(unsigned int index);

	// get the element on a position
	Product& get_i(unsigned int i)const;
	PastryShop filterByType(string t);

	std::string toString() const;
	friend ostream& operator<<(ostream& s, const PastryShop& arr);


	void read();
	void save();
	void iterateAndSave();

private:
	Product* product_list;
	int nrprod;
	int capacity;
	void resize(unsigned int newCapacity);
};