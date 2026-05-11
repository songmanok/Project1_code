#include "Thief.h"

Thief::Thief(string name, int hp, int mp, int power, int defence)
	:Player(name, hp, mp, power + 30, defence) {
	job = "Rogue";
}
	void Thief::attack() {
		cout << "* Knife Throw!" << endl;
	}