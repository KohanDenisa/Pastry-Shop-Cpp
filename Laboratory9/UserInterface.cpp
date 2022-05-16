#include "UserInterface.h"

void UserInterface::displayMenu()
{
	cout << "a - 1.Add a new product" << endl;
	cout << "d - 2.Display all products" << endl;
	cout << "r - 3.Remove a product by a given id " << endl;
	cout << "u - 4.Update a product at a agiven index " << endl;
	cout << "ft - 5.Filter and display a repository by type " << endl;
	cout << "fp - 6.Filter and display a repository by price " << endl;
	cout << "g - 7.Get a product by id" << endl;
	cout << "und - 8.Undo" << endl;
	cout << "red - 9.Redo" << endl;
	cout << "read - 10.Read" << endl;
	cout << "save - 11.Save" << endl;
	cout << "ias - 12.Iterate and save" << endl;
	cout << "e - 13.Exit" << endl;
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
			PastryShop s;
			int id_re, id_ge, id_up, i = 0;
			string n, fil_type;
			float fil_price;
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
				control.appendProduct(pr1);
				break;
			case 'd':
				for (unsigned int i = 0; i < control.getNrProd(); i++) {
					cout << control.get(i) << " ";
				}
				break;
			case 'r':
				try {
					cout << "id_remove:";
					cin >> id_re;
					control.removeById(id_re);
					for (unsigned int i = 0; i < control.getNrProd(); i++) {
						cout << control.get(i) << " ";
					}
				}
				catch (int e)
				{
					if (e == 1)
						cout << "Unavailable id";
				}
				break;
			case 'u':
				try
				{
					cout << "id_update:";
					cin >> id_up;
					cout << "name:";
					cin >> n;
					cout << "weight:";
					cin >> w;
					cout << "price:";
					cin >> p;
					cout << "type:";
					cin >> t;
					control.update_by_id(i, n, w, p, t);
					for (unsigned int i = 0; i < control.getNrProd(); i++) {
						cout << control.get(i) << " ";
					}
				}
				catch (int e)
				{
					if (e == 1)
						cout << "Unavailable id";
				}
				break;
			case 'ft':
				cout << "filter type:";
				cin >> fil_type;
				s = control.filter_and_display_by_type(fil_type);
				for (int i = 0; i < s.getNrprod(); i++)
					cout << s.get_i(i).toString() << endl;
				break;
			case 'fp':
				cout << "filter price:";
				cin >> fil_price;
				s = control.filter_and_display_by_price(fil_price);
				for (int i = 0; i < s.getNrprod(); i++)
					cout << s.get_i(i).toString() << endl;
				break;
			case 'g':
				try {
				cout << "id_get:";
				cin >> id_ge;
				cout << control.getbyid(id_ge);
					}
				catch (int e)
				{
					if (e == 1)
						cout << "Unavailable id";
				}
				break;
			case 'und':
				control.undo();
				break;
			case 'red':
				control.redo();
				break;
			case 'read':
				control.read();
				break;
			case 'save':
				control.save();
				break;
			case 'ias':
				control.iterateAndSave();
				break;
			case 'e':
				break;
			}

			system("pause");
		}
	}
