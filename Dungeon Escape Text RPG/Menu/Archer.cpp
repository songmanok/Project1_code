#include "Archer.h"

Archer::Archer(string name, int hp, int mp, int power, int defence)
	:Player(name, hp, mp, power, defence + 30) {
	job = "Archer";
}
void Archer::attack() {
	cout << "* Arrow shot!" << endl;
}