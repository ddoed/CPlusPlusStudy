#include "lectures.h"

/*
* 학습 목표 : 연산자 오버로딩
* 작성일 : 2024-08-19
* 작성자 : 임나빈
*/

/*
* #include <iostream>
* istream(입력스트림), ostream(출력스트림)
* cout <<
* cin >>
*/

/*
* 구조체, 클래스 : 사용자 정의 자료형
* 클래스와 클래스 사이에 산술연산자가 사용이 가능한가?
* 해당하는 연산자를 만들어주면 된다 -> 연산자 오버로딩으로 클래스에 직접 정의하겠다
*/

/*
* 연산자 오버로딩 : 기본 연산자들(+, -, *,/,[],<<,>>)들을 사용자가 클래스에 직접 정의하는 것
* (반환값) (키워드)(연산자)()
* 예시 : void operator+();
*/

/*
* 전역 함수 오버로딩
* - 멤버 함수를 통한 오버로딩 : 객체.operator+(피연산자) : 객체 + 피연산자
* - 연산자 기준으로 객체가 반드시 왼쪽에 있어야 한다
* 
* - 전역 함수 오버로딩은 operator+(피연산자, 피연산자) 피연산자 + 피연산자 식으로 객체가 뒤에 위치해도 정상적인 결과를 출력한다
* 피연산자 + 피연산자 = operator+(피연산자, 피연산자)
*/

/*
* friend 함수
* 클래스의 멤버함수가 아니면서 해당클래스의 private 데이터를 접근할 때 사용하는 함수
* 클래스에 속하지 않지만, 이 클래스 안에 있는 데이터를 사용하고 싶을 때 사용하는 키워드
* 단점 : private, public -> private를 이용해서 외부에서 수정을 못하게 하기 위해서 정보은닉 무시하는 문법
* 장점 : 연산자 오버로딩을 사용해서 범용적인 함수를 만들 수 있다.
* 결론 : 연산자 오버로딩 이외에 friend 키워드를 사용하는 것은 지양
*/

/*
* 단항 연산자 오버로딩 : 증감연산자
* ++ : num + 1;
* -- : num - 1;
* ++num : 전위 증가 연산
* num++ : 후위 증가 연산
*/

class Point
{
private:
	int posX, posY;
public:
	Point() {}; // 디폴트 생성자
	Point(int x, int y) // 생성자 오버로딩
	{
		posX = x;
		posY = y;
	}
	void ShowPosition()
	{
		std::cout << "posX : " << posX << ", posY : " << posY << std::endl;
	}

	Point operator+(Point& ref)
	{
		return Point(posX + ref.posX, posY + ref.posY);
	}
	Point operator-(Point& ref)
	{
		return Point(posX - ref.posX, posY - ref.posY);
	}
	Point operator+(int value)
	{
		return Point(posX + value, posY + value);
	}
	friend Point operator+(int num, Point ref); // 전역함수 연산자 오버로딩

	Point operator++() // 전위 증가 연산자
	{
		posX += 1;
		posY += 1;
		return *this; // 자기 자신을 객체로 반환
	}
	Point operator++(int) // 후위 증가 연산자
	{
		Point temp(*this); // 복사생성자 : 얕은 복사로 데이터 이동
		posX += 1;
		posY += 1;
		return temp; // 자기 자신을 객체로 반환
	}
};

Point operator+(int num, Point ref)
{
	ref.posX += num;
	ref.posY += num;
	return ref;
}

class Eng;
class Math
{
private:
	char name[10];
	int score;
public:
	Math() {}; // 생성자를 직접 정의하면 디폴트 생성자가 자동으로 생성되지 않기 때문에 명시적으로 생성
	Math(const char* name, int score)
	{
		strcpy_s(this->name, 10, name);
		this->score = score;
	}
	
	friend int Add(Math m1, Eng e1);
};

class Eng
{
private:
	char name[10];
	int score;
public:
	Eng() {}; // 생성자를 직접 정의하면 디폴트 생성자가 자동으로 생성되지 않기 때문에 명시적으로 생성
	Eng(const char* name, int score)
	{
		strcpy_s(this->name, 10, name);
		this->score = score;
	}

	friend int Add(Math m1, Eng e1);
};

int Add(Math m1, Eng e1)
{
	return m1.score + e1.score;
}

// <iostream> istream ostream

/*
* 연산자 오버로딩 예시
* ostream& operator<<(std::ostream& out, const int& val)
* {
*		printf("%d", val);
*		return out
* }
* 
* ostream& operator<<(std::ostream& out, const char* val)
* {
*		printf("%s", val);
* }
* 
* & operator>>(std::istream& in, int& val)
*/
void lecture7()
{
	Point p1(1, 1);
	Point p2(2, 3);
	Point result1 = p1 + p2;
	// point p1 + point p2 -> p1.operator+(point& p2)
	Point result2 = p1 - p2;

	p1.ShowPosition();
	p2.ShowPosition();
	result1.ShowPosition();
	result2.ShowPosition();

	Point plusWithNum = p1 + 10;
	plusWithNum.ShowPosition();

	Point NumPluspoint = 10 + p1;
	NumPluspoint.ShowPosition();

	Point p3(3, 3);
	++p3;
	p3.ShowPosition();
	Point p4(4, 4);
	p4++;
	p4.ShowPosition();

	system("cls");

	Math m1("수학", 95), m2("수학", 70);
	Eng e1("영어", 80), e2("영어", 65);

	std::cout << "수학 + 영어 총합 : " << Add(m1, e1) << std::endl;


}