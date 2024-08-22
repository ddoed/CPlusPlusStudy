#include "lectures.h"
#include <string>

/*
* �н� ��ǥ : c++ ��� �⺻ ����
* �ۼ��� : 2024-08-22
* �ۼ��� : �ӳ���
*/

/*
* ���(inheritance)
* �θ�(Ŭ����) <-> �ڽ�(Ŭ����) : public �Լ��� �����ؼ� ��� ���� ���
*/

/*
* ��ӿ��� ���� ���Ǵ� ��� ����
* ����� ���ִ� Ŭ���� vs ����� �޴� Ŭ����
* �θ�(parent) vs �ڽ�(child)
* ���(base) vs ����, �Ļ�(defrived)
* ����(super) vs ����(sub)
* ���� vs ����
*/

/*
* ����� �⺻ ��� : �θ� Ŭ����(��� �ϴ� Ŭ����)�� �ߺ����� �ʰ� ����� �� �ִ� ����
* Ŭ������ ������ �Ҹ���
*/

/*
* ���� ������
* public : public �������� ū ��� ����� ���� ���(private �̿��� ��� ���� ���)
* private : �ڽ� Ŭ���� �̿��� ��� Ŭ������ ������ ���´�. �ڽĵ� ���� ����
* protected : �⺻������ private�� �뵵�� ������, Ŭ������ ��ӵǾ��� �� �ڽ� Ŭ������ ������ ����ϴ� ����
* c++ Ư���� ��� ���� : ���� ���, ���� ��� ������ ���� �����ڷ� �ذ��ϱ� ���ؼ� private protected ����� ����
*/

/*
* ����� ������ ��� : public ���, private ���, protected ���
* public ��� : private �̿��� ��� ������ ���. �θ� �����ִ� ���������ڿ� �����ϰ� �����´�
* protected ��� : private �̿��� ��� ������ protected �������� �����Ѵ�
* private ��� : ��� ���� �����ڸ� private�� �����Ѵ�. �����ϴ� ������ �������� ��ӹ��.
*/


/*
* ����� ���� �ؾ��ϴ°�?
* IS-A : A is B�ΰ�? child(parent + �߰������� child ������ ���)�� parent �ΰ�?
* EBook�� å�̴�. å�� Ŭ���� ���� Ebook å�� ������ ��ӹ��� �� �ִ�.
* 
* HAS-A : A�� B�� �����ϰ� �ִ�. Police(�ڽ�)�� Gun(�θ�)�� ��
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
//		std::cout << "���� : " << title << std::endl;
//		std::cout << "���� : " << price << std::endl;
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
//		std::cout << "DRMkey �� : " << "wastddfg" << std::endl;
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
		std::cout << "�߻�!" << std::endl;
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
		std::cout << "�߻�!" << std::endl;

	}
};

class base
{
private:
	int num1;
protected:
	int num3;
public:
	base(int value, int value3) : num1(value) , num3(value3) {} // ��� �̴ϼȶ�����
	base()
	{
		std::cout << "base() ������ ȣ��!" << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "base()" << num1 << std::endl;
	}
	~base()
	{
		std::cout << "base() �Ҹ��� ȣ��!" << std::endl;
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
		std::cout << "derived() ������ ȣ��!" << std::endl;
	}
	void dPrint()
	{
		num3 = 1;
		num2 = 2;
		std::cout << "derived()" << num2 <<num3<< std::endl;
	}
	~derived()
	{
		std::cout << "derived() �Ҹ��� ȣ��!" << std::endl;
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

// ��������
class Rectangle
{
private:
	int width;
	int height;
	
public:
	Rectangle(int width, int height) : width(width), height(height) {}
	void ShowAreaInfo()
	{
		std::cout << "���� : " << width * height << std::endl;
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

	derived d1; // �ڽ� Ŭ������ ������ �� �θ� Ŭ������ ���� �����ؾ� �Ѵ�
	d1.dPrint();
	d1.Print();


	Rectangle re(2, 4);
	re.ShowAreaInfo();
	Square sq(5);
	sq.ShowAreaInfo();

	// protected ���
	parent p1;
	p1.num3 = 10;
	child c1;
	// c1.num3 = 100;

	Ebook ebook(10000, "C++ ��������", "ewrerered");
}