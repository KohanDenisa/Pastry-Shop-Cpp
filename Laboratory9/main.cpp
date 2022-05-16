#include <iostream>
#include "product.h"
#include "pastryshop.h"
#include "UserInterface.h"
#include <string>
#include "pastryshop_tests.h"

using namespace std;


int main()
{
	pastryshop_tests::test_all();
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);

	Controller controller(repo.getProduct_list(), 3, 5);
	//Controller controller;
	UserInterface ui(controller);

	ui.menu();
	
}