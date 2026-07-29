#include "Warrior.h"

#include <iostream>

using namespace std;

Warrior::Warrior(string name, int hp, int sp, int atk, int def)

	: Player(name, hp, sp, atk, def, exp, maxExp, level)
{
	job = "전사";

	this->hp += 15;
	this->def += 10;

}

void Warrior::attack()
{
	cout << "검을 휘두른다!!" << endl;
}
