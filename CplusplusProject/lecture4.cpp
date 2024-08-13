/*
* 학습 목표 : 첫 클래스 선언. 함수 오버로딩과 생성자
* 작성일 : 2024-08-13
* 작성자 : 임나빈
*/


/*
* 클래스 선언
* 클래스(class) : 객체 - 프로그래밍 언어로 세상에 존재하는 모든 대상을 표현하는 것
*/

// 1. 객체가 함수를 실행하는 것이 더 보기에 직관적이다
// struct 구조체 함수를 내부에 포함할 수 없다
// 클래스 내부에 함수를 포함해서 사용 할 수 있다

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

// 범위 지정자 이름공간:: //namespace안에 있는 함수를 사용하겠다
// 클래스::함수 이름 // 클래스 안에 있는 함수를 사용하겠다

Dog::Dog()
{
	happy = 100;
	hungry = 100;
	strcpy_s(name, 30, "뽀삐");
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
	std::cout << "개의 이름 : " << name << std::endl;
	std::cout << "개의 행복도 : " << happy << std::endl;
	std::cout << "개의 허기 : " << hungry << std::endl;
}

/// <summary>
/// Dog의 초기화 함수이므로 반드시 변수의 선언과 함께 사용되어야 함
/// </summary>
void Dog::MakePet()
{
	happy = 100;
	hungry = 100;
	strcpy_s(name, 30, "뽀삐");
}

/*
* 함수 오버로딩(overloading) : 1. 과적하다 2. 과부하에 걸리게 하다
* void Add(int a, int b)
* void Add(float a, float b)
* void Add(double a, double b)
* void Add(char a, char b)
* void Add(Dog dog1, Dog dog2)
*/

/*
* 함수 오버로딩 사용 시에 주의해야 할 사항
* 1. 컴파일러가 함수를 구별하는 방식 (1) 함수의 이름 (2) 인자의 데이터 타입 
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
* 클래스 생성자 : 클래스를 선언한 후에 초기화 함수를 강제로 호출시키는 기능
* 
* Dog dog1; default 생성자가 호출됨
* 
*/



void lecture4()
{
	// 생성자, 구조체 처음 변수를 선언하고 나서 데이터를 초기화하지 않으면 이상한 데이터 출력
	// MakeDog()를 먼저 실행해야함
	Dog dog1;
	dog1.MakePet(); // 문법적으로 반드시 강제하는 기능이 생성자
	dog1.ShowStatus();

	// case1. 함수 오버로딩에 인자를 만들어준 타입
	int a = 1;
	char b = 'b';
	double c = 1.1;
	Print(a);
	Print(b);
	Print(c);
	
	// case2. 함수 오버로딩에 없는 인자
	short s1 = 2;
	Print(s1);
	float f1 = 2.2f;
	Print(f1);
	
	// 함수의 이름은 존재하는데, 데이터 타입은 없는 경우
	// 컴파일러가 어떻게 행동하는가?
	// 1. 데이터 타입이 없으면 컴파일러는 형변환을 시도한다
	// 2. 명시적 변환, 묵시적 변환 -> 묵시적 형변환이 발생하고 있다
	// 3. 정수형 데이터 타입 -> int형으로 변환 시도. 실수형 데이터 타입 -> double 형으로 변환시도 -> float형으로 변환시도
	// 4. 정수형 데이터 타입이 없을 경우에 실수형 데이터 타입을 정수형으로 바꾸어서 형 변환 시도

	// float -> int와 char 중 무엇을 선택해야 할지 모른다

	// 정리
	// 1. 데이터 타입이 정의되지 않았는데 사용했다 -> 타입이 오버로딩으로 정의되지 않았어도 사용이 가능
	// 2. 정수형 데이터 타입을 선언하지 않고 정수형 데이터 타입을 두개 이상 선언한다

	// 생성자의 선언
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

	// 문제가 있는 코드
	Dog dog5 = dog4;
	dog5.ShowStatus();

	Dog* dogs[100];
	dogs[0] = new Dog();
	//delete dogs[0];

	dogs[1] = dogs[0];
	dogs[1]->ShowStatus();
}