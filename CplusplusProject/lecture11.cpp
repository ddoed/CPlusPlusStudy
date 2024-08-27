#include "lectures.h"

/*
* 1. c++ casting ������ ����
* 
*
* 
* 3. monster class (Goblin, Slime class) - Player ����
* 4. ���� ��� Reward - monster�׾����� �����ϴ� ������
*/
class AA
{
public:
	virtual void Show()
	{
		std::cout << "AA" << std::endl;
	}
};

class BB : public AA
{
public:
	void Show()
	{
		std::cout << "BB" << std::endl;
	}

	void MyBB()
	{
		std::cout << "MyBB" << std::endl;
	}
};

class CC : public AA
{
public:
	void Show()
	{
		std::cout << "CC" << std::endl;
	}
	void MyCC()
	{
		std::cout << "MyCC" << std::endl;
	}
};

// 2. virtual ���� �Լ��� ���� ����[��ü�������α׷����� ������]
//	*pure virtual : 
//	* abstract Ŭ����
//	* vtable

class NewPet
{
public:
	virtual void Sound() = 0; // ���� ���� �Լ� -> NewPet�� ��ӹ޴� Dog, Cat���� ����
	
};

// ���� ���� �Լ� pure virtual function
// ��� : �ݵ�� �������̵� �Ǿ�� �ϴ� �Լ�
// ���� ���� �Լ��� �����ϰ� �ִ� Ŭ������ �߻�Ŭ������� ����
// �߻� Ŭ������ �ϳ� �̻��� ��� �ʿ�

// c++�� �� �⺻ �������� virtual�� ����Ǿ� ���� ������? : �ٷ� �ش� �Լ� ����, �ʿ��Ҷ��� ����ϴ� ���� �ӵ��� ����

class NewDog : public NewPet
{
public:
	void Sound()
	{
		std::cout << "�п�!" << std::endl;
	}
};

void lecture11()
{
	std::cout << "c++ casting ������";
	std::cout << "1. static_cast<type>" << std::endl;

	double pi = 3.140000;
	int pi_int = (int)3.14 - 0.14;
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int�� �� : " << pi_int << std::endl;
	std::cout << "pi_int2�� �� : " << pi_int2 << std::endl;

	// ù��°, �����Լ��� �̿��Ͽ� ��ü�� ������ ȿ��
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();

	AA* aPtr3 = new CC();
	// static_cast ��Ӱ����� Ŭ���� ǥ��
	BB* bPtr1 = static_cast<BB*>(aPtr2);
	bPtr1->MyBB();
	bPtr1->Show();

	BB* bPtr2 = static_cast<BB*>(aPtr3);
	bPtr2->MyBB();
	bPtr2->Show();

	// ��� ������ Ŭ������ ����ȯ dynamic_cast

	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if(cPtr1 != nullptr)
		cPtr1->MyCC();

	// const_cast : const Ű���带 ���Ĺ޴� ������ ������� ���ִ� ��ȯ
	
	const int num = 10;
	int* nonConstNum = const_cast<int*>(&num);
	*nonConstNum = 12;

	// reinterpret_cast
	
	int num2 = 65;
	char* charPtr = reinterpret_cast<char*>(&num2);



	// pure virtual

	NewPet* np1 = new NewDog();
	np1->Sound();
	
}