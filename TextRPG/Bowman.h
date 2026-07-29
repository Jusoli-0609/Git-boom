#pragma once

#include "Player.h"

class Bowman : public Player {
public:

	Bowman(string name, int hp, int sp, int atk, int def);

	void attack() override;
};