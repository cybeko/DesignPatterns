#include <iostream>
#include <string>
using namespace std;

class Hero abstract {
protected:
    string name;
    int attack;
    int speed;
    int health;
    int defense;
public:
    Hero(string n) {
        name = n;
    }
    string GetName() {
        return name;
    }
    virtual int GetAttack() abstract;
    virtual int GetSpeed() abstract;
    virtual int GetHealth() abstract;
    virtual int GetDefense() abstract;
};

class Human : public Hero {
public:
    Human() : Hero("Human") {
        attack = 20;
        speed = 20;
        health = 150;
        defense = 0;
    }
    int GetAttack() override {
        return attack;
    }
    int GetSpeed() override {
        return speed;
    }
    int GetHealth() override {
        return health;
    }
    int GetDefense() override {
        return defense;
    }
};

class HumanProfession abstract : public Human {
protected:
    Human* human;
public:
    HumanProfession(string n, Human* human) : human(human)
    {
        this->name = n;
        this->attack = human->GetAttack();
        this->speed = human->GetSpeed();
        this->health = human->GetHealth();
        this->defense = human->GetDefense();
    }
};

class HumanWarrior : public HumanProfession {
public:
    HumanWarrior(Human* human) : HumanProfession("Human warrior", human) {
        attack += 20;
        speed += 10;
        health += 50;
        defense += 20;
    }
};
class Swordsman : public HumanProfession {
public:
    Swordsman(HumanWarrior* human) : HumanProfession("Human swordsman", human) {
        attack += 40;
        speed -= 10;
        health += 50;
        defense += 40;
    }
};
class Archer : public HumanProfession {
public:
    Archer(Swordsman* human) : HumanProfession("Human archer", human)
    {
        attack += 20;
        speed += 20;
        health += 50;
        defense += 10;
    }
};
class Horseman : public HumanProfession {
public:
    Horseman(Archer* human) : HumanProfession("Human archer", human)
    {
        attack -= 10;
        speed += 40;
        health += 200;
        defense += 100;
    }
};

class Elf : public Hero {
public:
    Elf() : Hero("Elf") {
        attack = 15;
        speed = 30;
        health = 100;
        defense = 0;
    }
    int GetAttack() override {
        return attack;
    }
    int GetSpeed() override {
        return speed;
    }
    int GetHealth() override {
        return health;
    }
    int GetDefense() override {
        return defense;
    }
};

class ElfProfession abstract : public Elf {
protected:
    Elf* elf;
public:
    ElfProfession(string n, Elf* elf) : elf(elf)
    {
        this->name = n;
        this->attack = elf->GetAttack();
        this->speed = elf->GetSpeed();
        this->health = elf->GetHealth();
        this->defense = elf->GetDefense();
    }
};

class ElfWarrior : public ElfProfession {
public:
    ElfWarrior(Elf* elf) : ElfProfession("Elf warrior", elf) {
        attack += 20;
        speed -= 10;
        health += 100;
        defense += 20;
    }
};
class Mage : public ElfProfession {
public:
    Mage(Elf* elf) : ElfProfession("Elf mage", elf) {
        attack += 10;
        speed += 10;
        health -= 50;
        defense += 10;
    }
};
class EvilMage : public ElfProfession {
public:
    EvilMage(Mage* elf) : ElfProfession("Evil elf mage", elf) {
        attack += 70;
        speed += 20;
        health += 0;
        defense += 0;
    }
};
class FriendlyMage : public ElfProfession {
public:
    FriendlyMage(Mage* elf) : ElfProfession("Evil elf mage", elf) {
        attack += 50;
        speed += 30;
        health += 100;
        defense += 30;
    }
};
class Crossbowman : public ElfProfession {
public:
    Crossbowman(ElfWarrior* elf) : ElfProfession("Crossbowman elf", elf) {
        attack += 20;
        speed += 10;
        health += 50;
        defense -= 10;
    }
};
void client(Hero* hero)
{
    char s[100];
    sprintf_s(s, "Name: %s  \nAttack: %d \nSpeed: %d \nHealth: %d \nDefense: %d", hero->GetName().c_str(), hero->GetAttack(), hero->GetSpeed(), hero->GetHealth(), hero->GetDefense());
    cout << s << endl << endl;
}

int main() {
    Hero* hero = new Human();
    client(hero);
    hero = new HumanWarrior(dynamic_cast<Human*>(hero));
    client(hero);
    hero = new Swordsman(dynamic_cast<HumanWarrior*>(hero));
    client(hero);
    delete hero;

    hero = new Elf();
    client(hero);
    hero = new Mage(dynamic_cast<Elf*>(hero));
    client(hero);
    hero = new EvilMage(dynamic_cast<Mage*>(hero));
    client(hero);
    delete hero;

    system("pause");
    return 0;
}
