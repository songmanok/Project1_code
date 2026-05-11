#include "Magician.h"

Magician :: Magician(string name, int hp, int mp, int power, int defence)
        : Player(name, hp, mp + 30, power, defence)
    {
        job = "Mage";
    }
    void Magician::attack()  { 
        cout << "* Fireball!" << endl; 
    }
