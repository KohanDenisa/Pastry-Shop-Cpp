#pragma once
#include "Controller.h"
class UserInterface
{
public:
	UserInterface(Controller& c);//constructor
	void displayMenu();//function that displays the menu on the screen 
	Product readProduct();//function that lets the user read a Product 
	void menu();

private:
	Controller control;

};

