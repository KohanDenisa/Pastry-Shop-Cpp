#include "pastryshop.h"

PastryShop::PastryShop()
{
	capacity = 1;
	product_list = new Product[capacity]();;
	nrprod = 0;
	it = 0;
}

PastryShop::PastryShop(Product* prl, int np, int c)
{
	nrprod = np;
	this->capacity = capacity;
	this->product_list = new Product[capacity]();
	for (int i = 0; i < nrprod; i++)
		this->product_list[i] = prl[i];
	it = 0;
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

void PastryShop::append(Product p)
{
	if (nrprod == capacity) {
		resize(capacity * 2);
	}
	product_list[nrprod] = p;
	nrprod++;
}



void PastryShop::update(int id, string n, float w, float p, string t)
{
	int i, ok = 0;
	for (i = 0; i < nrprod; i++)
		if (product_list[i].getId() == id)
		{
			product_list[i].setName(n);
			product_list[i].setWeight(w);
			product_list[i].setPrice(p);
			product_list[i].setType(t);
			ok = 1;
		}
	
	if (ok == 0) {
		throw 1;
	}
}


Product PastryShop::remove(unsigned int id)
{
	int i, j, ok = 0; for (i = 0; i < nrprod; i++)
		if (product_list[i].getId() == id)
		{
			ok = 1;
			Product p = product_list[i];
			for (j = i; j < nrprod - 1; j++)
				product_list[j] = product_list[j + 1];
			nrprod--;
			return p;
		}
	if (ok == 0)
	{
		throw 1;
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


Product& PastryShop::get_by_id(unsigned int id)const
{
	int i, ok = 0;
	for (i = 0; i < nrprod; i++)
		if (product_list[i].getId() == id)
		{
			ok = 1;
			Product *p = &product_list[i];
			return *p;
		}
	if (ok == 0) {
		throw 1;
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

PastryShop PastryShop::filterByPrice(float p)
{
	PastryShop result(nullptr, 0, 2);
	for (int i = 0; i < nrprod; i++)
		if (product_list[i].getPrice() == p)
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

bool operator==(const PastryShop& a, const PastryShop& b)
{
	if (a.getNrprod() != b.getNrprod())
		return false;
	for (int i = 0; i < a.getNrprod(); i++)
		if (!(a.get_i(i) == b.get_i(i)))
			return false;
	return true;
}


void PastryShop::read_it()
{

		ifstream inFile("save.csv");
		string line;
		getline(inFile, line);
		int id;
		string name;
		float weight;
		float price;
		string type;
		char* p;
		
		while (getline(inFile, line))
		{
			char arr[250];
			strcpy(arr, line.c_str());
			p = strtok(arr, ",");
			id = atoi(p);
			p = strtok(NULL, ",");
			name = p;
			p = strtok(NULL, ",");
			weight = atof(p);
			p = strtok(NULL, ",");
			price = atof(p);
			p = strtok(NULL, ",");
			type = p;

		}
		Product p2(id, name, weight, price, type);
		this->append(p2);
		inFile.close();
		
}

void PastryShop::save_it()
{
	ofstream outFile("save.csv");
	outFile << "Id, Name, Weight, Price, Type\n";
	for (int i = 0; i < nrprod; i++)
	{
		outFile << product_list[i].getId() << ",";
		outFile << product_list[i].getName() << ",";
		outFile << product_list[i].getWeight() << ",";
		outFile << product_list[i].getPrice() << ",";
		outFile << product_list[i].getType() << endl;
	}
	outFile.close();
}

void PastryShop::iterateAndSave_it()
{
	ofstream outFile; 
	if (it == 0) {
		outFile = ofstream("save.csv");
		outFile << "Id, Name, Weight, Price, Type\n";
	}
	else
		outFile = ofstream("save.csv", ios_base::app);

	if (it < nrprod) 
	{
		outFile << product_list[it].getId() << ",";
		outFile << product_list[it].getName() << ",";
		outFile << product_list[it].getWeight() << ",";
		outFile << product_list[it].getPrice() << ",";
		outFile << product_list[it].getType() << endl;
		it++;
	}

	if (it == nrprod)
		it = 0;
	outFile.close();
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