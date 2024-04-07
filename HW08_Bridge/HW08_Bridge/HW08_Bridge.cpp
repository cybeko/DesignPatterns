#include <iostream>
#include <string>
using namespace std;

class IComponent abstract
{
public:
	virtual void PrintInfo() abstract;
};

class RAM : public IComponent
{
protected:
	int capacity;
	float price;
	string manufacturer;
public:
	RAM(int capacity, float price, string manufacturer)
	{
		this->capacity = capacity;
		this->price = price;
		this->manufacturer = manufacturer;
	}
	void PrintInfo() override
	{
		cout << "\nRAM:" << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Price: $" << this->price << endl;
		cout << "Manufacturer: " << this->manufacturer << endl;
	}
};

class HDD : public IComponent
{
protected:
	int capacity;
	float price;
	string manufacturer;
public:
	HDD(int capacity, float price, string manufacturer)
	{
		this->capacity = capacity;
		this->price = price;
		this->manufacturer = manufacturer;
	}
	void PrintInfo() override
	{
		cout << "\nHard Drive:" << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Price: $" << this->price << endl;
		cout << "Manufacturer: " << this->manufacturer << endl;
	}
};
class GraphicsCard : public IComponent
{
protected:
	int capacity;
	float price;
	string manufacturer;
public:
	GraphicsCard(int capacity, float price, string manufacturer)
	{
		this->capacity = capacity;
		this->price = price;
		this->manufacturer = manufacturer;
	}
	void PrintInfo() override
	{
		cout << "\nGraphicsCard:" << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Price: $" << this->price << endl;
		cout << "Manufacturer: " << this->manufacturer << endl;
	}
};

class PC abstract
{
protected:
	IComponent* component;
public:
	IComponent* GetComponent()
	{
		return this->component;
	}
	void SetComponent(IComponent* component)
	{
		this->component = component;
	}
	virtual void PrintInfo()
	{
		component->PrintInfo();
	}
};

class UserPC : public PC
{};

void client(IComponent* component, PC* pc)
{
	pc->SetComponent(component);
	pc->PrintInfo();
}
int main()
{
	IComponent* component = new RAM(3288, 400, "Kingston");
	PC* pc = new UserPC();
	client(component, pc);
	delete component;

	component = new HDD(2230, 300, "Seagate BarraCuda");
	client(component, pc);
	delete component;

	component = new GraphicsCard(4000, 500, "Gigabyte");
	client(component, pc);
	delete component;
	delete pc;

	system("pause");
	return 0;
}