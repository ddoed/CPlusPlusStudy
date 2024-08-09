/*
* 학습 목표 : c언어 포인터 c++에서 활용법, 참조자(reference)에 대한 이해
* 작성일 : 2024-08-09
* 작성자 : 임나빈
*/

/*
* 함수를 사용할 때 포인터가 아닌 참조자를 사용하면 인자로 &(주소연산자)를 사용하지 않을 수 있다
* 주소 선언 : int*
* 참조자 선언 : int& 참조자 이름 = 참조하고자 하는 변수;
* int a;
* int& AnotherA = a;
*/

#include "lectures.h"
#include <cstring>

void SwapInt(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 함수 오버로딩 : C언어는 함수의 이름으로 함수를 구분, c++ 함수는 이름과 매개변수, 인자
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void ChangeVal(int& p)
{
	p = 10;
}

int Function1() //int를 반환하는 함수
{
	int a = 2;
	return a;
}

// 참조자를 리턴하는 함수
// 사용하지 않도록 쓰이는 예시
int& Function2()
{
	int a = 2;
	return a;
}

int& Function3(int& a)
{
	a = 2;
	return a;
}

typedef struct Human
{
	char name[30];
	int age;
}Human;

// 정수형 레퍼런스를 반환하는 함수
Human& AddHumanInfo(Human& human)
{
	std::cin >> human.age;
	std::cin >> human.name;
	return human;
}

void PrintHumanInfo(Human& human)
{
	std::cout << "이름 : " << human.name << std::endl << "나이 : " << human.age << std::endl;
}

void lecture2()
{
	std::cout << "2강" << std::endl;
	
	int num = 10; // num 변수 10이라는 정수, 주소
	int* numPtr = &num;
	std::cout << "포인터의 주소 : " << numPtr << std::endl;
	std::cout << "포인터가 가리키는 값 : " << *numPtr << std::endl;

	int num1 = 1, num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1의 값 " << num1 << std::endl << "num2의 값 " << num2 << std::endl;

	// 참조자 만드는 법
	// 참조자 : 변수의 별명
	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1;

	std::cout << "AnotherA1의 값 " << AnotherA1 << std::endl;

	// 참조자와 포인터가 다른부분
	// 포인터는 주소연산자를 인자로 받게 해야한다. 사용자가 함수와 포인터에 대한 이해도가 있어야 한다
	// 참조자는 주소연산자를 인자로 받지 않는다.
	
	//int Cnum2;
	//std::cin >> Cnum2;
	//std::cout << "Cnum2의 값 : " << Cnum2 << std::endl;

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num1의 값 " << d_num1 << std::endl << "d_num2의 값 " << d_num2 << std::endl;

	// 참조자는 반드시 선언과 동시에 초기화를 해야한다
	// 참조자는 선언할 때 상대의 주소를 가져와서 복사한다
	int& Anotherd1 = d_num1;

	const int& literal = 100; // const 키워드를 통해서 상수를 가리킬 수 있게 된다
	
	int p = 5;
	int p2 = 5;
	ChangeVal(p);
	std::cout << p << std::endl;

	//참조자(레퍼런스)를 리턴하는 함수
	int tempA = Function1(); // tempA Function 안에 있는 a값을 복사해서 대입
	int tempB = Function3(p2); // int tempB = a;

	// 레퍼런스 타입을 리턴할때는 반드시 지역변수를 반환하지 않도록 조심해야 한다

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	const int& anotherTemp = Function1();
	int& anotherTemp2 = Function2();

	std::cout << anotherTemp2 << std::endl;

	// 함수에서 값을 리턴할 때
	// int a = Function1();
	// const int& a = Function1();
	// 단 const 수식 받는 a 참조자는 값의 변경 불가능

	// (2) 함수가 참조자를 리턴할 때 int& Function();
	// 레퍼런스 타입을 리턴할때는 반드시 지역변수를 반환하지 않도록 조심해야 한다

	Human human;
	PrintHumanInfo(AddHumanInfo(human));
}