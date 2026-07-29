#pragma once

#include <string>

using namespace std;

struct Item
{
	string Name;
	int Price;

	void PrintInfo() const;
};
