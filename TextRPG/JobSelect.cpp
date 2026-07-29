#include "JobSelect.h"
#include "Warrior.h"
#include "Bowman.h"
#include "Mage.h"
#include "Rogue.h"

#include <iostream>

Player* JobSelect(const string& name, int stat[])
{
	cout << "어떤 직업으로 시작할까?" << endl;
	cout << "==================================" << endl;
	cout << endl;
	cout << "1. 전사	        2. 궁수" << endl;
	cout << "3. 마법사	4. 도적" << endl;
	cout << endl;
	cout << "==================================" << endl;

	int choice;

	cout << "직업을 선택하세요." << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		return new Warrior(name, stat[0], stat[1], stat[2], stat[3]);

	case 2:
		return new Bowman(name, stat[0], stat[1], stat[2], stat[3]);

	case 3:
		return new Mage(name, stat[0], stat[1], stat[2], stat[3]);

	case 4:
		return new Rogue(name, stat[0], stat[1], stat[2], stat[3]);

	default:
		return nullptr;
	}
}

