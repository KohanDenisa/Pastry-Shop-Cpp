#include "Controller.h"
#include "pastryshop.h"
#include "product.h"

Controller::Controller()
{
	repository = PastryShop();
}

Controller::Controller(Product* repo, int nr, int c)
{
	repository = PastryShop(repo, nr, c);
}


void Controller::appendProduct(Product* prod)
{
	this->repository.append(*prod);
	undoStack.push(std::make_pair(ActionType::ADD, prod));
}

void Controller::displayAll()
{
	for (int i = 0; i < repository.getNrprod(); i++)
		cout << repository.get_i(i).toString() << endl;
}

Product& Controller::get(unsigned int i) const
{
	return repository.get_i(i);
}

int Controller::getNrProd()
{
	return repository.getNrprod();
}

void Controller::insert_at_i(Product p, int index)
{
	try
	{
		repository.insert(p, index);
	}
	catch (int e)
	{
		if (e == 1)
			cout << "Index out of bounds!";
	}
	
}

void Controller::update_at_i(int index, int i, string n, float w, float p, string t)
{
	try
	{
		repository.update(index, i, n, w, p, t);
	}
	catch (int e)
	{
		if (e == 1)
			cout << "Index out of bounds!";
	}
	
}

void Controller::filter_and_display_by_type(string t)
{
	PastryShop p = repository.filterByType(t);
	for (int i = 0; i < p.getNrprod(); i++)
		cout << p.get_i(i).toString() << endl;
}

bool Controller::removeByIndex(int i)
{
	Product product = this->repository.remove(i);
	if(&product)
		undoStack.push(std::make_pair(ActionType::REMOVE, &product));
	return true;
}

Product Controller::popback()
{
	Product p = repository.pop_back();
	return p;
}

bool Controller::undo()
{
	if (undoStack.top().first == ActionType::ADD)
	{
		redoStack.push(std::make_pair(ActionType::ADD, undoStack.top().second));
		undoStack.pop();
		repository.remove(repository.getNrprod() - 1);
		return true;
	}
	else 
			if (undoStack.top().first == ActionType::REMOVE) 
			{
				redoStack.push(std::make_pair(ActionType::REMOVE, undoStack.top().second));
				undoStack.pop();
				repository.append(*redoStack.top().second);
				return true;
			}
	return false;
}

bool Controller::redo()
{
	if (redoStack.top().first == ActionType::ADD)
	{
		undoStack.push(std::make_pair(ActionType::ADD, redoStack.top().second));
		redoStack.pop();
		repository.remove(repository.getNrprod() - 1);
		return true;
	}
	else
		if (redoStack.top().first == ActionType::REMOVE)
		{
			undoStack.push(std::make_pair(ActionType::REMOVE, redoStack.top().second));
			redoStack.pop();
			repository.append(*undoStack.top().second);
			return true;
		}
	return false;
}

void Controller::read()
{
	
}

void Controller::save()
{


}

void Controller::iterateAndSave()
{
}
