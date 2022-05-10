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

void PastryShop::insert(Product p, int index)
{
	if (0 > index || index >= nrprod)
		throw 1;
	else
	{
	
	if (nrprod == capacity)
		resize(2 * capacity);
	nrprod++;
	for (int i = nrprod; i > index; i--)
		product_list[i] = product_list[i - 1];
	product_list[index] = p;
	}


}

void PastryShop::update(int index, int i, string n, float w, float p, string t)
{
	if (0 > index || index >= nrprod)
		throw 1;
	else
	{
		product_list[i].setId(i);
		product_list[i].setName(n);
		product_list[i].setWeight(w);
		product_list[i].setPrice(p);
		product_list[i].setType(t);
	}

}

Product PastryShop::pop_back()
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

Product& PastryShop::get_i(unsigned int i)const
{

	if (i >= 0 && i < nrprod) {
		return product_list[i];
	}
	else {
		cerr << "Precondition does not hold: get()" << endl;
		exit(-1);
	}

}

PastryShop PastryShop::filterByType(string t)
{
	PastryShop result(nullptr, 0, 2);
	for (int i = 0; i < nrprod; i++)
		if (product_list[i].getType() == t)
			result.append(product_list[i]);
	return result;
}

std::string PastryShop::toString() const
{
	std::string s = std::string("Pastry shop with capacity: %d, has %d number of products and items:", capacity, nrprod);
	for (int i = 0; i < nrprod; i++)
		s = s + product_list[i].toString();
	return s;
}

void PastryShop::read()
{

		ifstream inputFile;
		string data;
		inputFile.open("file.csv", fstream::in);
		do 
		{
			inputFile >> data;
			//  char* p = strdup(data.c_str());
			//  products[i].setId(id);
			//	products[i].setName(name);
			//	products[i].setWeight(weight);
			//	products[i].setPrice(price);
			//	products[i].setType(type);
		} while (!EOF);
		inputFile.close();
	


		//ifstream f("file.txt");
		//int capacity, nrprod;
		//f >> capacity >> nrprod;
		//Product* products = new Product[capacity]();
		//for (int i = 0; i < nrprod; i++) {
		//	int id;
		//	string name, type;
		//	float weight, price;
		//	f >> id >> name >> weight >> price >> type;
		//	products[i].setId(id);
		//	products[i].setName(name);
		//	products[i].setWeight(weight);
		//	products[i].setPrice(price);
		//	products[i].setType(type);
		//}
		
}

void PastryShop::save()
{
	/*ofstream f("file.csv");
	f << "Id" << " " << "Name" << " " << "Weight" << " " << "Price" << " " << "Type" << endl;
	for (int i = 0; i < repository.getNrprod(); i++)
		f << repository.get(i).getId() << ", " << repository.get(i).getName() << ", " << repository.get(i).getWeight() << ", " << repository.get(i).getPrice() << ", " << repository.get(i).getType() << endl;*/

}

void PastryShop::iterateAndSave()
{
}

ostream& operator<<(std::ostream& out, const PastryShop& p)
{
	out << "Pastry shop with capacity:" << p.getCapacity() << " has " << p.getNrprod() << " number of products and items:";
	for (int i = 0; i < p.getNrprod(); i++)
		out << p.get_i(i);
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