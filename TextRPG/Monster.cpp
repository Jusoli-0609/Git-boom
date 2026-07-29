#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int hp, int atk, int def, Item dropItem, int expReward)
{
	this->name = name;
	this->hp = hp;
	this->atk = atk;
	this->def = def;
	this->dropItem = dropItem;
	this->expReward = expReward;
}

string Monster::getName()
{
	return name;
}

int Monster::gethp()
{
	return hp;
}

int Monster::getatk()
{
	return atk;
}

int Monster::getdef()
{
	return def;
}

void Monster::takeDamage(int damage)
{
	damage -= def;

	if (damage < 1)
		damage = 1;

	hp -= damage;

	if (hp < 0)
		hp = 0;
}

bool Monster::isDead()
{
	return hp == 0;
}

Item Monster::GetDropItem()
{
	return dropItem;
}

int Monster::getexpReward()
{
	return expReward;
}