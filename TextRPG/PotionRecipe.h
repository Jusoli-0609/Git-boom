#pragma once

#include <string>

using namespace std;

struct PotionRecipe
{
	string potionName;

	string material1;
	int material1Count;

	string material2;
	int material2Count;

	void PrintRecipe() const;
};