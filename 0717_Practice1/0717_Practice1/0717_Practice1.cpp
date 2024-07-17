// 232쪽 5, 6, 9

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

struct CandyBar {
    string name;
    float weight;
    int calories;
};

void PrintSnack(CandyBar candy)
{
    cout << "Name :" << candy.name << endl
         << "Weight : " << candy.weight << endl
         << "Calories : " << candy.calories << "\n\n";
}

int main()
{
    CandyBar snack = { "Mocha Munch", 2.3, 350 };
    PrintSnack(snack);

    cout << "============== \n\n";

    CandyBar snacks[3];
    snacks[0] = { "Oreos", 1.2, 200 };
    snacks[1] = { "MnM", 0.4, 80 };
    snacks[2] = { "Pepsi", 2.3, 150 };

    for (int i = 0; i < sizeof(snacks) / sizeof(snacks[0]); i++)
        PrintSnack(snacks[i]);

    cout << "============== \n\n";

    CandyBar* pSnack;
    pSnack = new CandyBar[3];
    
    pSnack[0] = { "Mint", 1.7, 190 };
    pSnack[1] = { "Chocolate", 0.8, 50 };
    pSnack[2] = { "Vanilla", 2.4, 40 };

    for (int i = 0; i < 3; i++)
        PrintSnack(pSnack[i]);
    
    delete[] pSnack;
}
