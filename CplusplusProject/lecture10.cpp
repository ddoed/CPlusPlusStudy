#include "lectures.h"

// Pet 클래스
// Dog, HuntDog, Cat : Pet을 상속하는 클래스
// (down, child, derived) // (up, parent, base)

// PetController Handler 클래스
// Has-A. Feed(Pet* pet) Play(Pet* pet)

// 1. 확장성의 문제점
// Play(Dog, Cat, Bird) 확장해야 하는 클래스 만큼 오버로딩을 해야하는 문제
// 1-2 해결 방안
// Play(Pet* pet) -> Pet 클래스 안에 있는 virtual void PlayWithMaster();
// virtual - override

// 포인터와 상속 관계
// First 클래스 타입
// Second 클래스 타입 (first 클래스 + second 고유 멤버)

// First* a = new First();
// Second* b = new First(); (x)

class First
{
private:
	char* str1;
public:
	First(const char* _str1)
	{
		str1 = new char[strlen(_str1 + 1)];
		strcpy_s(str1, strlen(str1), _str1);
	}
	virtual void SimpleFunc()
	{
		std::cout << str1 << std::endl;
	}
};

class Second : public First
{
private:
	char* str2;
public:
	Second(const char* _str1, const char* _str2) : First(_str1)
	{
		str2 = new char[strlen(_str2)+1];
		strcpy_s(str2, strlen(str2), _str2);
	}
	void SimpleFunc() override
	{
		std::cout << str2 << std::endl;
	}
};

class Handler
{
private:
	First* first;
public:
	void Show()
	{
		first->SimpleFunc();
	}
};

class Water
{
private:
	int mL;
public:
	Water(int mL) : mL(mL) {}
	virtual void Show()
	{
		std::cout << mL << "mL"<< std::endl;
	}
};

class SparklingWater : public Water
{
private:
	int sparkle;
public:
	SparklingWater(int mL, int sparkle) : Water(mL), sparkle(sparkle) {}
	void Show() override
	{
		Water::Show();
		std::cout << sparkle << std::endl;
	}
};

// c언어 형변환 (타입) 이름;
// c++언어 형변환 조건을 추가해서 연산자로 만듦
// static_cast, dynamic_cast, reinterpret_cast, const_cast

// 1. static_cast 연산자 (static : 정적인)
// 2. dynamic_cast 연산자 (dynamic_cast : 동적인)

// 첫번째. 기본 데이터 타입(primitive Tyoe) : int, double, char 등의 형변환은 무조건 static_cast

// 포인터, 참조자 사이의 형변환 연산자
// reinterpret_cast

/*
* <c++ 형변환 연산자 정리>
* - 기본 자료형의 형변환은 static_cast를 사용하라
* - 상속관계에서 형변환은 dynamic_cast를 사용하라
* - 상속관계에서 강제로 형변환 -> static_cast
* - 포인터/참조 타입에서 무조건 형변환을 강제시키려면 reinterpret_cast를 사용
*/
void lecture10()
{
	First* fptr = new First("첫번째클래스");
	fptr->SimpleFunc();

	First* sPtr = new Second("첫번째 클래스", "두번째 클래스");
	sPtr->SimpleFunc();

	//1번 예시
	std::cout << "static_cast 기본 형변환" << std::endl;
	int d = 4.12;
	char* iPtr1 = (char*)&d; // c 스타일 형변환
	// reinterpret_cast 예시
	char* iPtr2 = reinterpret_cast<char*>(&d);

	int newint = static_cast<int>(d);

	// static_cast를 사용하는 이유
	// 1. 강제 형변환을 아래 조건으로 제한하고 있다
	// 다른 타입 간의 형 변환 제한 (int <-> double <-> char)

	// 2. 부모<->자식 클래스 형변환
	// Parent* parent = new Child();
	// (Child)parent;

	// dynamic_cast 연산자
	// 상속관계에서의 형변환을 안전하게 처리할 수 있는 연산자
	// static cast의 경우에는 형변환이 불가능한 경우에도 컴파일 허용 -> 불안전한 방식
	// dynamic cast 사용

	// const_cast 연산자
	// 실수 키워드로 선언한 변수를 비 상수로 변경하는 연산자


	std::cout << "부모 자식 형변환 예시" << std::endl;

	Water* water = new SparklingWater(100, 10);
	water->Show();
	SparklingWater* spWater = dynamic_cast<SparklingWater*>(water);
	spWater->Show();

	Water* water2 = new Water(150);
	SparklingWater* spWater2 = dynamic_cast<SparklingWater*>(water2);
	if(spWater2 != nullptr)
		spWater2->Show();

	// spWater2를 static_cast로 형변환하면 그대로 컴파일 에러가 발생한다.
	// spWater2를 dynamic_cast로 형변환을 해서 그 결과갑이 형변환이 불가능하면 nullPtr을 반환한다
}