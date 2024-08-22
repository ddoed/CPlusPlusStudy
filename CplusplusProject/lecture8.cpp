#include "lectures.h"
#include <string>

/*
* 학습 목표 : c++ 상속 기본 문법
* 작성일 : 2024-08-22
* 작성자 : 임나빈
*/

/*
* 상속(inheritance)
* 부모(클래스) <-> 자식(클래스) : public 함수를 선언해서 멤버 변수 사용
*/

/*
* 상속에서 자주 사용되는 용어 정리
* 상속을 해주는 클래스 vs 상속을 받는 클래스
* 부모(parent) vs 자식(child)
* 기반(base) vs 유도, 파생(defrived)
* 슈퍼(super) vs 서브(sub)
* 상위 vs 하위
*/

/*
* 상속의 기본 기능 : 부모 클래스(상속 하는 클래스)를 중복하지 않고 사용할 수 있는 문법
* 클래스의 생성자 소멸자
*/

/*
* 접근 지정자
* public : public 범위보다 큰 모든 멤버의 접근 허용(private 이외의 모든 접근 허용)
* private : 자신 클래스 이외의 모든 클래스의 접근을 막는다. 자식도 접근 제한
* protected : 기본적으로 private와 용도가 같은데, 클래스가 상속되었을 때 자식 클래스의 접근을 허용하는 범위
* c++ 특별한 상속 문법 : 다중 상속, 이중 상속 문제를 접근 지정자로 해결하기 위해서 private protected 상속이 존재
*/

/*
* 상속의 세가지 방법 : public 상속, private 상속, protected 상속
* public 상속 : private 이외의 모든 접근을 허용. 부모가 갖고있는 접근지정자와 동일하게 가져온다
* protected 상속 : private 이외의 모든 접근을 protected 접근으로 변경한다
* private 상속 : 모든 접근 지정자를 private로 변경한다. 재상속하는 이유가 없어지는 상속방법.
*/


/*
* 상속을 언제 해야하는가?
* IS-A : A is B인가? child(parent + 추가적으로 child 구현된 기능)가 parent 인가?
* EBook은 책이다. 책은 클래스 정의 Ebook 책의 내용을 상속받을 수 있다.
* 
* HAS-A : A가 B를 소유하고 있다. Police(자식)가 Gun(부모)을 소
*/

//class Book
//{
//private:
//	char* title;
//	int price;
//public:
//	Book(char* title, int price) : price(price)
//	{
//		// this->price = price;
//		title = new char[strlen(title) + 1];
//		strcpy_s(this->title, strlen(title) + 1, title);
//	}
//	Book(int price, std::string name) : price(price), name(name) {}
//	~Book()
//	{
//		delete[] title;
//	}
//	void ShowBookInfo() const
//	{
//		std::cout << "제목 : " << title << std::endl;
//		std::cout << "가격 : " << price << std::endl;
//	}
//};
//
//class Ebook : public Book
//{
//private:
//	char* DRMkey;
//public:
//	Ebook(int price, char* title, char* key) : Book(price, title)
//	{
//		DRMkey = new char[strlen(key) + 1];
//		strcpy_s(DRMkey, strlen(title) + 1, title);
//	}
//	void ShowBookInfo() const
//	{
//		ShowBookInfo();
//		std::cout << "DRMkey 값 : " << "wastddfg" << std::endl;
//	}
//};

class Gun
{
protected:
	int bulletCount;
public:
	Gun(int bullet)
	{
		bulletCount = bullet;
	}
	void Shot()
	{
		bulletCount--;
		std::cout << "발사!" << std::endl;
	}
};

class Police
{
private:
	Gun* gun;
public:
	Police()
	{
		gun = new Gun(10);
	}
	void Shot()
	{
		gun->UseGun();
		std::cout << "발사!" << std::endl;

	}
};

class base
{
private:
	int num1;
protected:
	int num3;
public:
	base(int value, int value3) : num1(value) , num3(value3) {} // 멤버 이니셜라이저
	base()
	{
		std::cout << "base() 생성자 호출!" << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "base()" << num1 << std::endl;
	}
	~base()
	{
		std::cout << "base() 소멸자 호출!" << std::endl;
	}
};

class derived : public base
{
private:
	int num2;
public:
	derived(int value) : num2(value) {}
	derived()
	{
		std::cout << "derived() 생성자 호출!" << std::endl;
	}
	void dPrint()
	{
		num3 = 1;
		num2 = 2;
		std::cout << "derived()" << num2 <<num3<< std::endl;
	}
	~derived()
	{
		std::cout << "derived() 소멸자 호출!" << std::endl;
	}
};

class parent
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
};

class child : protected parent
{
	
};

// 예제문제
class Rectangle
{
private:
	int width;
	int height;
	
public:
	Rectangle(int width, int height) : width(width), height(height) {}
	void ShowAreaInfo()
	{
		std::cout << "넓이 : " << width * height << std::endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size,size) {}
};

void lecture8()
{
	base b1(1,3);
	b1.Print();

	derived d1; // 자식 클래스는 생성될 때 부모 클래스도 같이 생성해야 한다
	d1.dPrint();
	d1.Print();


	Rectangle re(2, 4);
	re.ShowAreaInfo();
	Square sq(5);
	sq.ShowAreaInfo();

	// protected 상속
	parent p1;
	p1.num3 = 10;
	child c1;
	// c1.num3 = 100;

	Ebook ebook(10000, "C++ 예제문제", "ewrerered");
}