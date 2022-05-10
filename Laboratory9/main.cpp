#include <iostream>
#include "product.h"
#include "pastryshop.h"
#include "UserInterface.h"
#include <string>


using namespace std;


int main()
{
	Controller controller;
	UserInterface ui(controller);

	ui.menu();
}