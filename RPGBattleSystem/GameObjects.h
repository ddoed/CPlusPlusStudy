#pragma once
#include <string>

class Player
{
private:
	int HP;
	int AttackPower;
public:
	Player() {};
	Player(int hp, int attackpower) : HP(hp), AttackPower(attackpower) {};
	~Player();
	void Attack(Monster* monster);
	void Attacked();
};

class Monster
{
private:
	int Hp;
	int AttackPower;
	std::string Name;
	Reward* monsterReward;
public:
	Monster(int Hp, int AttackPower, Reward* monsterReward, std::string Name) : Hp(Hp), AttackPower(AttackPower), monsterReward(monsterReward), Name(Name) {};
	~Monster() {};
	virtual void Attack(Player* player)=0;
	virtual void Attacked() = 0;
	virtual void DropReward() = 0;
};

class Slime : public Monster
{
private:
	int Hp;
	int AttackPower;
	std::string Name;
	Reward* monsterReward;
public:
	
};

class Reward
{
private:
	int exp;
	int money;
	Item* item;
public:
	Reward() {};
	Reward(int exp, int money, Item* item) : exp(exp), money(money), item(item) {};
};

class Item
{
private:
	int itemNum;
public:
	Item() {};
	Item(int itemNum) : itemNum(itemNum) {};
};