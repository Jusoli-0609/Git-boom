#include "Mage.h"

#include <iostream>

using namespace std;

Mage::Mage(string name, int hp, int sp, int atk, int def)

	: Player(name, hp, sp, atk, def, exp, maxExp, level)
{
	job = "마법사";

	
	this->sp += 15;
	this->atk += 10;

}

void Mage::attack()
{
	cout << "주문 시전 중" << endl;
}
