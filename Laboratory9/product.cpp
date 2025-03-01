#include "product.h"
#include <string>
using namespace std;


int Product::getId()const
{
	return this->id;
}

void Product::setId(int i)
{
	this->id = i;
}

string Product::getName()const
{
	return this->name;
}

void Product::setName(string n)
{
	this->name = n;
}

float Product::getWeight()const
{
	return this->weight;
}

void Product::setWeight(float w)
{
	this->weight = w;
}

float Product::getPrice()const
{
	return this->price;
}

void Product::setPrice(float p)
{
	this->price = p;
}

string Product::getType()const
{
	return this->type;
}

void Product::setType(string t)
{
	this->type = t;
}

Product::Product()
{
	this->id = 0;
	this->name = "unknown";
	this->weight = 0.0;
	this->price = 0.0;
	this->type = "unknown";

}

Product::Product(int i, string n, float w, float p, string t)
{
	this->id = i;
	this->name = n;
	this->weight = w;
	this->price = p;
	this->type = t;

}

std::string Product::toString() const
{
	//std::ostream s;

	char s[100] = "";
	sprintf(s, "Product with id : %d  named : %s  has weight : %f, price: %f  and type %s", id, name.c_str(), weight, price, type.c_str());
	return std::string(s);
}


ostream& operator<<(std::ostream& out, const Product& p)
{
	out << "Product with id:" << p.getId() << " named:" << p.getName() << ", has weight:" << p.getWeight() << ", price:" << p.getPrice() << " and type" << p.getType();
	return out;
}


Product& Product::operator=(const Product& other)
{
	if (this == &other)
		return *this;
	id = other.id;
	name = other.name;
	weight = other.weight;
	price = other.price;
	type = other.type;
	return *this;

}

bool operator==(const Product& a, const Product& b)
{
	if (a.getId() != b.getId() || a.getName() != b.getName() || a.getWeight() != b.getWeight() || a.getPrice() != b.getPrice() || a.getType() != b.getType()  )
		return false;
	return true;
}
