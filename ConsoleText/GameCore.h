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
	Position CurrentPosition; // ����
	Position NewPosition; // �Է� ���� �÷��̾��� ��ġ
};

// ���� �� ����, ����
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

class WorldState // ���� ������ �ִ� world <- �÷��̾ ��ġ�ؾ� �� ������ ��� �ִ� Ŭ����
{
public:
	std::vector<MapData> MapDatas;
};

void InitializeGame(PlayerState& playerstate, WorldState& worldstate);

