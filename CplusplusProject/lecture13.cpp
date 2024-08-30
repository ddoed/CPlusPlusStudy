#include "lectures.h"

/*
* template 키워드
* 코드를 위한 툴을 만드는 것(데이터 타입)
*/

template <typename T>
void Plus(T a, T b)
{
	std::cout << a + b << std::endl;
}

template <typename T1, typename T2>

void SomeFunc(T1 a, T2 b) {}

template <typename T1>
void SomeFunc(T1 a, int b) {}

class One
{
public:
	void operator+(const One& one)
	{
		std::cout << "a+b의 연산자 오버로딩 출력" << std::endl;
	}
};

template <typename T>
class Point
{
private:
	T posX;
	T posY;
public:
	Point() {}
	Point(T x, T y) : posX(x), posY(y) {}
	void Show()
	{
		std::cout << "posX : " << posX << std::endl;
		std::cout << "posY : " << posY << std::endl;
	}
};

/*
* 클래스 템플릿과 함수 템플릿의 차이점
* 함수 템플릿은 함수 호출시에 <type> 명시하지 않으면 인자를 통해서 타입을 정한다
* 묵시적으로 템플릿 함수를 선언한다. 일반함수가 존재하면 일반 함수가 먼저 실행됨
* 클래스 템플릿은 묵시적으로 타입을 지정해주는 기능X
*/

template <typename T, int N> 
class MyArray // 직접 만드는 배열
{
private:
	T data[N]; // size 크기만큼 배열 선언
public:
	MyArray() {}
	MyArray(T(&arr)[N]) // 배열을 복사해서 저장하는 생성자
	{
		for (int i = 0; i < N; i++)
		{
			data[i] = arr[i];
		}
	}
	T* GetArray() { return data; }
	int Size() { return N; }
	void ShowInfo()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << data[i] << std::endl;
		}
	}
};

// 클래스가 한개만 존재해야 하는 패턴화 - 싱글톤 패턴



template <typename T>
class SingleTon
{
	// 반드시 객체가 하나만 있어야 한다
private:
	static T* singleTon;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleTon()
	{
		if (nullptr == singleTon)
		{
			singleTon = new T;
		}
		return singleTon;
	}

	static void Release()
	{
		delete singleTon;
		singleTon == nullptr;
	}
};

template <typename T>
T* SingleTon<T> ::singleTon = nullptr;

class GameManager : public SingleTon<GameManager>
{
private:
	int score;
public:
	GameManager() {}
	~GameManager() {}
	GameManager(int s) : score(s) {}
	int GetScore(){ return score; }
	void SetScore(int val) { score = val; }
	
	void GameStart()
	{
		std::cout << "게임 시작" << std::endl;
	}

	void GameEnd()
	{
		std::cout << "게임 종료" << std::endl;
	}

	void GameSave()
	{
		std::cout << "게임 저장" << std::endl;
	}
};

class GameData : public SingleTon<GameData>
{
private:
	int areaInfo;
public:
	GameData() {}

	int GetAreaInfo() { return areaInfo; }
	void SetAreaInfo(int area) { areaInfo = area; }
};


void lecture13()
{
	Point<int> p1(1, 2);
	p1.Show();

	int arrNum[3] = {1,5,9};
	MyArray<int, 3> mArray(arrNum);
	std::cout << mArray.Size() << std::endl;
	mArray.ShowInfo();

	double arrDouble[3] = { 1.1, 2.2, 3.3 };
	MyArray<double, 3> arrd(arrDouble);
	arrd.ShowInfo();

	std::cout << "GameManager 클래스" << std::endl;

	GameManager* gm = GameManager::GetSingleTon();
	gm->SetScore(100);
	std::cout << gm->GetScore() << std::endl;

	// 게임 시작
	gm->GameStart();

	// 종료
	gm->GameEnd();

	GameData* gameData = GameData::GetSingleTon();
	gameData->SetAreaInfo(10);
	std::cout << gameData->GetAreaInfo() << std::endl;

}