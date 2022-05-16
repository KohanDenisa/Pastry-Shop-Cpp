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
	Controller();//default constructor
	Controller(Product* repo, int nr, int c);//constructor
	void appendProduct(Product prod);//add an element at the end of the repository
	bool removeById(int id);// remove an element by id 
	void displayAll();//function that displays all the products 
	Product& get(unsigned int i)const;//function that gets a product by index
	Product& getbyid(unsigned int id)const;//function that gets a product by id
	int getNrProd();//function that gets the number of products
	void update_by_id(int i, string n, float w, float p, string t);//update a product at a a given index
	PastryShop filter_and_display_by_type(string t);//filter and display a repository by type
	PastryShop filter_and_display_by_price(float p);//filter and display a repository by price
	bool undo();//undo function
	bool redo();//redo function
	void read();
	void save();
	void iterateAndSave();


private:
	PastryShop repository;
	std::stack<pair<ActionType, Product>>undoStack;
	std::stack<pair<ActionType, Product>>redoStack;

};

