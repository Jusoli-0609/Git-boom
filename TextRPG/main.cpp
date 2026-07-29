#include <iostream>

#include "Character.h"
#include "Upgrade.h"
#include "JobSelect.h"
#include "Inventory.h"
#include "Item.h"
#include "Workshop.h"


#include "Player.h"
#include "Warrior.h"
#include "Bowman.h"
#include "Rogue.h"
#include "Mage.h"
#include "Monster.h"
#include "Battle.h"

using namespace std;

int main()
{
    srand((unsigned int)time(nullptr));
  
	string name;
	int stat[SIZE] = { 0 };

	CharacterCreation(name, stat); // 캐릭터 생성

	system("cls");

	cout << "게임을 시작합니다!" << endl;

	UpgradeMenu(name, stat); // 스탯 보너스 

	system("cls");

	Player* player = JobSelect(name, stat); // 직업 선택

	system("cls");

	player->Printplayerstatus(); // 최종 확인

    int menu;

    while (true)
    {
        system("cls");

        cout << "==================================" << endl;
        cout << "          메인 메뉴" << endl;
        cout << "==================================" << endl;
        cout << "1. 던전 입장" << endl;
        cout << "2. 인벤토리" << endl;
        cout << "3. 포션 제작소" << endl;
        cout << "0. 게임 종료" << endl;
        cout << "==================================" << endl;
        cout << "선택 : ";

        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            Item potion;
            potion.Name = "체력 포션";
            potion.Price = 100;

            Item claw;
            claw.Name = "늑대 발톱";
            claw.Price = 30;

            Item steel;
            steel.Name = "강철";
            steel.Price = 50;

            Monster slime("슬라임", 20, 5, 0, potion, 10);
            Monster wolf("늑대", 30, 10, 1, claw, 20);
            Monster kobold("코볼트", 15, 5, 3, steel, 30);

            Monster* monster;

            int random = rand() % 3;

            if (random == 0)
            {
                monster = &slime;
            }
            else if (random == 1)
            {
                monster = &wolf;
            }
            else
            {
                monster = &kobold;
            }

            Battle battle(player, monster);

            cin.ignore();

            battle.StartBattle();

            break;
        }

        case 2:
            system("cls");

            cout << "==================================" << endl;
            cout << "          인벤토리" << endl;
            cout << "==================================" << endl;

            player->GetInventory().ShowItems();

            cout << endl;
            cout << "[ENTER를 눌러 메뉴로 돌아갑니다.]" << endl;

            cin.ignore();
            cin.get();

            break;

        case 3:
        {
            system("cls");
            Workshop workshop;
            workshop.Run();
            break;
        }

        case 0:
            cout << "게임을 종료합니다." << endl;

            delete player;
            return 0;

        default:
            cout << "잘못된 입력입니다." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }

	return 0;
}