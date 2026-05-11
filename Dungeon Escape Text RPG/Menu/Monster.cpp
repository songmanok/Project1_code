#include "Monster.h"

Monster::Monster(string name, int hp, int power, int defence,
    string dropItemName, int dropItemPrice)
    :name(name), hp(hp), power(power), defence(defence),
    dropItemName(dropItemName), dropItemPrice(dropItemPrice)
{
}
string Monster::getName() {
    return name;
}
string Monster::getDropItemName() {
    return dropItemName;
}
int Monster::getHP() {
    return hp;
}
int Monster::getPower() {
    return power;
}
int Monster::getDefence() {
    return defence;
}
void Monster::setHP(int hp) {
    this->hp = hp;
}
void Monster::attack(Player* player) {
    int damage = power - player->getDefence();

    if (damage <= 0) {
        damage = 1;
    }
    int beforeHP = player->getHp();

    player->setHp(player->getHp() - damage);

    cout << name << " attacks!" << endl;
    cout << damage << " damage to "
        << player->getname() << "!" << endl;
    cout << player->getname() << " HP:" << beforeHP << " -> "
        << player->getHp() << endl;

};