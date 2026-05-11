#pragma once
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Monster {
protected:
	string name;
    string dropItemName;
    int dropItemPrice;
    int hp;
    int power;
    int defence;
public:
    Monster(string name, int hp, int power, int defence,
        string dropItemName, int dropItemPrice);

    string getName();
    string getDropItemName();
    int getHP();
    int getPower();
    int getDefence();

    void setHP(int hp);
    void attack(Player* player);

    virtual ~Monster() {}

    };