#pragma once
#include "Controller.h"
class UserInterface
{
public:
	UserInterface(Controller& c);
	void append();
	void remove();
	void displayMenu();
	Product readProduct();
	void menu();
	void insert(Product p, int index);
	void update(int index, int i, string n, float w, float p, string t);
	void popBack();
	void undo();
	void redo();
	void read();
	void save();
	void iterateAndSave();


private:
	Controller control;

};

