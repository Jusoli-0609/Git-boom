#pragma once

#include <string>
#include <vector>
#include "PotionRecipe.h"

using namespace std;

class Workshop
{
private:
	
	vector<PotionRecipe> recipes;

public:

	Workshop();

	void ShowAllRecipe() const;
	void SearchByName(string name) const;
	void SearchBymaterial(string material) const;
	void Run();
};