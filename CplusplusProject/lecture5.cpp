#include "lectures.h"

/*
* 학습목표 : 클래스(객체지향 프로그래밍)의 특징
* 작성일 : 2024-08-14
* 작성자 : 임나빈
*/

// 프로그래머를 제한하는 것이 클래스가 갖고 있는 특징
// 1. 생성자 : 프로그래머가 실수로 초기화하지 않고 데이터를 사용하는 것을 원천적으로 막기 위한 기능
// 2. 정보은닉 : 접근지정자를 통해서 프로그래머가 데이터를 안전하게 보장할 수 있는 기능 (숨기는 기능)
// 멤버 변수를 private으로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서 안전한 형태로 멤버 변수의 접근을 유도하는 것을 의미
// 좋은 클래스를 작성하기 위한 기본 조건 : 정보은닉(은닉성), 캡슐화
// 3. 캡슐화
// (1) 사용자(유저)가 그 함수가 무엇을 하는지 알 필요가 있다
// (2) 작성자(프로그래머) 입장에서 코드를 작성하는데 필요한 함수를 그냥 호출하면 됨

class SiniveCap
{
public:
	void Take()
	{
		std::cout << "콧물약을 복용했습니다" << std::endl;
	}
};

class SneezeCap
{
public:
	void Take()
	{
		std::cout << "감기약을 복용했습니다" << std::endl;
	}
};

class Capsule100
{
private:
	SiniveCap sc;
	SneezeCap sz;
public:
	void Take()
	{
		sc.Take();
		sz.Take();
	}
};

class Patient
{
public:
	void TakeCapsule(Capsule100& capsule)
	{
		capsule.Take();
	}
};

class Date
{
private:
	int day;
	int month;
	int year;
public:
	void ChangeDay(int x);
	void ChangeMonth(int x);
	void ChangeYear(int x);
	void ChangeDate(int year, int month, int day);
	Date();
	Date(int day, int month, int year);
	void ShowDate();
};

void Date::ChangeDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;

}
void Date::ChangeDay(int x)
{
	if (x > 31)
	{
		std::cout << "일은 31일을 넘을 수 없습니다." << std::endl;
		std::cout << "따라서 해당기능을 실행할 수 없습니다" << std::endl;
		return;
	}
	day = x;
}

void Date::ChangeMonth(int x)
{
	month = x;
}

void Date::ChangeYear(int x)
{
	year = x;
}

void Date::ShowDate()
{
	std::cout << "오늘은 " << year << "년 " << month << "월 " << day << "일 입니다." << std::endl;
}

Date::Date()
{
	day = 14;
	month = 8;
	year = 2024;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

class Point
{
private:
	int x;
	int y;
public:
	Point();
	int GetX() const;
	int GetY() const;
	void ShowPoint() const;
};

int Point::GetX() const {
	return x;
}

int Point::GetY() const {
	return y;
}

// const 함수에 대한 설명
// (반환값) 함수이름() const; 형식으로 지정
// const keyword 수식받는 함수는 멤버 변수의 값이 변경되지 않음을 보장하는 키워드

class Rectangle
{
private:
	Point leftDown;
	Point rightUp;
	int areaSize;
public:
	Rectangle();
	int CalculateArea();
	void ShowRectInfo();
	
};

Point::Point()
{
	std::cout << "x의 좌표를 입력 : ";
	std::cin >> x;
	std::cout << "y의 좌표를 입력 : ";
	std::cin >> y;
}

void Point::ShowPoint() const
{
	std::printf("(%d, %d)\n", GetX(), GetY());
}

// 멤버 이니셜라이저를 이용한 멤버 초기화 방법
// 멤버 이니셜라이저는 멤버변수로 선언된 객체의 생성자 호출을 활용하는 방법
Rectangle::Rectangle() :leftDown(), rightUp() 
{
	areaSize = CalculateArea();
}

int Rectangle::CalculateArea()
{
	int row = rightUp.GetX() - leftDown.GetX();
	int col = rightUp.GetY() - leftDown.GetY();
	return row * col;
}

void Rectangle::ShowRectInfo()
{
	leftDown.ShowPoint();
	rightUp.ShowPoint();
	std::cout << "사각형의 넓이 : " << areaSize << std::endl;
}

class Circle
{
private:
	float radius;
	const float PI = 3.14f;
	Point center;
	float AreaSize;
public:
	Circle();
	float GetRadius();
	float CalCircleArea();
	void ShowCircleInfo();
};

Circle::Circle(): center()
{
	std::cout << "반지름 입력 : ";
	std::cin >> radius;
	AreaSize = CalCircleArea();
}

float Circle::GetRadius()
{
	return radius;
}

float Circle::CalCircleArea()
{
	return radius * radius * PI;
}

void Circle::ShowCircleInfo()
{
	center.ShowPoint();
	std::cout << "원의 넓이 : " << AreaSize << std::endl;
}

void lecture5()
{
	Date date1;
	date1.ShowDate();

	Date date2 = Date(15, 8, 2024);
	date2.ChangeDay(16);
	date2.ShowDate();

	Date date3 = Date(15, 8, 2024);
	date3.ChangeDate(2025, 8, 15);
	date3.ShowDate();
	
	Patient p1;
	Capsule100 capsule;
	p1.TakeCapsule(capsule);

	// 사각형 클래스 호출
	Rectangle rect1;
	rect1.ShowRectInfo();

	Circle c1;
	c1.ShowCircleInfo();
}