/*
* �н� ��ǥ : ��������ڿ� ���� ���� �� �Ҹ���
* �ۼ��� : 2024-08-16
* �ۼ��� : �ӳ���
*/

// 1. ���� Ŭ���� �����

// 2. Ŭ���� �Ҹ���
// new Ű���尡 ���Ե� ������ ����������, new Ű����� ������ ������ �޸� ������ ���ϴ� ������
// Ŭ������ �Ҹ��ϴ� ������ ȣ��Ǵ� �Ҹ��ڸ� �����ؼ� delete Ű����� �޸� ����

// 3. ��������ڸ� �̿��ؼ� Ŭ���� ����
// �ڱ��ڽ� Ŭ������ �����ؼ� �ٸ� Ŭ����(�ν��Ͻ�)�� �����ϴ� ������

// 4. ���� ���� vs ���� ����
// ���� ���� : ���縦 �� �� �ּҸ� �״�� �����ͼ� ���� �ּҸ� ����Ű�� ���� ���
// (�ּҸ� ������ �� �ٸ� �ּҰ� ���� �޸� ������ �Ǹ� ���� �ּҸ� ����Ű�� ���� �߻�)
// ���� ���� : ������ �� �ּ��� ��쿡 �ش� ������ ���� �Ҵ����� �����ؼ� ���ο� ������ �����ϴ� ���

// ���� ���縦 ���� ���� : �ϳ��� �޸𸮷� �� �̻��� ǥ���� �� �ִ�. �޸𸮸� ������ �� ������ ���� �� �ִ�



#include "lectures.h"


class Marine
{
private:
	int hp;
	int attackPower;
	int posX;
	int posY;
	bool isDead;
	char* name;
public:
	Marine(int x, int y);
	Marine(int x, int y, const char* marineName); // Ŭ���� ����� name�� �ܺ��� marineName�� �����ϴ� ��, const -> marineName�� ������ �ʴ´�
	Marine(const Marine& m1); // ��������� ȣ�� ���
	~Marine();
	void Move(int x, int y);
	int Attack();
	void Damaged(int damage);

	void ShowStatus();
};

Marine::Marine(int x, int y)
{
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(int x, int y, const char* marineName)
{
	// char name[30] : 30�̻��� �̸� ũ�⸦ ������ �� ���� (������ ���� ���)
	// ������ ���� ��� : �����ϰ��� �ϴ� ���ڿ��� ���� ��ŭ �޸� ������ �Ҵ��ؼ� ����
	name = new char[strlen(marineName) + 1]; // strlen�� null������ ���ϱ� ������ +1 �ؾ��Ѵ�
	strcpy_s(name, strlen(marineName)+1, marineName);
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(const Marine& m1)
{
	name = new char[strlen(m1.name) + 1]; // strlen�� null������ ���ϱ� ������ +1 �ؾ��Ѵ�
	strcpy_s(name, strlen(m1.name) + 1, m1.name);
	hp = m1.hp;
	attackPower = m1.attackPower;
	posX = m1.posX;
	posY = m1.posY;
	isDead = m1.isDead;
}

Marine::~Marine()
{
	std::cout << name << "�� �Ҹ��� ȣ��!" << std::endl;
	delete[] name; // delete[] : �迭�� ��ü �޸� ����
}

void Marine::Move(int x, int y)
{
	posX = x;
	posY = y;
}

int Marine::Attack()
{
	return attackPower;
}

void Marine::Damaged(int damage)
{
	hp -= damage;
	if (hp <= 0)
		isDead = true;
	
}

void Marine::ShowStatus()
{
	std::cout << "** ���� ���� **" << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "��ġ : " << posX << ", " << posY << std::endl;
	std::cout << "���ݷ� : " << attackPower << std::endl;
	std::cout << "���� ü�� : " << hp << std::endl;
}

void lecture6()
{
	Marine marine1(1, 2, "marine1");
	marine1.ShowStatus();

	Marine marine2(5,10, "marine2");
	marine2.ShowStatus();

	std::cout << "����1�� ����2�� ����" << std::endl;
	marine2.Damaged(marine1.Attack());

	// ���� ������ ������ �ѹ��� �����غ��� -> �迭
	Marine* marines[100];
	marines[0] = new Marine(2, 3, "Marine3");
	marines[1] = new Marine(3, 5, "Marine4");
	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];
	
	int num = 10;
	int num2 = num;
	int num3(num); // num3(num) num ������ ���� num3�� ����

	std::cout << num3 << std::endl;

	//Marine�� ��������� ȣ��(����Ʈ ���������)
	Marine marine3(0, 0, "����1");
	Marine marine4 = marine3;
	Marine marine5(marine3);

	// ����Ʈ ����������� �Ѱ� : Ŭ������ ��� ������ ������ ������ �ּҸ� ����Ű�� ��쿡 ���� ����� �����Ѵ�. 
	// => ���� ����� ���ؼ� ���� �޸� �Ҹ�� �ּҸ� ã�� �� ���� ���� �߻�

	marine5.ShowStatus();


}

// 1. ���� Ŭ���� ����
// 2. �����ڿ� �Ҹ���(ü�°� �̸��� �ʱ�ȭ�ϰ�, �Ҹ��� �� �����Ҵ� �� �ּҸ� �����ϰ� �����
// 3. ��������ڸ� ��������� �ۼ��ؼ� ���� ���簡 �ƴ� ���� ���� ������� ������ �� �ְ� �ڵ� ����

class Zealot
{
private:
	int hp;
	char* name;
public:
	Zealot();
	Zealot(const Zealot& z1);
	~Zealot();
	void ShowStatus();
};

void Zealot::ShowStatus()
{
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "���� ü�� : " << hp << std::endl;
}

void lecture6_2()
{
	Zealot zealot1;
	Zealot zealot2(zealot1);

	zealot2.ShowStatus();

}

Zealot::Zealot()
{
	hp = 100;
	char temp[30];
	std::cout << "�̸��� �Է��ϼ��� : ";
	std::cin >> temp;

	name = new char[strlen(temp) + 1]; // strlen�� null������ ���ϱ� ������ +1 �ؾ��Ѵ�
	strcpy_s(name, strlen(temp) + 1, temp);

	std::cout << name << "������ ȣ��!" << std::endl;
}

Zealot::Zealot(const Zealot& z1)
{
	std::cout << "��������� ȣ��!" << std::endl;
	hp = z1.hp;
	name = new char[strlen(z1.name) + 1]; // strlen�� null������ ���ϱ� ������ +1 �ؾ��Ѵ�
	strcpy_s(name, strlen(z1.name) + 1, z1.name);
}

Zealot::~Zealot()
{
	std::cout << name << "�Ҹ��� ȣ��!" << std::endl;
}
