
#include <iostream>
#include "product.h"
#include "pastryshop.h"
#include <string>


using namespace std;



void displayMenu() {
	cout << "1.Add a new product" << endl;
	cout << "2.Display all products" << endl;
	cout << "3.Remove the product from the end" << endl;
	cout << "4.Remove a product by a given index " << endl;
	cout << "5.Get a product by index" << endl;
	cout << "6.Exit" << endl;
	cout << "Pick a command:" << endl;
}

Product read_product()
{
	int id1;
	string n;
	float w;
	float p;
	string t;


	cout << "id:";
	cin >> id1;
	cout << "name:";
	cin >> n;
	cout << "weigth:";
	cin >> w;
	cout << "price:";
	cin >> p;
	cout << " type:";
	cin >> t;
	Product pr(id1, n, w, p, t);
	return pr;
}


void menu()
{
	while (1)
	{
		PastryShop shop;
		Product pr1;
		char x;
		int index_re, index_ge;
		displayMenu();
		cin >> x;
		if (x >= 'A' && x <= 'Z')
			x = x + 32;
		switch (x)
		{
		case 'a':
			pr1 = read_product();
			shop.append(pr1);
			break;
		case 'd':
			for (unsigned int i = 0; i < shop.getNrprod(); i++) {
				cout << shop.get(i) << " ";
			}
			break;
		case 'rl':
			shop.popBack();
			for (unsigned int i = 0; i < shop.getNrprod(); i++) {
				cout << shop.get(i) << " ";
			}
			break;
		case 'ri':
			cout << "index_remove:";
			cin >> index_re;
			shop.remove(index_re);
			for (unsigned int i = 0; i < shop.getNrprod(); i++) {
				cout << shop.get(i) << " ";
			}
			break;
		case 'gi':
			cout << "index_get";
			cin >> index_ge;
			cout << shop.get(index_ge);
			break;

		case 'q':
			return;
		}
	}
}

int main()
{
	menu();
}
