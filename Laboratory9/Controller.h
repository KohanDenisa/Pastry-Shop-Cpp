#pragma once

#include<fstream>
#include<stack>
#include "Product.h"
#include "PastryShop.h"
using namespace std;

enum class ActionType {
	ADD,
	REMOVE,
	INSERT
};

class Controller
{
public:
	Controller();
	Controller(Product* repo, int nr, int c);
	void appendProduct(Product* prod);//add an element at the end of the repository
	bool removeByIndex(int i);// remove an element from position i
	Product popback();
	void displayAll();
	Product& get(unsigned int i)const;
	int getNrProd();
	void insert_at_i(Product p, int index);//insert an element at a given index in the repository
	void update_at_i(int index, int i, string n, float w, float p, string t);//update a product at a agiven index
	void filter_and_display_by_type(string t);//filter and display a repository by type
	bool undo();
	bool redo();
	void read();
	void save();
	void iterateAndSave();


private:
	PastryShop repository;
	std::stack<pair<ActionType, Product*>>undoStack;
	std::stack<pair<ActionType, Product*>>redoStack;

};

