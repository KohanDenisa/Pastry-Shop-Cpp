#include "UserInterface.h"

void UserInterface::displayMenu()
{
	cout << "a - 1.Add a new product" << endl;
	cout << "d - 2.Display all products" << endl;
	cout << "p - 3.Remove the product from the end" << endl;
	cout << "r - 4.Remove a product by a given index " << endl;
	cout << "i - 5.Insert an element at a given index in the repository " << endl;
	cout << "u - 6.Update a product at a agiven index " << endl;
	cout << "f - 7.Filter and display a repository by type " << endl;
	cout << "g - 8.Get a product by index" << endl;
	cout << "e - 9.Exit" << endl;
	cout << endl;
	cout << "Pick a command:" << endl;
}

UserInterface::UserInterface(Controller& c)
{
	control = c;
}
Product UserInterface:: readProduct()
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

void UserInterface::menu()
{
		while (1)
		{
			system("cls");
			Product pr1, pr2;
			char x;
			int index_re, index_ge, index_in, index_up, i = 0;
			string n, fil_type;
			float w = 0;
			float p = 0;
			string t;
			displayMenu();
			cin >> x;
			if (x >= 'A' && x <= 'Z')
				x = x + 32;
			switch (x)
			{
			case 'a':
				pr1 = readProduct();
				control.appendProduct(&pr1);
				break;
			case 'd':
				for (unsigned int i = 0; i < control.getNrProd(); i++) {
					cout << control.get(i) << " ";
				}
				break;
			case 'p':
				control.popback();
				for (unsigned int i = 0; i < control.getNrProd(); i++) {
					cout << control.get(i) << " ";
				}
				break;
			case 'r':
				cout << "index_remove:";
				cin >> index_re;
				control.removeByIndex(index_re);
				for (unsigned int i = 0; i < control.getNrProd(); i++) {
					cout << control.get(i) << " ";
				}
				break;
			case 'i':
				cout << "index_insert:";
				cin >> index_in;
				control.insert_at_i(pr2, index_in);
				for (unsigned int i = 0; i < control.getNrProd(); i++) {
					cout << control.get(i) << " ";
				}
				break;
			case 'u':
				cout << "index_update:";
				cin >> index_up;
				cout << "id:";
				cin >> i;
				cout << "name:";
				cin >> n;
				cout << "weight:";
				cin >> w;
				cout << "price:";
				cin >> p;
				cout << "type:";
				cin >> t;
				control.update_at_i(index_up, i, n, w, p, t);
				for (unsigned int i = 0; i < control.getNrProd(); i++) {
					cout << control.get(i) << " ";
				}
				break;
			case 'f':
				cout << "filter type:";
				cin >> fil_type;
				control.filter_and_display_by_type(fil_type);
				break;
			case 'g':
				cout << "index_get:";
				cin >> index_ge;
				cout << control.get(index_ge);
				break;

			case 'e':
				break;
			}

			system("pause");
		}
	}


