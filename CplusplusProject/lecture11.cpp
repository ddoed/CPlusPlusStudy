#include "lectures.h"

/*
* 1. c++ casting 연산자 예시
* 
*
* 
* 3. monster class (Goblin, Slime class) - Player 전투
* 4. 전투 결과 Reward - monster죽었을때 보상하는 아이템
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

// 2. virtual 가상 함수에 대한 이해[객체지향프로그래밍의 다형성]
//	*pure virtual : 
//	* abstract 클래스
//	* vtable

class NewPet
{
public:
	virtual void Sound() = 0; // 순수 가상 함수 -> NewPet을 상속받는 Dog, Cat에서 실행
	
};

// 순수 가상 함수 pure virtual function
// 기능 : 반드시 오버라이딩 되어야 하는 함수
// 순수 가상 함수를 포함하고 있는 클래스를 추상클래스라고 정의
// 추상 클래스는 하나 이상의 상속 필요

// c++은 왜 기본 형식으로 virtual이 선언되어 있지 않은가? : 바로 해당 함수 실행, 필요할때만 사용하는 것이 속도가 빠름

class NewDog : public NewPet
{
public:
	void Sound()
	{
		std::cout << "왈왈!" << std::endl;
	}
};

void lecture11()
{
	std::cout << "c++ casting 연산자";
	std::cout << "1. static_cast<type>" << std::endl;

	double pi = 3.140000;
	int pi_int = (int)3.14 - 0.14;
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int의 값 : " << pi_int << std::endl;
	std::cout << "pi_int2의 값 : " << pi_int2 << std::endl;

	// 첫번째, 가상함수를 이용하여 객체의 다형성 효현
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();

	AA* aPtr3 = new CC();
	// static_cast 상속관계의 클래스 표현
	BB* bPtr1 = static_cast<BB*>(aPtr2);
	bPtr1->MyBB();
	bPtr1->Show();

	BB* bPtr2 = static_cast<BB*>(aPtr3);
	bPtr2->MyBB();
	bPtr2->Show();

	// 상속 사이의 클래스의 형변환 dynamic_cast

	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if(cPtr1 != nullptr)
		cPtr1->MyCC();

	// const_cast : const 키워드를 수식받는 변수의 상수성을 없애는 변환
	
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