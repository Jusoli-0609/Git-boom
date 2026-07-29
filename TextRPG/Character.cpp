#include "Character.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const string statName[SIZE] = { "HP","SP","공격력","방어력" };
const int statMax[SIZE] = { 15,10,5,5 };

void PrintStatus(const string& name, int stat[])
{
    cout << "==================================" << endl;
    cout << "        Hero information" << endl;
    cout << "==================================" << endl;

    cout << "이름 : " << name << endl;
    cout << "==================================" << endl;

    cout << "체력   : " << stat[0] << endl;
    cout << "기력   : " << stat[1] << endl;
    cout << "공격력 : " << stat[2] << endl;
    cout << "방어력 : " << stat[3] << endl;

    cout << "==================================" << endl;
}

void CharacterCreation(string& name, int stat[])
{
    int point = 20;

    while (true)
    {
        point = 20;

        system("cls");

        cout << "==================================" << endl;
        cout << "      Character Creation" << endl;
        cout << "==================================" << endl;

        cout << "당신의 이름을 입력해주세요 : ";
        cin >> name;

        cout << endl;
        cout << "능력치를 설정합니다." << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << "남은 스탯포인트 : " << point << endl;

            if (i == 0)
                cout << statName[i] << "(1~15) : ";
            else if (i == 1)
                cout << statName[i] << "(0~10) : ";
            else
                cout << statName[i] << "(0~5) : ";

            cin >> stat[i];

            while ((i == 0 && stat[i] < 1) ||
                stat[i] < 0 ||
                stat[i] > statMax[i] ||
                stat[i] > point)
            {
                cout << "다시 입력하세요 : ";
                cin >> stat[i];
            }

            point -= stat[i];
            cout << endl;
        }

        system("cls");

        PrintStatus(name, stat);

        cout << "이 캐릭터로 시작하겠습니까? (Y/N) : ";

        char answer;
        cin >> answer;

        if (answer == 'Y' || answer == 'y')
        {
            break;
        }
    }
}
