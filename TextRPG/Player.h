#pragma once

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Inventory.h"

using namespace std;

class Player
{
protected:

	string name;
	string job;

	int level;

	int hp;
	int sp;
	int atk;
	int def;

	int exp;
	int maxExp;

	Inventory inventory;

public:

	Player(string name, int hp, int sp, int atk, int def, int exp, int maxExp, int level);

	void Printplayerstatus();

	virtual void attack() = 0;

	virtual ~Player() {}

	string getName();
	string getJob();

	int gethp();
	int getsp();
	int getatk();
	int getdef();
	int getexp();
	int getmaxExp();
	int getlevel();

	Inventory& GetInventory();

	void Gainexp(int amount);

	void levelUP();

	void setJob(string Job);

	void takedamage(int damage);

	bool isDead();
};


#endif 