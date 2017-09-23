#ifndef STORYG_CH01_Character_CPP
#define STORYG_CH01_Character_CPP
#include "Contracts/Weapon.hpp"
#include <iostream>

using namespace std;
using namespace Storyg::Contracts;

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

#endif