#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defence)
	:name(name), hp(hp), mp(mp), power(power), defence(defence),
	level(1), job("None")
{

}
string Player::getname() {
	return name;
 }
string Player::getjob() {
	return job;
}
int Player::getHp() {
	return hp;
}
int Player::getMp() {
	return mp;
}
int Player::getPower() {
	return power;
}
int Player::getDefence() {
	return defence;
}
void Player::setHp(int hp) { this->hp = hp; }
void Player::setMp(int mp) { this->mp = mp; }

void Player::printPlayerStatus() {
	cout << "------------------------------------" << endl;
	cout << "Name: " << name << " | Job: " << job << " | Lv." << level << endl;
	cout << "HP: " << hp << " | MP: " << mp 
		 << " | Attack: " << power
		 << " | Defense: " << defence << endl;
	cout << "------------------------------------" << endl;
}