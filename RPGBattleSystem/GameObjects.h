#pragma once
#include <string>
#include <iostream>
#include <vector>

class Item
{
private:
	std::string name;
	int index;
public:
	Item() {}
	Item(std::string name, int index) : name(name), index(index) {};
	void ShowItemInfo()
	{
		std::cout << "아이템의 이름 : " << name << std::endl;
		std::cout << "아이템의 번호 : " << index << std::endl;
	}
};

class Reward
{
private:
	int exp;
	int money;
	Item* item;
public:
	Reward() {}
	Reward(int exp, int money, Item* item) : exp(exp), money(money)
	{
		this->item = new Item();
		this->item = item;
	}
	~Reward()
	{
		delete item;
	}
	void RewardItem(std::vector<Item>* inventory);
	int RewardMoney() { return money; };
	int RewardExp() { return exp; };
};

class Monster;

class Player
{
private:
	int HP;
	int AP;
	int exp;
	int money;
	std::vector<Item> inventory;
public:
	Player() {} 
	Player(int hp, int ap) : HP(hp), AP(ap) {}
	~Player() {}
	void Attack(Monster* monster);
	void BeAttacked(int damage);
	bool IsDead();
	void GetMoney(int money);
	void GetExp(int exp);
	std::vector<Item>* GetInventory();
	void ShowStatus();
	int GetAttackPowwer();
};

class Monster
{
protected:
	int HP;
	int AP;
	Reward* monsterReward;
public:
	Monster() {}
	Monster(int hp, int ap) : HP(hp), AP(ap) {};
	~Monster() {};
	virtual void Attack(Player* player)=0;
	virtual void BeAttacked(Player* player) = 0;
	virtual void DropReward(Player* player) = 0;
};

class Slime : public Monster
{
public:
	Slime(int hp, int ap, Reward* rewardPtr) : Monster(hp, ap)
	{
		std::cout << "슬라임 생성!" << std::endl;
		InsertDropItemTable(rewardPtr);
	}
	~Slime() {}

	void InsertDropItemTable(Reward* rewardPtr)
	{
		monsterReward = new Reward();
		monsterReward = rewardPtr;
	}
	void Attack(Player* player);
	void BeAttacked(Player* player);
	void DropReward(Player* player);
	bool IsDead();
};

