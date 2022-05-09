#pragma once

#include<fstream>
#include<stack>
#include "Product.h"
#include "PastryShop.h"
using namespace std;

enum class ActionType {
	ADD,
	REMOVE
};

class Controller
{
public:
	Controller();
	Controller(Product* repo, int nr, int c);
	void addProduct(Product* prod);
	void displayAll();
	bool removeByIndex(int i);
	//int size();
	bool undo();
	bool redo();
	void read();
	void save();

private:
	PastryShop repository;
	std::stack<pair<ActionType, Product*>>undoStack;
	std::stack<pair<ActionType, Product*>>redoStack;

};

