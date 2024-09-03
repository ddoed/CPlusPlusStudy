// 사용하면 좋은 함수들
// std::cin >> input;   숫자인지 아닌지 판별, std::isdigit()
// std::setw() 가로의 길이를 일정하게 맞추어 주는 함수
// 포인터를 클래스로 표현한 것 -> iterator
// 문자열을 클래스로 표현한 것 -> string

#include <iostream>
#include <cstdlib>
#include <iomanip> 

// std

class SampleSTD
{
public:
	SampleSTD() {}

	// 콘솔의 출력 관련 도우미 함수  (가로의 길이)
	// setw(숫자) : 숫자 만큼 크기를 채워서 맞춰준다.
	// std::left : 왼쪽 정렬
	// std::right : 오른쪽 정렬
	// std::setfill : 빈칸을 (문자로)로 채워준다.

	void SetWidthExample()
	{
		int a = 4235;
		int b = 12345;
		std::cout << std::setfill('=') << std::left << std::setw(20) << a << std::endl;
		std::cout << std::setfill('#') << std::right << std::setw(20) << b << std::endl;


		int waitnum;
		std::cout << "이 예제를 종료하려면 아무 숫자를 입력해주세요." << std::endl;
		std::cin >> waitnum;
		system("cls");
	}

	void IsDigitExampe()
	{
		// 조건으로 숫자가 아니면 false,  true 반환해주는 함수 

		int a = 10;

		if (std::isdigit(a))
		{
			std::cout << "참입니다." << std::endl;
		}
	}
};

// 포인터 
// *ptr  : 역참조.
// ptr++ : (주소 + 1)
// ++ptr
class Iterator
{
private:
	int* ptr;
public:
	Iterator(int* p) : ptr(p) {}

	// 연산자 오버로딩

	Iterator* operator++()
	{
		++ptr;
		return this;
	}
	Iterator* operator++(int)
	{
		Iterator* temp = this;
		++(*this);
		return temp;
	}

};

// Iterator 클래스 std  
// 자료구조 class
// 클래스 안에 포인터(iterator 클래스) 

//  for반복문

// for(int i =0;  i <  arr.Length; i++) { } 
// Iterator s;     s.begin();   s.End() ;
// while(s.End() != nullptr)