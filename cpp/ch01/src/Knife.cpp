#ifndef STORYG_CH01_KNIFE_CPP
#define STORYG_CH01_KNIFE_CPP
#include "Contracts/Weapon.hpp"
#include <iostream>

using namespace std;
using namespace Storyg::Contracts;

class Knife : public Weapon
{
protected:
	
public:
	Knife();
	void doAttack();
};

Knife::Knife(){

}

void Knife::doAttack(){
	cout << "Knife Attack" << endl;
}

#endif