/*
* �н� ��ǥ : c��� ������ c++���� Ȱ���, ������(reference)�� ���� ����
* �ۼ��� : 2024-08-09
* �ۼ��� : �ӳ���
*/

/*
* �Լ��� ����� �� �����Ͱ� �ƴ� �����ڸ� ����ϸ� ���ڷ� &(�ּҿ�����)�� ������� ���� �� �ִ�
* �ּ� ���� : int*
* ������ ���� : int& ������ �̸� = �����ϰ��� �ϴ� ����;
* int a;
* int& AnotherA = a;
*/

#include "lectures.h"
#include <cstring>

void SwapInt(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// �Լ� �����ε� : C���� �Լ��� �̸����� �Լ��� ����, c++ �Լ��� �̸��� �Ű�����, ����
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void ChangeVal(int& p)
{
	p = 10;
}

int Function1() //int�� ��ȯ�ϴ� �Լ�
{
	int a = 2;
	return a;
}

// �����ڸ� �����ϴ� �Լ�
// ������� �ʵ��� ���̴� ����
int& Function2()
{
	int a = 2;
	return a;
}

int& Function3(int& a)
{
	a = 2;
	return a;
}

typedef struct Human
{
	char name[30];
	int age;
}Human;

// ������ ���۷����� ��ȯ�ϴ� �Լ�
Human& AddHumanInfo(Human& human)
{
	std::cin >> human.age;
	std::cin >> human.name;
	return human;
}

void PrintHumanInfo(Human& human)
{
	std::cout << "�̸� : " << human.name << std::endl << "���� : " << human.age << std::endl;
}

void lecture2()
{
	std::cout << "2��" << std::endl;
	
	int num = 10; // num ���� 10�̶�� ����, �ּ�
	int* numPtr = &num;
	std::cout << "�������� �ּ� : " << numPtr << std::endl;
	std::cout << "�����Ͱ� ����Ű�� �� : " << *numPtr << std::endl;

	int num1 = 1, num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1�� �� " << num1 << std::endl << "num2�� �� " << num2 << std::endl;

	// ������ ����� ��
	// ������ : ������ ����
	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1;

	std::cout << "AnotherA1�� �� " << AnotherA1 << std::endl;

	// �����ڿ� �����Ͱ� �ٸ��κ�
	// �����ʹ� �ּҿ����ڸ� ���ڷ� �ް� �ؾ��Ѵ�. ����ڰ� �Լ��� �����Ϳ� ���� ���ص��� �־�� �Ѵ�
	// �����ڴ� �ּҿ����ڸ� ���ڷ� ���� �ʴ´�.
	
	//int Cnum2;
	//std::cin >> Cnum2;
	//std::cout << "Cnum2�� �� : " << Cnum2 << std::endl;

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num1�� �� " << d_num1 << std::endl << "d_num2�� �� " << d_num2 << std::endl;

	// �����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �ؾ��Ѵ�
	// �����ڴ� ������ �� ����� �ּҸ� �����ͼ� �����Ѵ�
	int& Anotherd1 = d_num1;

	const int& literal = 100; // const Ű���带 ���ؼ� ����� ����ų �� �ְ� �ȴ�
	
	int p = 5;
	int p2 = 5;
	ChangeVal(p);
	std::cout << p << std::endl;

	//������(���۷���)�� �����ϴ� �Լ�
	int tempA = Function1(); // tempA Function �ȿ� �ִ� a���� �����ؼ� ����
	int tempB = Function3(p2); // int tempB = a;

	// ���۷��� Ÿ���� �����Ҷ��� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	const int& anotherTemp = Function1();
	int& anotherTemp2 = Function2();

	std::cout << anotherTemp2 << std::endl;

	// �Լ����� ���� ������ ��
	// int a = Function1();
	// const int& a = Function1();
	// �� const ���� �޴� a �����ڴ� ���� ���� �Ұ���

	// (2) �Լ��� �����ڸ� ������ �� int& Function();
	// ���۷��� Ÿ���� �����Ҷ��� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�

	Human human;
	PrintHumanInfo(AddHumanInfo(human));
}