#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Common
{
protected:
	int x;
	int y;
public:
	Common(int x, int y) : x(x), y(y) {};
	int GetX()
	{
		return x;
	}
	void IncreaseX(int n)
	{
		x += n;
	}
	int GetY()
	{
		return y;
	}
	void IncreaseY(int n)
	{
		y += n;
	}
};

class Base abstract
{
protected:
	string name;
	int speed;
	int power;
	Common* common;
public:
	void Show(Common* ref) 
	{
		common = ref;
		cout << "Name: " << this->name << endl;
		cout <<"Speed: " << this->speed << endl;
		cout <<"Power: " << this->power << endl;
		char buffer[100];
		sprintf_s(buffer, "(Coordinates: X: %d   Y: %d)\n", common->GetX(), common->GetY());
		cout << buffer << endl;
	}
};

class LightInfantry : public Base
{
public:
	LightInfantry()
	{
		name = "Light Infantry";
		power = 10;
		speed = 20;
	}
};
class TransportVehicle : public Base
{
public:
	TransportVehicle()
	{
		name = "Transport vehicle";
		power = 0;
		speed = 70;
	}
};
class HeavyQquipment : public Base
{
public:
	HeavyQquipment()
	{
		name = "Heavy equipment";
		power = 150;
		speed = 15;
	}
};
class LightVehicles : public Base
{
public:
	LightVehicles()
	{
		name = "Light vehicles";
		power = 30;
		speed = 50;
	}
};

class Aircraft : public Base
{
public:
	Aircraft()
	{
		name = "Aircraft";
		power = 100;
		speed = 300;
	}
};
class CharacterFactoryTwo
{
	map<string, Base*> tr;
public:
	CharacterFactoryTwo()
	{
		tr["LightInfantry"] = new LightInfantry();
		tr["HeavyQquipment"] = new HeavyQquipment();
		tr["TransportVehicle"] = new TransportVehicle();
		tr["LightVehicles"] = new LightVehicles();
		tr["Aircraft"] = new Aircraft();

	}
	~CharacterFactoryTwo()
	{
		delete tr["LightInfantry"];
		delete tr["HeavyQquipment"];
		delete tr["TransportVehicle"];
		delete tr["LightVehicles"];
		delete tr["Aircraft"];
		tr.clear();
	}
	Base* GetCharacter(string key)
	{
		if (tr[key] != nullptr)
			return tr[key];
		else
			return nullptr;
	}
};

int main()
{
	CharacterFactoryTwo* transpFac = new CharacterFactoryTwo();
	Common sprite(10, 15);

	for (int i = 0; i < 2; i++)
	{
		Base* baseTransp = transpFac->GetCharacter("LightInfantry");
		if (baseTransp != nullptr)
			baseTransp->Show(&sprite);
		sprite.IncreaseX(10);
		sprite.IncreaseY(10);
	}
	for (int i = 0; i < 2; i++)
	{
		Base* baseTransp = transpFac->GetCharacter("HeavyQquipment");
		if (baseTransp != nullptr)
			baseTransp->Show(&sprite);
		sprite.IncreaseX(10);
		sprite.IncreaseY(10);
	}
	for (int i = 0; i < 2; i++)
	{
		Base* baseTransp = transpFac->GetCharacter("TransportVehicle");
		if (baseTransp != nullptr)
			baseTransp->Show(&sprite);
		sprite.IncreaseX(10);
		sprite.IncreaseY(10);
	}
	delete transpFac;
	system("pause");
}
