#include<iostream>
#include<string>

#include "Player.h"
#include "Monster.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Slime.h"
#include "Goblin.h"
#include "Wolf.h"
using namespace std;

void printStatus(string name, int stat[]) {
    cout << "====================================" << endl;
    cout << " " << name << "'s Stats" << endl;
    cout << "====================================" << endl;
    cout << "HP: " << stat[0] << "    MP: " << stat[1] << endl;
    cout << "Attack: " << stat[2] << "    Defense: " << stat[3] << endl;
    cout << "====================================" << endl;
  }

int main() {
    string name;
    int stat[4];

    cout << "====================================" << endl;
    cout << " [ Dungeon Escape Text RPG ]" << endl;
    cout << "====================================" << endl;
    cout << "Enter Your hero's name: ";
    cin >> name;
    cout << endl;
    while (true) {
        cout << "Enter HP and MP: ";
        cin >> stat[0] >> stat[1];
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Please enter numbers only" << endl;
            continue;
        }
        
        if (stat[0] >= 50 && stat[1] >= 50) {
            break;
        }
        cout << "HP or MP is too low. Try again." << endl;
    }
    while (true) {
        cout << "Enter Attack and Defense: ";
        cin >> stat[2] >> stat[3];
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Please enter numbers only" << endl;
            continue;
        }

        if (stat[2] >= 50 && stat[3] >= 50) {
            break;
        }
        cout << "Attack or Defense is too low. Try again." << endl;
    }
    cout << endl;

    printStatus(name, stat);

    cout << endl;

    cout << "* You received 5 HP Potins and 5 MP Potions" << endl;
    cout << "====================================" << endl;
    cout << "< Character Upgrade >" << endl;
    cout << "1. HP UP    2. MP UP    3. Attack x2" << endl;
    cout << "4. Defense x2  5. Show Stats  0. Start Game" << endl;
    cout << "====================================" << endl;


    int HPPotion = 5;
    int MPPotion = 5;
    int powerup = 1;
    int defenceup = 1;
    bool isGameStart = false;
    int choice;
    while (!isGameStart) {
        cout << "Choose:";
        cin >> choice;

        switch (choice) {

        case 0:
            cout << "Starting the game!" << endl;
            isGameStart = true;
            break;
        case 1:
            if (HPPotion > 0) {
                HPPotion--;
                stat[0] += 20;
                cout << "HP increased by 20. (HP Potion used:" << HPPotion << " left)" << endl;
            }
            else {
                cout << "HP Potion low" << endl;
            }
            break;
        case 2:
            if (MPPotion > 0) {
                MPPotion--;
                stat[1] += 20;
                cout << "MP increased by 20. (MP Potion used:" << MPPotion << " left)" << endl;
            }
            else {
                cout << "MP Potion low" << endl;
            }
            break;
        case 3:
            if (powerup > 0) {
                powerup--;
                stat[2] *= 2;
                cout << "Attack x2" << endl;
            }
            else {
                cout << "I've already used it" << endl;
            }
            break;
        case 4:
            if (defenceup > 0) {
                defenceup--;
                stat[3] *= 2;
                cout << "Defence x2" << endl;
            }
            else {
                cout << "I've already used it" << endl;
            }
            break;
        case 5:
            printStatus(name, stat);
            break;
        default:
            cout << "Wrong choice" << endl;
            continue;
        }
       
    }
    cout << endl;
    cout << "< Job Selection >" << endl;
    cout << name << " choose your job!" << endl;
    cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;
           
    Player* player = nullptr;

    int jobChoice;
    while (true) {
        cout << "Choose: ";
        cin >> jobChoice;

        switch (jobChoice) {
        case 1:
            player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Warrior! (HP + 30)";
            break;
        case 2:
            player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Magician! (MP + 30)";
            break;
        case 3:
            player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Rogue! (Power + 30)";
            break;
        case 4:
            player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Archer! (Defence + 30)";
            break;
        default:
            cout << "Wrong choice" << endl;
            continue;
        }
        break;
    }
    cout << endl;
    player->attack();
    player->printPlayerStatus();
    
    cout << endl;

    Monster* monster = nullptr;
    int monsterchoice;
    while (true) {
        cout << "<< Monster Choice >>" << endl;
        cout << "1.Slime  2.Goblin  3.Wolf " << endl;
        cout << "Choice: ";
        cin >> monsterchoice;
        switch (monsterchoice) {
        case 1:
            monster = new Slime();
            break;
        case 2:
            monster = new Goblin();
            break;
        case 3:
            monster = new Wolf();
            break;
        default:
            cout << "Re" << endl;
            continue;
        }
        break;
    }
    

    cout << "[ Battle Start! ] "
        << player->getname()
        << " ( " << player->getjob() << " )"
        << " vs " << monster->getName() << endl;

    
    while (player->getHp() > 0 && monster->getHP() > 0) {
        cout << endl;
        cout << "--- Player Turn ---" << endl;

        player->attack();

        int damage = 
            player->getPower() - monster->getDefence();
        if (damage <= 0) {
            damage = 1;
        }

        int beforeHP = monster->getHP();
        monster->setHP(monster->getHP()-damage);
        cout << damage << " damage to " << monster->getName()
             << "!" << endl;
        cout << monster->getName() << " HP: " << beforeHP
            << " -> " << monster->getHP() << endl;
       

        if (monster->getHP() <= 0) {
            break;
        }
        cout << endl;

        cout << "--- Monster Turn ---" << endl;
        monster->attack(player);
    }
    cout << endl;
    if (player->getHp() > 0) {
        cout << "* Victory!" << endl;
        cout << "-> Got: " << monster->getDropItemName() << "!" << endl;
        cout << "(Will be saved to inventory in the next STEP)" << endl;

    }
    else {
        cout << "You Died..." << endl;
    }
    delete player;
    player = nullptr;
    delete monster;
    monster = nullptr;

    return 0;
    
}
