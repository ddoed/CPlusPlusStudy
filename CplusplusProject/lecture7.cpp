#include "lectures.h"

/*
* �н� ��ǥ : ������ �����ε�
* �ۼ��� : 2024-08-19
* �ۼ��� : �ӳ���
*/

/*
* #include <iostream>
* istream(�Է½�Ʈ��), ostream(��½�Ʈ��)
* cout <<
* cin >>
*/

/*
* ����ü, Ŭ���� : ����� ���� �ڷ���
* Ŭ������ Ŭ���� ���̿� ��������ڰ� ����� �����Ѱ�?
* �ش��ϴ� �����ڸ� ������ָ� �ȴ� -> ������ �����ε����� Ŭ������ ���� �����ϰڴ�
*/

/*
* ������ �����ε� : �⺻ �����ڵ�(+, -, *,/,[],<<,>>)���� ����ڰ� Ŭ������ ���� �����ϴ� ��
* (��ȯ��) (Ű����)(������)()
* ���� : void operator+();
*/

/*
* ���� �Լ� �����ε�
* - ��� �Լ��� ���� �����ε� : ��ü.operator+(�ǿ�����) : ��ü + �ǿ�����
* - ������ �������� ��ü�� �ݵ�� ���ʿ� �־�� �Ѵ�
* 
* - ���� �Լ� �����ε��� operator+(�ǿ�����, �ǿ�����) �ǿ����� + �ǿ����� ������ ��ü�� �ڿ� ��ġ�ص� �������� ����� ����Ѵ�
* �ǿ����� + �ǿ����� = operator+(�ǿ�����, �ǿ�����)
*/

/*
* friend �Լ�
* Ŭ������ ����Լ��� �ƴϸ鼭 �ش�Ŭ������ private �����͸� ������ �� ����ϴ� �Լ�
* Ŭ������ ������ ������, �� Ŭ���� �ȿ� �ִ� �����͸� ����ϰ� ���� �� ����ϴ� Ű����
* ���� : private, public -> private�� �̿��ؼ� �ܺο��� ������ ���ϰ� �ϱ� ���ؼ� �������� �����ϴ� ����
* ���� : ������ �����ε��� ����ؼ� �������� �Լ��� ���� �� �ִ�.
* ��� : ������ �����ε� �̿ܿ� friend Ű���带 ����ϴ� ���� ����
*/

/*
* ���� ������ �����ε� : ����������
* ++ : num + 1;
* -- : num - 1;
* ++num : ���� ���� ����
* num++ : ���� ���� ����
*/

class Point
{
private:
	int posX, posY;
public:
	Point() {}; // ����Ʈ ������
	Point(int x, int y) // ������ �����ε�
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
	friend Point operator+(int num, Point ref); // �����Լ� ������ �����ε�

	Point operator++() // ���� ���� ������
	{
		posX += 1;
		posY += 1;
		return *this; // �ڱ� �ڽ��� ��ü�� ��ȯ
	}
	Point operator++(int) // ���� ���� ������
	{
		Point temp(*this); // ��������� : ���� ����� ������ �̵�
		posX += 1;
		posY += 1;
		return temp; // �ڱ� �ڽ��� ��ü�� ��ȯ
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
	Math() {}; // �����ڸ� ���� �����ϸ� ����Ʈ �����ڰ� �ڵ����� �������� �ʱ� ������ ��������� ����
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
	Eng() {}; // �����ڸ� ���� �����ϸ� ����Ʈ �����ڰ� �ڵ����� �������� �ʱ� ������ ��������� ����
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
* ������ �����ε� ����
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

	Math m1("����", 95), m2("����", 70);
	Eng e1("����", 80), e2("����", 65);

	std::cout << "���� + ���� ���� : " << Add(m1, e1) << std::endl;


}