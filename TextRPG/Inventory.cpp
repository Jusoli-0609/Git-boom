#include <iostream>

#include "Inventory.h"

using namespace std;

Inventory::Inventory()
{

}

void Inventory::AddItem(const Item& item)
{
	inventory.push_back(item);
}

void Inventory::RemoveItem(int index)
{
	if (index >= 0 && index < inventory.size())
	{
		inventory.erase(inventory.begin() + index);
	}
}

void Inventory::ShowItems() const
{
	if (inventory.empty())
	{
		cout << "인벤토리가 비어 있습니다." << endl;
		return;
	}

	for (const Item& item : inventory)
	{
		item.PrintInfo();
	}
}

Item* Inventory::GetItem(int index)
{
	if (index >= 0 && index < inventory.size())
	{
		return &inventory[index];
	}

	return nullptr;
}