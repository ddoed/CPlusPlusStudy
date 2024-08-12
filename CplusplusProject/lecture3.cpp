/*
* 학습 목표 : c++로 구조체 및 구조체 포인터 복습
* Pet Management Game
* 작성일 : 2024-08-12
* 작성자 : 임나빈
*/

// typedef : 다음에 작성되는 데이터 타입을 뒤에 이름으로 별명으로 지어주는 것

#include "lectures.h"
#include "stdbool.h"

typedef struct Dog
{
	char name[30];
	int Happy;
	int Hungry;
}Dog;

typedef struct Cat
{
	char name[30];
	int Happy;
	int Hungry;
	int curious;
}Cat;

typedef struct Bird
{
	char name[30];
	int Happy;
	int Hungry;
}Bird;


void ShowStatus(Dog& dog, int& currentDay)
{
	std::cout << "개의 이름 : " << dog.name << std::endl;
	std::cout << "행복도 : " << dog.Happy << std::endl;
	std::cout << "배고픔 : " << dog.Hungry << std::endl;
	std::cout << "진행날짜 : " << currentDay << "일" << std::endl;
}
void ShowStatus(Cat& cat, int& currentDay)
{
	std::cout << "고양이의 이름 : " << cat.name << std::endl;
	std::cout << "행복도 : " << cat.Happy << std::endl;
	std::cout << "배고픔 : " << cat.Hungry << std::endl;
	std::cout << "호기심 : " << cat.curious << std::endl;
	std::cout << "진행날짜 : " << currentDay << "일" << std::endl;
}

void Play(Dog& dog)
{
	dog.Happy += 10;
	dog.Hungry -= 5;
}

void Play(Cat& cat)
{
	srand(time(NULL));
	int randomnumber = rand()%101;
	if (cat.curious < randomnumber)
	{
		std::cout << "고양이가 놀기를 거부했습니다" << std::endl;
	}
	else
	{
		cat.Happy += 10;
		cat.Hungry -= 5;
	}
}

void Feed(Dog& dog)
{
	dog.Happy += 5;
	dog.Hungry += 10;
}
void Feed(Cat& dog)
{
	dog.Happy += 5;
	dog.Hungry += 10;
	dog.curious += 10;
}

void DayEnd(Dog& dog, int& currentDay)
{
	dog.Happy -= 10;
	dog.Hungry -= 10;
	currentDay++;
}
void DayEnd(Cat& dog, int& currentDay)
{
	dog.Happy -= 10;
	dog.Hungry -= 10;
	currentDay++;
}

void MakePet(Dog& dog)
{
	std::cout << "개의 이름을 입력하세요 : ";
	std::cin >> dog.name;
	//std::cout << dog.name << std::endl;
	dog.Happy = 100;
	dog.Hungry = 100;
}

void MakePet(Cat& cat)
{
	std::cout << "고양이의 이름을 입력하세요 : ";
	std::cin >> cat.name;
	//std::cout << dog.name << std::endl;
	cat.Happy = 100;
	cat.Hungry = 100;
	cat.curious = 10;
}

void MainPlay(Dog& dog, int& currentDay)
{
	int userInput;
	while (true)
	{
		ShowStatus(dog, currentDay);
		std::cout << "1. 먹이주기" << std::endl;
		std::cout << "2. 놀아주기" << std::endl;

		std::cin >> userInput;

		if (userInput == 1)
		{
			Feed(dog);
		}
		else if (userInput == 2)
		{
			Play(dog);
		}
		DayEnd(dog, currentDay);
		if (currentDay >= 10)
			break;
	}
}

void MainPlay(Cat& cat, int& currentDay)
{
	int userInput;
	while (true)
	{
		ShowStatus(cat, currentDay);
		std::cout << "1. 먹이주기" << std::endl;
		std::cout << "2. 놀아주기" << std::endl;

		std::cin >> userInput;

		if (userInput == 1)
		{
			Feed(cat);
		}
		else if (userInput == 2)
		{
			Play(cat);
		}
		DayEnd(cat, currentDay);
		if (currentDay >= 10)
			break;
	}
}


void lecture3()
{
	// 구조체 선언하는 방법
	Dog dog;
	Cat cat;
	int selectPet;
	int currentDay = 1;

	std::cout << "펫의 종류를 선택하세요" << std::endl;
	std::cout << "1. 강아지" << std::endl;
	std::cout << "2. 고양이" << std::endl;
	std::cin >> selectPet;
	
	switch (selectPet)
	{
		case 1 :
			MakePet(dog);
			break;
		case 2 :
			MakePet(cat);
			break;
		default :
			std::cout << "잘못된 숫자를 입력했습니다" << std::endl;
	}
	
	if (selectPet == 1)
	{
		MainPlay(dog, currentDay);
	}
	else if (selectPet == 2)
	{
		MainPlay(cat, currentDay);
	}
	
	std::cout << "게임 종료!" << std::endl;
	
	

	// 구조체 포인터
	//Dog* dogPtr = &dog;

	// 동적할당 new 데이터타입 ();
	// 동적할당 해제 : delete 변수이름;
	//Dog* dogPtr2 = new Dog();
	//strcpy_s(dogPtr2->name, 30, "치코");
	//delete dogPtr2;

	//std::cout << "구조체 포인터가 가리키는 이름 : " << dogPtr2->name << std::endl;
}
