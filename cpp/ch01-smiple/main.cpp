#include <iostream>

using namespace std;

class Weapon   
{   
public:
	virtual void doAttack() = 0;
};

class Character
{
protected:
	Weapon * w;
	
public:
	Character(Weapon *w);
	void doAttack();
	Character * setWeapon(Weapon *w);
};

Character::Character(Weapon * w){
	this->w = w;
}

Character * Character::setWeapon(Weapon * w){
	this->w = w;
	return this;
}

void Character::doAttack(){
	w->doAttack();
}

class Sword : public Weapon
{
protected:
	
public:
	void doAttack();
};

void Sword::doAttack(){
	cout << "Sword Attack!!" << endl;
}

class Knife : public Weapon
{
protected:
	
public:
	void doAttack();
};

void Knife::doAttack(){
	cout << "Knife Attack!!" << endl;
}

int main() {
	Character * c = new Character(new Sword());
	c->doAttack();
	c->setWeapon(new Knife());
	c->doAttack();
   return 0;
}