/*
* �н� ��ǥ : c++�� ����ü �� ����ü ������ ����
* Pet Management Game
* �ۼ��� : 2024-08-12
* �ۼ��� : �ӳ���
*/

// typedef : ������ �ۼ��Ǵ� ������ Ÿ���� �ڿ� �̸����� �������� �����ִ� ��

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
	std::cout << "���� �̸� : " << dog.name << std::endl;
	std::cout << "�ູ�� : " << dog.Happy << std::endl;
	std::cout << "����� : " << dog.Hungry << std::endl;
	std::cout << "���೯¥ : " << currentDay << "��" << std::endl;
}
void ShowStatus(Cat& cat, int& currentDay)
{
	std::cout << "������� �̸� : " << cat.name << std::endl;
	std::cout << "�ູ�� : " << cat.Happy << std::endl;
	std::cout << "����� : " << cat.Hungry << std::endl;
	std::cout << "ȣ��� : " << cat.curious << std::endl;
	std::cout << "���೯¥ : " << currentDay << "��" << std::endl;
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
		std::cout << "����̰� ��⸦ �ź��߽��ϴ�" << std::endl;
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
	std::cout << "���� �̸��� �Է��ϼ��� : ";
	std::cin >> dog.name;
	//std::cout << dog.name << std::endl;
	dog.Happy = 100;
	dog.Hungry = 100;
}

void MakePet(Cat& cat)
{
	std::cout << "������� �̸��� �Է��ϼ��� : ";
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
		std::cout << "1. �����ֱ�" << std::endl;
		std::cout << "2. ����ֱ�" << std::endl;

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
		std::cout << "1. �����ֱ�" << std::endl;
		std::cout << "2. ����ֱ�" << std::endl;

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
	// ����ü �����ϴ� ���
	Dog dog;
	Cat cat;
	int selectPet;
	int currentDay = 1;

	std::cout << "���� ������ �����ϼ���" << std::endl;
	std::cout << "1. ������" << std::endl;
	std::cout << "2. �����" << std::endl;
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
			std::cout << "�߸��� ���ڸ� �Է��߽��ϴ�" << std::endl;
	}
	
	if (selectPet == 1)
	{
		MainPlay(dog, currentDay);
	}
	else if (selectPet == 2)
	{
		MainPlay(cat, currentDay);
	}
	
	std::cout << "���� ����!" << std::endl;
	
	

	// ����ü ������
	//Dog* dogPtr = &dog;

	// �����Ҵ� new ������Ÿ�� ();
	// �����Ҵ� ���� : delete �����̸�;
	//Dog* dogPtr2 = new Dog();
	//strcpy_s(dogPtr2->name, 30, "ġ��");
	//delete dogPtr2;

	//std::cout << "����ü �����Ͱ� ����Ű�� �̸� : " << dogPtr2->name << std::endl;
}
