#pragma once
#include "Player.h"

class Rogue : public Player {
public:

	Rogue(string name, int hp, int sp, int atk, int def);

	void attack() override;
};