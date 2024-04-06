#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Component abstract
{
protected:
	string name;
	int price;
public:
	Component(string name, int price)
	{
		this->name = name;
		this->price = price;
	}
	Component(string name)
	{
		this->name = name;
		this->price = 0;
	}

	virtual  void Add(Component* c) abstract;
	virtual  void Remove(Component* c) abstract;
	virtual  void Display(int depth) abstract;
};

class Composite : public Component
{
	vector<Component*> vecComponents;

public:
	Composite(string name) :Component(name) {	}
	Composite(string name, int price) : Component(name, price) {}

	void Add(Component* component) override
	{
		vecComponents.push_back(component);
	}

	void Remove(Component* component) override
	{
		auto iter = find(vecComponents.begin(), vecComponents.end(), component);
		vecComponents.erase(iter);
	}


	void Display(int depth) override
	{
		string s(depth, '-');
		if (this->price != 0)
		{
			cout << s + name << "\t$" << price << endl;
		}
		else
		{
			cout << s + name << endl;

		}
		for (Component* component : vecComponents)
		{
			component->Display(depth + 4);
		}
	}
};

class Leaf : public Component
{
public:
	Leaf(string name) : Component(name) {	}
	Leaf(string name, int price) : Component(name, price) {}

	void Add(Component* c) override
	{
		cout << "Cannot add to file\n";
	}
	void Remove(Component* c) override
	{
		cout << "Cannot remove from file\n";
	}
	void Display(int depth) override
	{
		string s(depth, '-');
		if (this->price != 0)
		{
			cout << s + name << "\t$" << price << endl;
		}
		else
		{
			cout << s + name << endl;

		}
	}
};

int main()
{
	Component* main = new Composite("Main");
	Component* reception = new Composite("Reception");
	reception->Add(new Leaf("Warm colors"));
	Component* coffeeTable = new Composite("Coffee table", 120);
	coffeeTable->Add(new Leaf("10-20 magazines such as \"Computer world\"", 1600));
	reception->Add(coffeeTable);
	Component* sofa = new Composite("Soft sofa", 200);
	reception->Add(sofa);
	Component* desk = new Composite("Secretary's desk", 100);
	Component* computer = new Composite("Computer", 950);
	computer->Add(new Leaf("Big hard drive capcity"));
	Component* tools = new Composite("Office tools");
	Component* cooler = new Composite("Water cooler");
	desk->Add(computer);
	desk->Add(tools);
	reception->Add(desk);
	reception->Add(cooler);

	Component* aud1 = new Composite("Auditorium 1");
	Component* tables = new Composite("Tables x10");
	aud1->Add(tables);
	desk = new Composite("Desk", 120);
	aud1->Add(desk);
	Component* teacherDesk = new Composite("Teacher's desk");
	computer = new Composite("Computer");
	teacherDesk->Add(computer);
	aud1->Add(teacherDesk);
	Component* posters = new Composite("Posters with great mathematicians");
	aud1->Add(posters);

	Component* aud2 = new Composite("Auditorium 2");
	tables = new Composite("Tables x20", 2200);
	tables->Add(new Leaf("Black tables"));
	tables->Add(new Leaf("Tables are arranged in an oval or circle"));
	aud2->Add(tables);
	Component* board = new Composite("Board");
	aud2->Add(board);
	sofa = new Composite("Soft sofa");
	sofa->Add(board);

	Component* compAud = new Composite("Computer auditorium");
	tables = new Composite("Computer tables x10", 1100);
	computer = new Composite("Computer on each table");
	computer->Add(new Leaf("Processor 2.2GHz"));
	computer->Add(new Leaf("80GB hard drive"));
	computer->Add(new Leaf("RAM 1024MB"));
	tables->Add(computer);
	Component* socket = new Composite("Socket near each table");
	tables->Add(socket);
	compAud->Add(tables);
	board = new Composite("Board", 70);
	board->Add(new Leaf("Set of colorful markers"));
	compAud->Add(board);

	Component* cafeteria = new Composite("Cafeteria");
	Component* coffeeMachine = new Composite("Coffee machine", 300);
	cafeteria->Add(coffeeMachine);
	tables = new Composite("Tables");
	tables->Add(new Leaf("4 Chairs"));
	cafeteria->Add(tables);
	Component* fridge = new Composite("Fridge", 450);
	cafeteria->Add(fridge);
	Component* sink = new Composite("Sink", 100);
	cafeteria->Add(sink);

	main->Add(reception);
	main->Add(aud1);
	main->Add(aud2);
	main->Add(compAud);
	main->Add(cafeteria);
	main->Display(1);

	system("pause");
}


