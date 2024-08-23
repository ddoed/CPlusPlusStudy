#include "lectures.h"

/*
* Ŭ���� ���
* 1. class Parent{};
* 2. class Child : public Parent{}
*/

/*
* class Pet
* hungry, happy
* 
* dog, cat, bird �߰� ������ : pet Ŭ���� ��� �޴� Ŭ���� ����
*/

// ���� : �߻����� ������ ��ü

/*
* ��ü ������ ��������
* c++���� ������ ������ �ش� ��ü�� ���� Ȥ�� ���������� ����ų �� �ִ�.
* Dog : public Pet
* Pet* pet;
* Pet* dog;
* Dog* dog;
* Dog* pet; // ������ ���� : ���������� �ڽ� Ŭ���� �����Ͱ� �θ� Ŭ������ ���� ����Ű�� ���� ���Ƶξ��� -> ����ȯ
*/

/*
* ���� : Ŭ������ Ȯ�强�� ���� ������ �����ϱ� ���� ���1. <-> �ð�
* DogŬ���� CatŬ���� Play(Dog* dog) Play(Cat* cat) Feed �Լ��� ǥ��
* Cat�� Dog�� ���ÿ� ����ϴ� PetŬ������ ���ڷ� �Ѱ��ش�
* Play(Pet* pet)
*/

/*
* �θ� Ŭ���� ���ڷ� ����ؼ� ���뼺 �ִ� �Լ��� �����Ͽ���
* void Play(Pet* pet) -> pet�� ��ӹ޴� ��� Ŭ������ ���������� ǥ�������ϰ� ��
* -> �θ� ���� �ִ� �Լ��� �ڽ� �������� �����ϰ� �ʹ�
* ���� �Լ�, override Ű����
* virtual Ű���� -> �����Լ�
* override Ű���� -> virtual�� �Բ� ���ȴ�
*/

class Pet // �÷��̾ �߻����� ������� ������ �� �ִ� ��ü
{
protected:
	int hungry;
	int happy;
public:
	Pet() {};
	Pet(int hungry, int happy) : hungry(hungry), happy(happy)
	{
		std::cout << "Pet�� �����߽��ϴ�" << std::endl;
	}
	void ShowInfo()
	{
		std::cout << "����� : " << hungry << std::endl;
		std::cout << "�ູ�� : " << happy << std::endl;
	}

	virtual void PlayWithMaster()
	{
		std::cout << "��� ����־���" << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

class Dog2 : public Pet
{
public:
	Dog2() {}
	Dog2(int hungry, int happy) : Pet(hungry, happy)
	{
		std::cout << "Dog�� �����߽��ϴ�" << std::endl;
	}
	virtual void PlayWithMaster() override
	{
		std::cout << "���� ����־���." << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

class HuntDog : public Dog2
{
public:
	HuntDog() {}
	HuntDog(int hungry, int happy) : Dog2(hungry, happy)
	{
		std::cout << "HuntDog�� �����߽��ϴ�" << std::endl;
	}
	void PlayWithMaster() override
	{
		std::cout << "��ɰ��� ����־���." << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

class Cat2 : public Pet
{
private:
	int curious;
public:
	Cat2() {}
	Cat2(int hungry, int happy, int curious) : Pet(hungry, happy)
	{
		this->curious = curious;
		std::cout << "Cat�� �����߽��ϴ�" << std::endl;
	}
};

class PetController
{
private:
	Pet* myPet;
	int money;
	int ActivePoint;

	void UseActivePoint()
	{
		std::cout << "�ൿ���� 1 �Ҹ��߽��ϴ�." << std::endl;
		ActivePoint--;
		std::cout << "���� �ൿ�� : " << ActivePoint << std::endl;
	}

public:
	PetController() {}; // ����Ʈ ������
	PetController(Pet* pet, int money, int AP) : money(money), ActivePoint(AP)
	{
		myPet = pet;
	}

	void EarnMoney(int pay)
	{
		std::cout << pay << "��ŭ ���� ȹ���߽��ϴ�." << std::endl;
		
		money += pay;
	}

	void Play()
	{
		myPet->PlayWithMaster();
		UseActivePoint();
	}

	void ShowInfo()
	{
		std::cout << "���� �ݾ� : " << money << std::endl;
		std::cout << "���� �ൿ�� : " << ActivePoint << std::endl;
		std::cout << "-------���� ����--------" << std::endl;
		myPet->ShowInfo();
	}


};

void lecture9()
{
	Pet pet(100,100);
	Dog2 dog(100, 100);
	HuntDog hdog(100, 100);
	PetController player(&pet,5000, 3);
	player.Play();
	player.ShowInfo();

	PetController p2(&dog, 1000, 3);
	p2.Play();
	p2.ShowInfo();
}