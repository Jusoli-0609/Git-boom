#pragma once

#ifndef BATTLE_H_
#define BATTLE_H_

#include "Player.h"
#include "Monster.h"

class Battle
{
private:
	Player* player;
	Monster* monster;

	void ShowStatus();
	void PlayerTurn();
	void MonsterTurn();
	bool CheckEnd();

public:
	Battle(Player* player, Monster* monster);

	void StartBattle();

};

#endif
