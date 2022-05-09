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


void Controller::addProduct(Product* prod)
{
	this->repository.append(*prod);
	undoStack.push(std::make_pair(ActionType::ADD, prod));
}

void Controller::displayAll()
{
	for (int i = 0; i < repository.getNrprod(); i++)
		cout << repository.get(i).toString() << endl;
}

bool Controller::removeByIndex(int i)
{
	Product product = this->repository.remove(i);
	if(&product)
		undoStack.push(std::make_pair(ActionType::REMOVE, &product));
	return true;
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
	ifstream f("file.txt");
	int capacity, nrprod;
	f >> capacity >> nrprod;
	Product* products = new Product[capacity]();
	for (int i = 0; i < nrprod; i++) {
		int id;
		string name, type;
		float weight, price;
		f >> id  >> name >> weight >> price >> type;
		products[i].setId(id);
		products[i].setName(name);
		products[i].setWeight(weight);
		products[i].setPrice(price);
		products[i].setType(type);
	}
}

void Controller::save()
{
	ofstream f("file.txt");
	f << repository.getCapacity() << " " << repository.getNrprod() << endl;
	for (int i = 0; i < repository.getNrprod(); i++)
		f << repository.get(i).getId() << " " << repository.get(i).getName() << " " << repository.get(i).getWeight() << " " << repository.get(i).getPrice() << " " << repository.get(i).getType() << endl;


}
