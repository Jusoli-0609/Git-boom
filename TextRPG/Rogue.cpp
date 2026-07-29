#include "Rogue.h"

#include <iostream>

using namespace std;

Rogue::Rogue(string name, int hp, int sp, int atk, int def)

	: Player(name, hp, sp, atk, def, exp, maxExp, level)
{
	job = "도적";

	this->atk += 25;

}

void Rogue::attack()
{
	cout << "Back ATTACK!!!!" << endl;
}
