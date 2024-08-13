/*
* �н� ��ǥ : ù Ŭ���� ����. �Լ� �����ε��� ������
* �ۼ��� : 2024-08-13
* �ۼ��� : �ӳ���
*/


/*
* Ŭ���� ����
* Ŭ����(class) : ��ü - ���α׷��� ���� ���� �����ϴ� ��� ����� ǥ���ϴ� ��
*/

// 1. ��ü�� �Լ��� �����ϴ� ���� �� ���⿡ �������̴�
// struct ����ü �Լ��� ���ο� ������ �� ����
// Ŭ���� ���ο� �Լ��� �����ؼ� ��� �� �� �ִ�

#include "lectures.h"

class Dog
{
private:
	int happy;
	int hungry;
	char name[30];

public:
	Dog();
	Dog(int happy, int hungry);
	void Play();
	void Feed();
	void ShowStatus();
	void MakePet();
};

// ���� ������ �̸�����:: //namespace�ȿ� �ִ� �Լ��� ����ϰڴ�
// Ŭ����::�Լ� �̸� // Ŭ���� �ȿ� �ִ� �Լ��� ����ϰڴ�

Dog::Dog()
{
	happy = 100;
	hungry = 100;
	strcpy_s(name, 30, "�ǻ�");
}

Dog::Dog(int happy, int hungry)
{
	std::cin >> name;
	this->happy = happy;
	this->hungry = hungry;
}
void Dog::Play()
{
	happy += 10;
	hungry -= 5;
}

void Dog::Feed()
{
	happy += 5;
	hungry += 10;
}

void Dog::ShowStatus()
{
	std::cout << "���� �̸� : " << name << std::endl;
	std::cout << "���� �ູ�� : " << happy << std::endl;
	std::cout << "���� ��� : " << hungry << std::endl;
}

/// <summary>
/// Dog�� �ʱ�ȭ �Լ��̹Ƿ� �ݵ�� ������ ����� �Բ� ���Ǿ�� ��
/// </summary>
void Dog::MakePet()
{
	happy = 100;
	hungry = 100;
	strcpy_s(name, 30, "�ǻ�");
}

/*
* �Լ� �����ε�(overloading) : 1. �����ϴ� 2. �����Ͽ� �ɸ��� �ϴ�
* void Add(int a, int b)
* void Add(float a, float b)
* void Add(double a, double b)
* void Add(char a, char b)
* void Add(Dog dog1, Dog dog2)
*/

/*
* �Լ� �����ε� ��� �ÿ� �����ؾ� �� ����
* 1. �����Ϸ��� �Լ��� �����ϴ� ��� (1) �Լ��� �̸� (2) ������ ������ Ÿ�� 
*	void Add(int a);
*	void Add(int b);
*	void Add(); (o)
* 
* 2. void Print(int x);
*	 void Print(char x);
*	 void Print(double x);
*/

void Print(int x)
{
	std::cout << "int x : " << x << std::endl;
}
void Print(char x)
{
	std::cout << "char x : " << x << std::endl;
}
void Print(double x)
{
	std::cout << "double x : " << x << std::endl;
}

/*
* Ŭ���� ������ : Ŭ������ ������ �Ŀ� �ʱ�ȭ �Լ��� ������ ȣ���Ű�� ���
* 
* Dog dog1; default �����ڰ� ȣ���
* 
*/



void lecture4()
{
	// ������, ����ü ó�� ������ �����ϰ� ���� �����͸� �ʱ�ȭ���� ������ �̻��� ������ ���
	// MakeDog()�� ���� �����ؾ���
	Dog dog1;
	dog1.MakePet(); // ���������� �ݵ�� �����ϴ� ����� ������
	dog1.ShowStatus();

	// case1. �Լ� �����ε��� ���ڸ� ������� Ÿ��
	int a = 1;
	char b = 'b';
	double c = 1.1;
	Print(a);
	Print(b);
	Print(c);
	
	// case2. �Լ� �����ε��� ���� ����
	short s1 = 2;
	Print(s1);
	float f1 = 2.2f;
	Print(f1);
	
	// �Լ��� �̸��� �����ϴµ�, ������ Ÿ���� ���� ���
	// �����Ϸ��� ��� �ൿ�ϴ°�?
	// 1. ������ Ÿ���� ������ �����Ϸ��� ����ȯ�� �õ��Ѵ�
	// 2. ����� ��ȯ, ������ ��ȯ -> ������ ����ȯ�� �߻��ϰ� �ִ�
	// 3. ������ ������ Ÿ�� -> int������ ��ȯ �õ�. �Ǽ��� ������ Ÿ�� -> double ������ ��ȯ�õ� -> float������ ��ȯ�õ�
	// 4. ������ ������ Ÿ���� ���� ��쿡 �Ǽ��� ������ Ÿ���� ���������� �ٲپ �� ��ȯ �õ�

	// float -> int�� char �� ������ �����ؾ� ���� �𸥴�

	// ����
	// 1. ������ Ÿ���� ���ǵ��� �ʾҴµ� ����ߴ� -> Ÿ���� �����ε����� ���ǵ��� �ʾҾ ����� ����
	// 2. ������ ������ Ÿ���� �������� �ʰ� ������ ������ Ÿ���� �ΰ� �̻� �����Ѵ�

	// �������� ����
	Dog dog2;
	dog2.ShowStatus();
	Dog dog3 = Dog();
	dog3.ShowStatus();

	int dogHappy;
	std::cin >> dogHappy;
	int dogHungry;
	std::cin >> dogHungry;
	Dog dog4 = Dog(dogHappy, dogHungry);
	dog4.ShowStatus();

	// ������ �ִ� �ڵ�
	Dog dog5 = dog4;
	dog5.ShowStatus();

	Dog* dogs[100];
	dogs[0] = new Dog();
	//delete dogs[0];

	dogs[1] = dogs[0];
	dogs[1]->ShowStatus();
}