#include "GameObjects.h"

void Player::Attack(Monster* monster)
{
	std::cout << "플레이어의 공격!" << std::endl;
	monster->BeAttacked(this);
}

void Player::BeAttacked(int damage)
{
	std::cout << "플레이어가 데미지를 받음!" << std::endl;

	HP -= damage;

	if (IsDead())
	{
		HP = 0;
		std::cout << "플레이어가 사망하였습니다" << std::endl;
		exit(0);
	}
}

bool Player::IsDead()
{
	if (HP <= 0)
		return true;
	else
		return false;
}

void Player::GetMoney(int money)
{
	std::cout << "획득한 재화 : " << money << std::endl;
	this->money += money;
}

void Player::GetExp(int exp)
{
	std::cout << "획득한 경험치 : " << exp << std::endl;
	this->exp += exp;
}

std::vector<Item>* Player::GetInventory()
{
	return &inventory;
}

void Player::ShowStatus()
{
	std::cout << "현재 체력 : " << HP << std::endl;
	std::cout << "현재 공격력 :" << AP << std::endl;
	std::cout << "현재 경험치 : " << exp << std::endl;
	std::cout << "----플레이어 소지품----" << std::endl;
	std::cout << "현재 금액 : " << money << std::endl;
	std::cout << "현재 아이템 : " << std::endl;
}

int Player::GetAttackPowwer()
{
	return AP;
}

void Slime::Attack(Player* player)
{
	std::cout << "슬라임의 공격!" << std::endl;
	player->BeAttacked(AP);
}

void Slime::BeAttacked(Player* player)
{
	std::cout << "슬라임이 움츠러들었다" << std::endl;
	HP -= player->GetAttackPowwer();

	if (IsDead())
	{
		HP = 0;
		std::cout << "슬라임을 처치했습니다" << std::endl;
		DropReward(player);
	}
}

void Slime::DropReward(Player* player)
{
	std::cout << "몬스터 처치 보상" << std::endl;
	monsterReward->RewardExp();
	monsterReward->RewardItem(player->GetInventory());
	monsterReward->RewardMoney();
}

bool Slime::IsDead()
{
	if (HP <= 0)
		return true;
	else
		return false;
}

void Reward::RewardItem(std::vector<Item>* inventory)
{
	if (item != nullptr)
	{
		inventory->push_back(*item);
		std::cout << "아이템 획득 : " << std::endl;
		item->ShowItemInfo();
	}
}


