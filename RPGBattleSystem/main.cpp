#include <iostream>
#include "GameObjects.h"

int main(void)
{
	std::cout << "RPG BATTLE SYSTEM" << std::endl;

	Player player(100, 10);
	player.BeAttacked(10);
	Item sword("소드", 10);
	Reward slimeReward(50,1000,&sword);

	Slime slime(50, 5, &slimeReward);
	
	int userInput = 0;
	int turn = 1;

	while (true)
	{
		std::cout << "현재 진행 중인 턴 수 : " << turn << std::endl;

		std::cin >> userInput;

		if (userInput == 1)
		{
			player.Attack(&slime);
		}

		std::cout << "슬라임의 turn" << std::endl;
		slime.Attack(&player);

		if (player.IsDead() || slime.IsDead())
		{
			break;
		}
	}

	player.ShowStatus();
	// 1. 게임 시작 화면

	// 2. 메인 게임 플레이

	// phase 1. 돌아다니는 기능

	// phase 2. player vs Monster
}