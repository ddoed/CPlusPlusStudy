/*
* 학습목표 : c++ 언어 학습. c언어에서 배운 내용을 복습해본다
* 작성일 : 2024-08-08
* 작성자 : 임나빈
*/

/*
* Hello World 출력해주는 함수 <- 입출력 함수 : printf, scanf
* Hello World 출력해주는 함수 <- 입출력 함수 : <iostream> cout, cin
* cout : 출력 함수
* 사용법 std::cout << "Hello World" << std::endl;
* cin : 입력함수
* int num;
* 사용법 std::cin >> num;
*/

/*
* 1. std::cout << " "
* namespace 이름공간 : 어떤 정의된 객체가 어디에 소속되어있는지 알려준다
* std는 c++ standard library에 등록된 함수. C++ 표준 라이브러리의 모든 함수가 정의된 이름공간
*/

/*
* 함수, 변수를 작성하는데 다른 사람이 쓴 코드를 가져다 쓰면서 중복된 이름을 가진 함수를 사용할 확률이 높아짐
* c++ 문법에서 이를 구분하기 위해서 namespace라는 문법 제공
* 사용법 namespace (이름공간)이름 { }
*/

/*
* 범위 지정 연산자 '::'
* 사용법 : 이름공간::변수 또는 함수;
* 이름공간안에 있는 변수 또는 함수 사용 가능
* 만약에 이름 공간이 너무 길다
* using 키워드
* using TODAYISTUIRSDAY::num;
*/


/*
* 1. 변수 : int, char, float, double
* 2. 반복문, 조건문 : for반복문, while반복문, if, switch 조건문
* 3. 포인터(변수) : int*, char*, &num, &a1, *num, *a1
*/

#include "lectures.h"
#include "cstring"

using std::cout;
using std::endl;

//using namespace TODAYISTHURSDAY;
// 이 페이지 안에서 사용하는 모든 변수 또는 함수는 using namespace이름을 사용해라
// 장점 : 이름이 긴 namespace를 굳이 입력안해도 된다
// 단점 : namespace 안에 변수와 함수가 많을 수록, 다른 함수와 겹치는 경우가 많다

// 사용 추천안
// using namespace를 이용해서 모든 변수를 참조하는 방식은 지양
//필요한 함수만 지정해서 사용

namespace CPP
{
	void Sample()
	{
		std::cout << "Sample!"<<std::endl;
	}
}

namespace CPP2
{
	void Sample()
	{
		std::cout << "Sample2!"<<std::endl;
	}
}

namespace YNB
{
	int age;
	char name[30];
	void PrintMyName()
	{
		cout << "제 이름은 " << name << "입니다.\n";
		cout << "나이는 " << age << "입니다\n";
	}
}

namespace TODAYISTHURSDAY
{
	int num;
	int num2;
}

using TODAYISTHURSDAY::num;

// std::in 네임스페이스 사용해보기
// 숫자맞추기 간단히 구현

void lecture1()
{
	cout << "Hello World" << endl;
	cout << "Hello World\n";

	CPP::Sample();
	CPP2::Sample();
	
	// 이름이 나오면 :: namespace
	strcpy_s(YNB::name, 30, "임나빈");
	YNB::age = 20;
	YNB::PrintMyName();


	//숫자 맞추기 게임
	int LuckyNumber = 5;
	int UserInput;
	
	while (true)
	{
		std::cout << "나의 숫자를 맞추어 보세요 : ";
		std::cin >> UserInput;

		if (LuckyNumber == UserInput)
		{
			std::cout << "정답을 맞추었습니다" << std::endl;
			break;
		}
		else
		{
			std::cout << "오답입니다. 다시 입력하세요" << std::endl;
		}
	}


}


