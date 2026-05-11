#include "Warrior.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defence)
        :Player(name, hp + 30, mp, power, defence)
    {
        job = "Warrior";
    }
    void Warrior :: attack()  { 
        cout << "* Sword slash" << endl; 
    }