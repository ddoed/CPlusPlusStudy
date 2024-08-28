#include <iostream>
#include "GameObjects.h"

int main(void)
{
	std::cout << "RPG BATTLE SYSTEM" << std::endl;

	Player player(100, 10);
	player.BeAttacked(10);
	Item sword("�ҵ�", 10);
	Reward slimeReward(50,1000,&sword);

	Slime slime(50, 5, &slimeReward);
	
	int userInput = 0;
	int turn = 1;

	while (true)
	{
		std::cout << "���� ���� ���� �� �� : " << turn << std::endl;

		std::cin >> userInput;

		if (userInput == 1)
		{
			player.Attack(&slime);
		}

		std::cout << "�������� turn" << std::endl;
		slime.Attack(&player);

		if (player.IsDead() || slime.IsDead())
		{
			break;
		}
	}

	player.ShowStatus();
	// 1. ���� ���� ȭ��

	// 2. ���� ���� �÷���

	// phase 1. ���ƴٴϴ� ���

	// phase 2. player vs Monster
}