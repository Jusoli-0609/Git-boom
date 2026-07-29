#include <iostream>
#include <string>
#include "Battle.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"

using namespace std;

Battle::Battle(Player* player, Monster* monster)
{
	this->player = player;
	this->monster = monster;
}

void Battle::ShowStatus()
{                           
    cout << "==================================" << endl;
    cout << "           [Battle Log]" << endl; 
    cout << "==================================" << endl;

    cout << player->getName() << endl;
    cout << "HP : " << player->gethp() 
         << "     SP : " << player->getsp() << "\n" 
         << "공격력 : " << player->getatk() 
         << " 방어력 : " << player->getdef() << endl;

    cout << endl;

    cout << monster->getName() << endl;
    cout << "HP : " << monster->gethp() << endl;
    cout << "공격력 : " << monster->getatk() << " 방어력 : " << monster->getdef() << endl;

    cout << "==================================" << endl;
}

void Battle::PlayerTurn()
{
    cout << player->getName() << "의 공격!" << endl;

    player->attack();

    monster->takeDamage(player->getatk());

    cout << endl;
    cout << monster->getName() << "의 남은 HP : " << monster->gethp() << endl;
}

void Battle::MonsterTurn()
{
    cout << endl;
    cout << monster->getName() << "의 공격!" << endl;

    player->takedamage(monster->getatk());

    cout << endl;
    cout << player->getName() << "의 남은 HP : " << player->gethp() << endl;
    cout << "==================================" << endl;
    cout << "[ENTER를 눌러 계속진행]" << endl;
    cin.get();
}

bool Battle::CheckEnd()
{
    if (monster->isDead())
    {
        cout << monster->getName() << "을 처치했습니다!" << endl;

        Item item = monster->GetDropItem();
        
        player->getexp();
        player->Gainexp(monster->getexpReward());
        player->GetInventory().AddItem(item);

        cout << item.Name << "을(를) 획득했습니다." << endl;
        cout << endl;
        cout << monster->getexpReward() << "경험치를 획득했습니다." << endl;
        cout << "[ENTER를 눌러 계속진행]" << endl;
        cin.get();
        return true;
    }

    if (player->isDead())
    {
        cout << player->getName() << "이 쓰러졌습니다." << endl;
        cout << "[ENTER를 눌러 계속진행]" << endl;
        cin.get();
        return true;
    }

    return false;
}

void Battle::StartBattle()
{
    while (true)
    {
        ShowStatus();

        PlayerTurn();

        if (CheckEnd())
            break;

        MonsterTurn();

        system("cls");

        if (CheckEnd())
            break;

    }
}