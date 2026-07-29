#include <iostream>
#include "Workshop.h"

using namespace std;

Workshop::Workshop()
{
	PotionRecipe hp;
	hp.potionName = "HP포션";
	hp.material1 = "허브";
	hp.material1Count = 1;
	hp.material2 = "맑은물";
	hp.material2Count = 1;

	recipes.push_back(hp);

	PotionRecipe sp;
	sp.potionName = "SP포션";
	sp.material1 = "허브";
	sp.material1Count = 1;
	sp.material2 = "베리";
	sp.material2Count = 1;

	recipes.push_back(sp);
}

void Workshop::ShowAllRecipe() const
{
	cout << "==================================" << endl;
	cout << "          전체 레시피" << endl;
	cout << "==================================" << endl;

	for (const PotionRecipe& recipe : recipes)
	{
		recipe.PrintRecipe();
	}
}

void Workshop::SearchByName(string name) const
{
	bool found = false;

	for (const PotionRecipe& recipe : recipes)
	{
		if (recipe.potionName == name)
		{
			recipe.PrintRecipe();
			found = true;
		}
	}

	if (found)
	{
		cout << "찾을 수 없습니다." << endl;
	}
}

void Workshop::SearchBymaterial(string material) const
{
	int count = 0;

	for (const PotionRecipe& recipe : recipes)
	{
		if (recipe.material1 == material ||
			recipe.material2 == material)
		{
			recipe.PrintRecipe();
			count++;
		}
	}

	cout << "총 " << count << "개의 레시피를 찾았습니다." << endl;
}

void Workshop::Run()
{
	int menu;

	while (true)
	{
		cout << endl;
		cout << "==================================" << endl;
		cout << "          제작소" << endl;
		cout << "==================================" << endl;
		cout << "1. 전체 레시피 보기" << endl;
		cout << "2. 포션 이름으로 검색" << endl;
		cout << "3. 재료로 검색" << endl;
		cout << "0. 돌아가기" << endl;

		cout << "선택 : ";
		cin >> menu;

		if (menu == 0)
			break;

		switch (menu)
		{
		case 1:
			ShowAllRecipe();
			break;

		case 2:
		{
			string name;

			cout << "검색할 포션 이름 : ";
			cin >> name;

			SearchByName(name);

			break;
		}

		case 3:
		{
			string material;

			cout << "검색할 재료 : ";
			cin >> material;

			SearchBymaterial(material);

			break;
		}

		default:
			cout << "잘못된 입력입니다." << endl;
		}
	}
}