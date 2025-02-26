/*
* 학습 목표 : 복사생성자에 대한 이해 및 소멸자
* 작성일 : 2024-08-16
* 작성자 : 임나빈
*/

// 1. 몬스터 클래스 만들기

// 2. 클래스 소멸자
// new 키워드가 포함된 생성자 구현했을때, new 키워드로 생성한 변수의 메모리 해제를 못하는 문제점
// 클래스가 소멸하는 시점에 호출되는 소멸자를 구현해서 delete 키워드로 메모리 해제

// 3. 복사생성자를 이용해서 클래스 복사
// 자기자신 클래스를 복사해서 다른 클래스(인스턴스)에 복사하는 생성자

// 4. 얕은 복사 vs 깊은 복사
// 얕은 복사 : 복사를 할 때 주소를 그대로 가져와서 같은 주소를 가리키는 복사 방식
// (주소를 복사할 때 다른 주소가 먼저 메모리 해제가 되면 없는 주소를 가리키는 에러 발생)
// 깊은 복사 : 복사할 때 주소인 경우에 해당 공간을 동적 할당으로 복사해서 새로운 공간을 복사하는 방식

// 얕은 복사를 쓰는 이유 : 하나의 메모리로 둘 이상을 표현할 수 있다. 메모리를 해제할 때 문제가 있을 수 있다



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
	Marine(int x, int y, const char* marineName); // 클래스 멤버인 name을 외부의 marineName로 복사하는 것, const -> marineName이 변하지 않는다
	Marine(const Marine& m1); // 복사생성자 호출 방식
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
	// char name[30] : 30이상의 이름 크기를 복사할 수 없다 (정적인 복사 방식)
	// 동적인 복사 방식 : 복사하고자 하는 문자열의 길이 만큼 메모리 공간을 할당해서 생성
	name = new char[strlen(marineName) + 1]; // strlen은 null포함을 안하기 때문에 +1 해야한다
	strcpy_s(name, strlen(marineName)+1, marineName);
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(const Marine& m1)
{
	name = new char[strlen(m1.name) + 1]; // strlen은 null포함을 안하기 때문에 +1 해야한다
	strcpy_s(name, strlen(m1.name) + 1, m1.name);
	hp = m1.hp;
	attackPower = m1.attackPower;
	posX = m1.posX;
	posY = m1.posY;
	isDead = m1.isDead;
}

Marine::~Marine()
{
	std::cout << name << "의 소멸자 호출!" << std::endl;
	delete[] name; // delete[] : 배열을 전체 메모리 해제
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
	std::cout << "** 마린 생성 **" << std::endl;
	std::cout << "이름 : " << name << std::endl;
	std::cout << "위치 : " << posX << ", " << posY << std::endl;
	std::cout << "공격력 : " << attackPower << std::endl;
	std::cout << "현재 체력 : " << hp << std::endl;
}

void lecture6()
{
	Marine marine1(1, 2, "marine1");
	marine1.ShowStatus();

	Marine marine2(5,10, "marine2");
	marine2.ShowStatus();

	std::cout << "마린1이 마린2를 공격" << std::endl;
	marine2.Damaged(marine1.Attack());

	// 여러 마리의 마린을 한번에 생성해본다 -> 배열
	Marine* marines[100];
	marines[0] = new Marine(2, 3, "Marine3");
	marines[1] = new Marine(3, 5, "Marine4");
	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];
	
	int num = 10;
	int num2 = num;
	int num3(num); // num3(num) num 데이터 복사 num3에 대입

	std::cout << num3 << std::endl;

	//Marine형 복사생성자 호출(디폴트 복사생성자)
	Marine marine3(0, 0, "마린1");
	Marine marine4 = marine3;
	Marine marine5(marine3);

	// 디폴트 복사생성자의 한계 : 클래스의 멤버 변수로 포인터 변수가 주소를 가리키는 경우에 얕은 복사로 복제한다. 
	// => 얕은 복사로 인해서 기존 메모리 소멸시 주소를 찾을 수 없는 문제 발생

	marine5.ShowStatus();


}

// 1. 질럿 클래스 생성
// 2. 생성자와 소멸자(체력과 이름을 초기화하고, 소멸할 때 동적할당 한 주소를 해제하게 만들것
// 3. 복사생성자를 명시적으로 작성해서 얕은 복사가 아닌 깊은 복사 방식으로 복사할 수 있게 코드 변경

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
	std::cout << "이름 : " << name << std::endl;
	std::cout << "현재 체력 : " << hp << std::endl;
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
	std::cout << "이름을 입력하세요 : ";
	std::cin >> temp;

	name = new char[strlen(temp) + 1]; // strlen은 null포함을 안하기 때문에 +1 해야한다
	strcpy_s(name, strlen(temp) + 1, temp);

	std::cout << name << "생성자 호출!" << std::endl;
}

Zealot::Zealot(const Zealot& z1)
{
	std::cout << "복사생성자 호출!" << std::endl;
	hp = z1.hp;
	name = new char[strlen(z1.name) + 1]; // strlen은 null포함을 안하기 때문에 +1 해야한다
	strcpy_s(name, strlen(z1.name) + 1, z1.name);
}

Zealot::~Zealot()
{
	std::cout << name << "소멸자 호출!" << std::endl;
}
