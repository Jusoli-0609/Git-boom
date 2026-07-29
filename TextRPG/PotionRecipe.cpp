#include <iostream>
#include "PotionRecipe.h"

using namespace std;

void PotionRecipe::PrintRecipe() const
{
	cout << potionName << " : "
		 << material1 << " x" << material1Count << ", "
		 << material2 << " x" << material2Count << endl;
}