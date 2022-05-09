#include "pastryshop.h"

PastryShop::PastryShop()
{
	product_list = nullptr;
	nrprod = 0;
	capacity = 0;
}

PastryShop::PastryShop(Product* prl, int np, int c)
{
	nrprod = np;
	this->capacity = capacity;
	this->product_list = new Product[capacity]();
	for (int i = 0; i < nrprod; i++)
		this->product_list[i] = prl[i];
}

PastryShop::PastryShop(const PastryShop& other)
{

	this->nrprod = other.nrprod;
	this->capacity = other.capacity;
	this->product_list = new Product[other.capacity]();

	if (product_list == nullptr) {
		cerr << "PastryShop(const PastryShop& other): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < nrprod; i++)
		this->product_list[i] = other.product_list[i];
}

PastryShop& PastryShop::operator=(const PastryShop& other)
{

	if (this != &other)
	{

		nrprod = other.nrprod;
		capacity = other.capacity;
		delete[] this->product_list;
		product_list = new Product[other.capacity]();

		if (product_list == nullptr) {
			cerr << "PastryShop(const PastryShop& other): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < nrprod; i++)
			this->product_list[i] = other.product_list[i];
	}
	return *this;
}

PastryShop::~PastryShop()
{
	delete[]product_list;
}

void PastryShop::append(Product p, bool* err)
{

	if (nrprod == capacity) {
		resize(capacity * 2);
	}
	product_list[nrprod] = p;
	nrprod++;
}

Product PastryShop::popBack()
{
	if (nrprod == 0) {

		cerr << "Precondition does not hold: popBack()" << endl;
		exit(-1);
	}


	Product p = product_list[nrprod];
	nrprod--;

	return p;
}

Product PastryShop::remove(unsigned int index)
{
	int i;

	if (index >= 0 && index < nrprod) {
		Product p = product_list[index];
		for (i = index; i < nrprod - 1; i++)
			product_list[i] = product_list[i + 1];
		nrprod--;
		return p;
	}
	else
	{
		cerr << "Precondition does not hold: remove()" << endl;
		exit(-1);
	}
}

Product& PastryShop::get(unsigned int i)const
{

	if (i >= 0 && i < nrprod) {
		return product_list[i];
	}
	else {
		cerr << "Precondition does not hold: get()" << endl;
		exit(-1);
	}

}

//std::string PastryShop::toString() const
//{
//	std::string s = std::string("Pastry shop with capacity: %d, has %d number of products and items:", capacity, nrprod);
//	for (int i = 0; i < nrprod; i++)
//		s = s + product_list[i].toString();
//	return s;
//}

ostream& operator<<(std::ostream& out, const PastryShop& p)
{
	out << "Pastry shop with capacity:" << p.getCapacity() << " has " << p.getNrprod() << " number of products and items:";
	for (int i = 0; i < p.getNrprod(); i++)
		out << p.get(i);
	return out;
}

void PastryShop::resize(unsigned int newCapacity) {

	this->capacity = newCapacity;

	Product* newproduct_list = new Product[newCapacity]();
	if (newproduct_list == nullptr) {
		cerr << "resize(): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < nrprod; i++) {
		newproduct_list[i] = this->product_list[i];
	}

	delete[] this->product_list;
	this->product_list = newproduct_list;
}  