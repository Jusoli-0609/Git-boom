#include <iostream>
#include "Item.h"

void Item::PrintInfo() const
{
	cout << "이름: " << Name << endl;
	cout << "가격: " << Price << " G" << endl;
}