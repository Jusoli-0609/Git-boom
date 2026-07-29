#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string name, int hp, int sp, int atk, int def, int exp, int maxExp, int level)
{
	this->name = name;
	this->job = "루키";
	this->level = 1;
	exp = 0;
	maxExp = 100;

	this->hp = hp;
	this->sp = sp;
	this->atk = atk;
	this->def = def;
}

int Player::gethp()
{
	return hp;
}

int Player::getsp()
{
	return sp;
}

int Player::getatk()
{
	return atk;
}

int Player::getdef()
{
	return def;
}

int Player::getexp()
{
	return exp;
}

int Player::getmaxExp()
{
	return maxExp;
}

int Player::getlevel()
{
	return level;
}

void Player::Printplayerstatus()
{
	cout << "==================================" << endl;
	cout << endl;
	cout << "닉네임 : " << name << endl;
	cout << "직업 : " << job << endl;
	cout << "Level : " << level << endl;
	cout << endl;
	cout << "HP : " << hp << endl;
	cout << "SP : " << sp << endl;
	cout << "공격력 : " << atk << endl;
	cout << "방어력 : " << def << endl;
	cout << endl;
	cout << "==================================" << endl;
	cout << endl;
	cout << endl;
}

Inventory& Player::GetInventory()
{
	return inventory;
}

string Player::getName()
{
	return name;
}

string Player::getJob()
{
	return job;
}

void Player::setJob(string job)
{
	this->job = job;
}

void Player::Gainexp(int amount)
{
	exp += amount;

	if (exp >= maxExp)
	{
		levelUP();
	}
}

void Player::levelUP()
{
	level++;

	hp += 10;
	sp += 5;
	atk += 3;
	def += 2;

	exp = 0;
	maxExp += 50;

	cout << "Level UP!!!" << endl;
	cout << "현재 레벨 : " << level << endl;
}

void Player::takedamage(int damage)
{
	damage -= def;

	if (damage < 1)
		damage = 1;

	hp -= damage;

	if (hp < 0)
		hp = 0;
}

bool Player::isDead()
{
	return hp == 0;
}