#pragma once
#include <string>
#include <vector>
#include <iostream>

class Position
{
public:
	int posX;
	int posY;

	bool operator == (const Position& otherPos) const
	{
		return posX == otherPos.posX && posY == otherPos.posY;
	}

	bool operator != (const Position& otherPos) const
	{
		return !(*this == otherPos);
	}
};

class PlayerState
{
public:
	Position CurrentPosition; // 현재
	Position NewPosition; // 입력 받은 플레이어의 위치
};

// 현재 맵 정보, 설명
class MapData
{
	std::string Name;
	std::string Description;
	std::string MapInfo;
	unsigned int MapWidth;
	
public:
	Position MapPosition;
	MapData();
	MapData(std::string Name, std::string Description, std::string MapInfo)
	{
		this->Name = Name;
		this->Description = Description;
		this->MapInfo = MapInfo;
	}
};

class WorldState // 맵이 여러개 있는 world <- 플레이어가 위치해야 할 정보를 담고 있는 클래스
{
public:
	std::vector<MapData> MapDatas;
};

void InitializeGame(PlayerState& playerstate, WorldState& worldstate);

