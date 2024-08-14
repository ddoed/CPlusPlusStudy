#include "lectures.h"

/*
* �н���ǥ : Ŭ����(��ü���� ���α׷���)�� Ư¡
* �ۼ��� : 2024-08-14
* �ۼ��� : �ӳ���
*/

// ���α׷��Ӹ� �����ϴ� ���� Ŭ������ ���� �ִ� Ư¡
// 1. ������ : ���α׷��Ӱ� �Ǽ��� �ʱ�ȭ���� �ʰ� �����͸� ����ϴ� ���� ��õ������ ���� ���� ���
// 2. �������� : ���������ڸ� ���ؼ� ���α׷��Ӱ� �����͸� �����ϰ� ������ �� �ִ� ��� (����� ���)
// ��� ������ private���� �����ϰ�, �ش� ������ �����ϴ� �Լ��� ������ �����ؼ� ������ ���·� ��� ������ ������ �����ϴ� ���� �ǹ�
// ���� Ŭ������ �ۼ��ϱ� ���� �⺻ ���� : ��������(���м�), ĸ��ȭ
// 3. ĸ��ȭ
// (1) �����(����)�� �� �Լ��� ������ �ϴ��� �� �ʿ䰡 �ִ�
// (2) �ۼ���(���α׷���) ���忡�� �ڵ带 �ۼ��ϴµ� �ʿ��� �Լ��� �׳� ȣ���ϸ� ��

class SiniveCap
{
public:
	void Take()
	{
		std::cout << "�๰���� �����߽��ϴ�" << std::endl;
	}
};

class SneezeCap
{
public:
	void Take()
	{
		std::cout << "������� �����߽��ϴ�" << std::endl;
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
		std::cout << "���� 31���� ���� �� �����ϴ�." << std::endl;
		std::cout << "���� �ش����� ������ �� �����ϴ�" << std::endl;
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
	std::cout << "������ " << year << "�� " << month << "�� " << day << "�� �Դϴ�." << std::endl;
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

// const �Լ��� ���� ����
// (��ȯ��) �Լ��̸�() const; �������� ����
// const keyword ���Ĺ޴� �Լ��� ��� ������ ���� ������� ������ �����ϴ� Ű����

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
	std::cout << "x�� ��ǥ�� �Է� : ";
	std::cin >> x;
	std::cout << "y�� ��ǥ�� �Է� : ";
	std::cin >> y;
}

void Point::ShowPoint() const
{
	std::printf("(%d, %d)\n", GetX(), GetY());
}

// ��� �̴ϼȶ������� �̿��� ��� �ʱ�ȭ ���
// ��� �̴ϼȶ������� ��������� ����� ��ü�� ������ ȣ���� Ȱ���ϴ� ���
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
	std::cout << "�簢���� ���� : " << areaSize << std::endl;
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
	std::cout << "������ �Է� : ";
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
	std::cout << "���� ���� : " << AreaSize << std::endl;
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

	// �簢�� Ŭ���� ȣ��
	Rectangle rect1;
	rect1.ShowRectInfo();

	Circle c1;
	c1.ShowCircleInfo();
}