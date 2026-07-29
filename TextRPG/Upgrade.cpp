#include "Upgrade.h"
#include "Character.h"

#include <iostream>

using namespace std;

void setPotion(int count, int* p_hpPotion, int* p_spPotion)
{
    *p_hpPotion = count;
    *p_spPotion = count;
}

void UpgradeMenu(const string& name, int stat[])
{
    int hpPotion = 0;
    int spPotion = 0;

    setPotion(2, &hpPotion, &spPotion);

    bool isGameStart = false;
    bool attackUpgrade = false;
    bool defenseUpgrade = false;

    int menu;

    while (!isGameStart)
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << endl;
        cout << "< 캐릭터 강화 >" << endl;
        cout << "1. HP UP    2. SP UP" << endl;
        cout << "3. 공격력 2배    4. 방어력 2배" << endl;
        cout << "5.캐릭터 정보    6. 게임 시작" << endl;
        cout << endl;
        cout << "==================================" << endl;
        cout << "번호를 선택해주세요 : ";


        cin >> menu;

        switch (menu)
        {
        case 1:  //이건 HP 포션 사용했을 때

            if (hpPotion > 0)
            {
                stat[0] += 5;
                hpPotion--;

                system("cls");

                cout << "* HP가 5 증가했습니다. (남은 HP 포션 "
                    << hpPotion << "개)" << endl;
            }
            else
            {
                system("cls");

                cout << "HP 포션이 없습니다." << endl;
            }

            break;

        case 2: //SP 포션 사용했을 때

            if (spPotion > 0)
            {
                stat[1] += 5;
                spPotion--;

                system("cls");

                cout << "* SP가 5 증가했습니다. (남은 SP 포션 "
                    << spPotion << "개)" << endl;
            }
            else
            {

                system("cls");

                cout << "SP 포션이 없습니다." << endl;
            }

            break;

        case 3: //공력력 강화

            if (!attackUpgrade)
            {
                stat[2] *= 2;
                attackUpgrade = true;

                system("cls");

                cout << "* 공격력이 2배가 되었습니다!" << endl;
            }
            else
            {
                system("cls");

                cout << "이미 공격력 강화를 사용했습니다." << endl;
            }

            break;

        case 4: //방어력 강화

            if (!defenseUpgrade)
            {
                stat[3] *= 2;
                defenseUpgrade = true;

                system("cls");

                cout << "* 방어력이 2배가 되었습니다!" << endl;
            }
            else
            {

                system("cls");

                cout << "이미 방어력 강화를 사용했습니다." << endl;
            }

            break;

        case 5: //남아있는 포션 개수출력

            system("cls");

            PrintStatus(name, stat);

            cout << "HP 포션 : " << hpPotion << endl;
            cout << "SP 포션 : " << spPotion << endl;

            break;

        case 6://게임 시작 (선택하면 일단 테스트 끝남)

            cout << "출발하자!" << endl;
            isGameStart = true;

            system("cls");

            break;


        default: //입력 에러 방지용

            cout << "잘못된 입력입니다." << endl;
        }
    }
}