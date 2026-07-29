#pragma once
#include <string>
#include "Item.h"

#ifndef MONSTER_H_ 
#define MONSTER_H_

using namespace std;

class Monster
{
private:
	string name;
	int hp;
	int atk;
	int def;

	int expReward;
	Item dropItem;



public:
	Monster(string name, int hp, int atk, int def, Item dropItem, int expReward);

	string getName();

	int gethp();
	int removehp(int num);
	int getatk();
	int getdef();
	int getexpReward();

	void takeDamage(int damage);

	bool isDead();

	Item GetDropItem();
};

#endif
