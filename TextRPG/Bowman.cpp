#include "Bowman.h"

#include <iostream>

using namespace std;

Bowman::Bowman(string name, int hp, int sp, int atk, int def)

	: Player(name, hp, sp, atk, def, exp, maxExp, level)
{
	job = "궁수";

	this->atk += 20;
	this->hp += 5;

}

void Bowman::attack()
{
	cout << "발사!!" << endl;
}
