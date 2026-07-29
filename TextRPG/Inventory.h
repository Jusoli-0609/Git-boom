#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Item.h"


class Inventory
{
private:
	vector<Item> inventory;

public:
	Inventory();

	void AddItem(const Item& item);
	void RemoveItem(int index);
	void ShowItems() const;
	Item* GetItem(int index);
};

 