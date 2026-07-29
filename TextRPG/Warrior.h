#pragma once
#include "Player.h"

class Warrior : public Player {
public:

		Warrior(string name, int hp, int sp, int atk, int def);

	void attack() override;
};