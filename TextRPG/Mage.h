#pragma once
#include "Player.h"

class Mage : public Player {
public:

	Mage(string name, int hp, int sp, int atk, int def);

	void attack() override;
};