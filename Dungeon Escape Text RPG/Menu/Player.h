#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player {
protected:
	string name;
	string job;
	int hp;
	int mp;
	int level;
	int power;
	int defence;

public:
	Player(string name, int hp, int mp, int power, int defence);
	
	string getname();
	string getjob();
	int getHp();
	int getMp();
	int getPower();
	int getDefence();

	void setHp(int hp);
	void setMp(int mp);

	void printPlayerStatus();

	virtual void attack() = 0;
	virtual ~Player() {}
};