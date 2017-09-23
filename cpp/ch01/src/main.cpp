#include <iostream>
#include "Knife.cpp"
#include "Sword.cpp"
#include "Character.cpp"
#include "Contracts/Weapon.hpp"
using namespace std;

int main() {
	Character * c = new Character(new Sword());
	c->doAttack();
	c->setWeapon(new Knife());
	c->doAttack();
   return 0;
}