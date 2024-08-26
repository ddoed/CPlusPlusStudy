#include "lectures.h"

/*
* 클래스 상속
* 1. class Parent{};
* 2. class Child : public Parent{}
*/

/*
* class Pet
* hungry, happy
* 
* dog, cat, bird 추가 컨텐츠 : pet 클래스 상속 받는 클래스 구현
*/

// 몬스터 : 추상적인 개념의 객체

/*
* 객체 포인터 참조관계
* c++에서 포인터 변수는 해당 객체를 직접 혹은 간접적으로 가르킬 수 있다.
* Dog : public Pet
* Pet* pet;
* Pet* dog;
* Dog* dog;
* Dog* pet; // 컴파일 에러 : 문법적으로 자식 클래스 포인터가 부모 클래스를 직접 가리키는 것을 막아두었다 -> 형변환
*/

/*
* 정리 : 클래스의 확장성에 대한 문제를 개선하기 위한 방안1. <-> 시간
* Dog클래스 Cat클래스 Play(Dog* dog) Play(Cat* cat) Feed 함수로 표현
* Cat과 Dog를 동시에 상속하는 Pet클래스를 인자로 넘겨준다
* Play(Pet* pet)
*/

/*
* 부모 클래스 인자로 사용해서 범용성 있는 함수를 구현하였다
* void Play(Pet* pet) -> pet을 상속받는 모든 클래스를 범용적으로 표현가능하게 함
* -> 부모가 갖고 있는 함수를 자식 버전으로 변경하고 싶다
* 가상 함수, override 키워드
* virtual 키워드 -> 가상함수
* override 키워드 -> virtual과 함께 사용된다
*/

class Pet // 플레이어가 추상적인 대상으로 접근할 수 있는 객체
{
protected:
	int hungry;
	int happy;
public:
	Pet() {};
	Pet(int hungry, int happy) : hungry(hungry), happy(happy)
	{
		std::cout << "Pet을 생성했습니다" << std::endl;
	}
	void ShowInfo()
	{
		std::cout << "배고픔 : " << hungry << std::endl;
		std::cout << "행복도 : " << happy << std::endl;
	}

	virtual void PlayWithMaster()
	{
		std::cout << "펫과 놀아주었다" << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

class Dog2 : public Pet
{
public:
	Dog2() {}
	Dog2(int hungry, int happy) : Pet(hungry, happy)
	{
		std::cout << "Dog를 생성했습니다" << std::endl;
	}
	virtual void PlayWithMaster() override
	{
		std::cout << "개와 놀아주었다." << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

class HuntDog : public Dog2
{
public:
	HuntDog() {}
	HuntDog(int hungry, int happy) : Dog2(hungry, happy)
	{
		std::cout << "HuntDog를 생성했습니다" << std::endl;
	}
	void PlayWithMaster() override
	{
		std::cout << "사냥개와 놀아주었다." << std::endl;
		hungry -= 10;
		happy += 5;
	}
	void Hunting()
	{
		std::cout << "사냥개가 사냥을 합니다" << std::endl;
	}
};

class Cat2 : public Pet
{
private:
	int curious;
public:
	Cat2() {}
	Cat2(int hungry, int happy, int curious) : Pet(hungry, happy)
	{
		this->curious = curious;
		std::cout << "Cat을 생성했습니다" << std::endl;
	}
	void Hide()
	{
		std::cout << "고양이가 숨었습니다" << std::endl;
	}
};

class PetController
{
private:
	Pet* myPet;
	int money;
	int ActivePoint;

	void UseActivePoint()
	{
		std::cout << "행동력을 1 소모했습니다." << std::endl;
		ActivePoint--;
		std::cout << "남은 행동력 : " << ActivePoint << std::endl;
	}

public:
	PetController() {}; // 디폴트 생성자
	PetController(Pet* pet, int money, int AP) : money(money), ActivePoint(AP)
	{
		myPet = pet;
	}

	void EarnMoney(int pay)
	{
		std::cout << pay << "만큼 돈을 획득했습니다." << std::endl;
		
		money += pay;
	}

	void Play()
	{
		myPet->PlayWithMaster();
		UseActivePoint();
	}

	// Pet 클래스를 이용해서 고유 함수를 실행시키고 싶다
	// Pet을 고유 클래스로 타입 변환 시키고 싶다
	// 모든 Pet이 상속받는 하나의 자식클래스로 변활할 수 없다
	// 조건 필요

	// c언어 형변환 (타입) 이름;
	// c++언어 형변환 조건을 추가해서 연산자로 만듦
	// static_cast, dynamic_cast, reinterpret_cast, const_cast

	void Play2()
	{
		HuntDog* huntDog = dynamic_cast<HuntDog*>(myPet);
		if(huntDog != nullptr)
			huntDog->Hunting();

		Cat2* cat = dynamic_cast<Cat2*>(myPet);
		if (cat != nullptr)
			cat->Hide();
	}

	void ShowInfo()
	{
		std::cout << "소지 금액 : " << money << std::endl;
		std::cout << "남은 행동력 : " << ActivePoint << std::endl;
		std::cout << "-------펫의 정보--------" << std::endl;
		myPet->ShowInfo();
	}


};

void lecture9()
{
	Pet pet(100,100);
	Dog2 dog(100, 100);
	HuntDog hdog(100, 100);
	Cat2 cat(100, 100,100);
	PetController player(&cat,5000, 3);
	player.Play();
	player.ShowInfo();

	PetController p2(&hdog, 1000, 3);
	p2.Play();
	p2.ShowInfo();

	p2.Play2();
	player.Play2();
}