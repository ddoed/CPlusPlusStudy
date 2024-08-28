#include "GameObjects.h"

void Player::Attack(Monster* monster)
{
	std::cout << "�÷��̾��� ����!" << std::endl;
	monster->BeAttacked(this);
}

void Player::BeAttacked(int damage)
{
	std::cout << "�÷��̾ �������� ����!" << std::endl;

	HP -= damage;

	if (IsDead())
	{
		HP = 0;
		std::cout << "�÷��̾ ����Ͽ����ϴ�" << std::endl;
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
	std::cout << "ȹ���� ��ȭ : " << money << std::endl;
	this->money += money;
}

void Player::GetExp(int exp)
{
	std::cout << "ȹ���� ����ġ : " << exp << std::endl;
	this->exp += exp;
}

std::vector<Item>* Player::GetInventory()
{
	return &inventory;
}

void Player::ShowStatus()
{
	std::cout << "���� ü�� : " << HP << std::endl;
	std::cout << "���� ���ݷ� :" << AP << std::endl;
	std::cout << "���� ����ġ : " << exp << std::endl;
	std::cout << "----�÷��̾� ����ǰ----" << std::endl;
	std::cout << "���� �ݾ� : " << money << std::endl;
	std::cout << "���� ������ : " << std::endl;
}

int Player::GetAttackPowwer()
{
	return AP;
}

void Slime::Attack(Player* player)
{
	std::cout << "�������� ����!" << std::endl;
	player->BeAttacked(AP);
}

void Slime::BeAttacked(Player* player)
{
	std::cout << "�������� �����������" << std::endl;
	HP -= player->GetAttackPowwer();

	if (IsDead())
	{
		HP = 0;
		std::cout << "�������� óġ�߽��ϴ�" << std::endl;
		DropReward(player);
	}
}

void Slime::DropReward(Player* player)
{
	std::cout << "���� óġ ����" << std::endl;
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
		std::cout << "������ ȹ�� : " << std::endl;
		item->ShowItemInfo();
	}
}


