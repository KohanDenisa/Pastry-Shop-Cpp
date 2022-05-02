#pragma once
#include "product.cpp"

class PastryShop {
public:
	PastryShop();
	PastryShop(Product* prl, int np, int c);
	PastryShop(const PastryShop& other);
	PastryShop& operator=(const PastryShop& other);
	~PastryShop();
	inline unsigned int getNrprod() const { return nrprod; }
	inline unsigned int getCapacity() const { return capacity; }
	inline Product* getProduct_list() { return product_list; }

	void append(Product p, bool* err = nullptr);

	// remove the element from the end
	Product popBack();

	// remove an element from position i
	Product remove(unsigned int index);

	// get the element on a position
	Product& get(unsigned int i)const;
	std::string toString() const;
	friend ostream& operator<<(ostream& s, const PastryShop& arr);
	

private:
	Product* product_list;
	int nrprod;
	int capacity;
	void resize(unsigned int newCapacity);
};