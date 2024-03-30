#include <iostream>
using namespace std;

class Herbivore abstract
{
protected:
	string name = "";
	int weight;
	bool isAlive;
public:
	Herbivore(int weight) :weight(weight), isAlive(true) {};
	void EatGrass()
	{
		if (isAlive)
		{
			weight += 10;
			cout << name << " ate grass. Weight: " << weight << endl;
		}
	}
	int GetWeight()const {
		return weight;
	}

	bool IsAlive()const {
		return isAlive;
	}

	void SetLifeStatus(bool isAlive) {
		this->isAlive = isAlive;
	}

	virtual string GetName()
	{
		return name;
	}
};

class Wildebeest : public Herbivore
{
public:
	Wildebeest() : Herbivore(250) {
		this->name = "Wildebeest";
	};
};

class Bison : public Herbivore {
public:
	Bison() :Herbivore(600) {
		this->name = "Bison";
	};
};
class Elk : public Herbivore {
public:
	Elk() :Herbivore(400) {
		this->name = "Elk";
	};
};

class Carnivore abstract
{
protected:
	string name = "";
	int power;
public:
	Carnivore(unsigned int power) {
		this->power = power;
	}
	unsigned int GetPower()const {
		return power;
	}

	void Eat(Herbivore*& herbivore) {
		if (this->power >= herbivore->GetWeight()) {
			this->power += 10;
			herbivore->SetLifeStatus(false);
			cout << name << " ate " << herbivore->GetName() << ". Power: " << this->power << endl;
		}
		else
		{
			this->power -= 10;
			cout << name << " couldn't eat " << herbivore->GetName() << ". Power: " << this->power << endl;

		}

	};
	virtual string GetName()
	{
		return name;
	}
};

class Lion : public Carnivore {
public:
	Lion() :Carnivore(500) {
		this->name = "Lion";
	};
};
class Wolf : public Carnivore {
public:
	Wolf() :Carnivore(300) {
		this->name = "Wolf";
	};
};
class Tiger : public Carnivore {
public:
	Tiger() :Carnivore(450) {
		this->name = "Tiger";
	};
};

class Continent abstract
{
public:
	virtual string GetName() = 0;
	virtual Carnivore* CreateCarnivore() abstract;
	virtual  Herbivore* CreateHerbivore() abstract;
};

class Africa :public Continent {
	string GetName()override {
		return "Africa";
	}
	Carnivore* CreateCarnivore() override {
		return new Lion();
	}
	Herbivore* CreateHerbivore() override {
		return new Wildebeest();
	}
};
class NorthAmerica : public Continent {
	string GetName() override {
		return "North America";

	}
	Carnivore* CreateCarnivore()override {
		return new Wolf();
	}
	Herbivore* CreateHerbivore()override {
		return new Bison();
	}
};
class Eurasia : public Continent {
	string GetName() override {
		return "Eurasia";

	}
	Carnivore* CreateCarnivore()override {
		return new Tiger();
	}
	Herbivore* CreateHerbivore()override {
		return new Elk();
	}
};

class Client {
private:
	Carnivore* carnivore;
	Herbivore* herbivore;
public:
	Client(Continent* continent) {
		carnivore = continent->CreateCarnivore();
		herbivore = continent->CreateHerbivore();
	}
	void Start() {
		FeedHerbivores();
		cout << "Power of " << carnivore->GetName() << ": " << carnivore->GetPower() << endl;
		FeedCarnivores();
		if (herbivore->IsAlive() == false)
		{
			cout << herbivore->GetName() << " is dead." << endl;
		}
		cout << endl;
	}
	string GetHerbivoreName() {
		return herbivore->GetName();
	}
	string GetCarnivoreName() {
		return carnivore->GetName();
	}
	void FeedHerbivores() {
		herbivore->EatGrass();
	}
	void FeedCarnivores() {
		carnivore->Eat(herbivore);
	}
};
void main() {
	Continent* continent = new Africa();
	cout << continent->GetName() << endl;
	Client* client = new Client(continent);
	client->Start();
	delete continent;
	delete client;

	continent = new NorthAmerica();
	cout << continent->GetName() << endl;
	client = new Client(continent);
	client->Start();
	delete continent;
	delete client;

	continent = new Eurasia();
	cout << continent->GetName() << endl;
	client = new Client(continent);
	client->Start();
	delete continent;
	delete client;

	system("pause");
}