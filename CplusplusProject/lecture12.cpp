#include "lectures.h"

/*
* template Ű���� - �Ϲ�ȭ �ڵ�
* �Լ� ���ø�
* Ŭ���� ���ø�
*/

/*
* template �� ����ϴ°�? -> �ѹ��� int, double, ... ǥ���ϴ� ����� ������?
*/

template <typename T1, typename T2>
void ShowData(double t1, double t2)
{
	std::cout << (T1)t1 << (T2)t2 << std::endl;
}

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

/*
* �Լ� ���ø��� ����ȭ
*/

template <>
char Add(char num1, char num2)
{
	std::cout << num1 << num2 << std::endl;
	return 0;
}

template <typename P>
P Minus(P num1, P num2)
{
	return num1 - num2;
}

template <typename T>
T Divid(T num1, T num2)
{
	return num1 / num2;
}

// template <class T> ��õX

template <typename T>
T Max(T t1, T t2)
{
	return t1 < t2 ? t2 : t1;
}

template <>
const char* Max(const char* c1, const char* c2)
{
	return (strlen(c1) > strlen(c2)) ? c1 : c2;
}

// nontype ���ø�
template <typename T, int val>
T AddValue(T const& curValue)
{
	return curValue + val;
}

const int EVENTMONEY = 1000;
const int EVENTEXP = 100;

void lecture12()
{
	std::cout << Add(3, 5) << std::endl;
	std::cout << Add<char>(32, 32) << std::endl;

	ShowData<float, int>(3.2, 4.5);

	std::cout << Divid<int>(6, 1) << std::endl;

	std::cout << "Add ���ø� �Լ��� ����ȭ " << std::endl;
	Add<char>(97, 98);

	std::cout << Max<const char*>("aa", "b") << std::endl;

	float myExp = 1.1f;
	int myMoney = 100;

	std::cout << AddValue<float, EVENTEXP>(myExp) << std::endl;
	std::cout << AddValue<int, EVENTMONEY>(myMoney) << std::endl;
	
}