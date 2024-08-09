/*
* �н���ǥ : c++ ��� �н�. c���� ��� ������ �����غ���
* �ۼ��� : 2024-08-08
* �ۼ��� : �ӳ���
*/

/*
* Hello World ������ִ� �Լ� <- ����� �Լ� : printf, scanf
* Hello World ������ִ� �Լ� <- ����� �Լ� : <iostream> cout, cin
* cout : ��� �Լ�
* ���� std::cout << "Hello World" << std::endl;
* cin : �Է��Լ�
* int num;
* ���� std::cin >> num;
*/

/*
* 1. std::cout << " "
* namespace �̸����� : � ���ǵ� ��ü�� ��� �ҼӵǾ��ִ��� �˷��ش�
* std�� c++ standard library�� ��ϵ� �Լ�. C++ ǥ�� ���̺귯���� ��� �Լ��� ���ǵ� �̸�����
*/

/*
* �Լ�, ������ �ۼ��ϴµ� �ٸ� ����� �� �ڵ带 ������ ���鼭 �ߺ��� �̸��� ���� �Լ��� ����� Ȯ���� ������
* c++ �������� �̸� �����ϱ� ���ؼ� namespace��� ���� ����
* ���� namespace (�̸�����)�̸� { }
*/

/*
* ���� ���� ������ '::'
* ���� : �̸�����::���� �Ǵ� �Լ�;
* �̸������ȿ� �ִ� ���� �Ǵ� �Լ� ��� ����
* ���࿡ �̸� ������ �ʹ� ���
* using Ű����
* using TODAYISTUIRSDAY::num;
*/


/*
* 1. ���� : int, char, float, double
* 2. �ݺ���, ���ǹ� : for�ݺ���, while�ݺ���, if, switch ���ǹ�
* 3. ������(����) : int*, char*, &num, &a1, *num, *a1
*/

#include "lectures.h"
#include "cstring"

using std::cout;
using std::endl;

//using namespace TODAYISTHURSDAY;
// �� ������ �ȿ��� ����ϴ� ��� ���� �Ǵ� �Լ��� using namespace�̸��� ����ض�
// ���� : �̸��� �� namespace�� ���� �Է¾��ص� �ȴ�
// ���� : namespace �ȿ� ������ �Լ��� ���� ����, �ٸ� �Լ��� ��ġ�� ��찡 ����

// ��� ��õ��
// using namespace�� �̿��ؼ� ��� ������ �����ϴ� ����� ����
//�ʿ��� �Լ��� �����ؼ� ���

namespace CPP
{
	void Sample()
	{
		std::cout << "Sample!"<<std::endl;
	}
}

namespace CPP2
{
	void Sample()
	{
		std::cout << "Sample2!"<<std::endl;
	}
}

namespace YNB
{
	int age;
	char name[30];
	void PrintMyName()
	{
		cout << "�� �̸��� " << name << "�Դϴ�.\n";
		cout << "���̴� " << age << "�Դϴ�\n";
	}
}

namespace TODAYISTHURSDAY
{
	int num;
	int num2;
}

using TODAYISTHURSDAY::num;

// std::in ���ӽ����̽� ����غ���
// ���ڸ��߱� ������ ����

void lecture1()
{
	cout << "Hello World" << endl;
	cout << "Hello World\n";

	CPP::Sample();
	CPP2::Sample();
	
	// �̸��� ������ :: namespace
	strcpy_s(YNB::name, 30, "�ӳ���");
	YNB::age = 20;
	YNB::PrintMyName();


	//���� ���߱� ����
	int LuckyNumber = 5;
	int UserInput;
	
	while (true)
	{
		std::cout << "���� ���ڸ� ���߾� ������ : ";
		std::cin >> UserInput;

		if (LuckyNumber == UserInput)
		{
			std::cout << "������ ���߾����ϴ�" << std::endl;
			break;
		}
		else
		{
			std::cout << "�����Դϴ�. �ٽ� �Է��ϼ���" << std::endl;
		}
	}


}


