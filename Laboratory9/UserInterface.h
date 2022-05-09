#pragma once
#include "Controller.h"
class UserInterface
{
public:
	UserInterface(Controller c);
	void add();
	void remove();
	void displayMenu();



private:
	Controller control;

};

