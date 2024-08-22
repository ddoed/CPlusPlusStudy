#include "GameCore.h"
#include "Parser.h"

void InitializeGame(PlayerState& playerState, WorldState& worldState)
{
	std::cout << "섬에 오신것을 환영합니다" << std::endl;
	std::cout << "이 섬에 대한 추가 정보를 입력" << std::endl;
	
	playerState.CurrentMapIndex = 0;
	playerState.CurrentPosition.posX = playerState.NewPosition.posX = 3;
	playerState.CurrentPosition.posY = playerState.NewPosition.posY = 3;
	//0
	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#......#"
			"#......#"
			"########";
		MapData map = MapData("초원", "경치가 아름다운 곳이다. 앞에 이동할 수 있는 문이 보이는 것 같다", MapInfo);
		map.MapWidth = 8;
		map.MapPosition.posX = 3;
		map.MapPosition.posY = 3;

		worldState.Mapdatas.push_back(map);
	}

	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#.%....#"
			"#......#"
			"###..###";
		MapData map = MapData("숲속", "울창한 수림에 둘러 쌓여 있다. 나뭇잎 사이로 지나갈 수 있는 길이 보인다", MapInfo);
		map.MapWidth = 8;
		map.MapPosition.posX = 3;
		map.MapPosition.posY = 2;

		worldState.Mapdatas.push_back(map);
	}

	{

	}


}

void RenderGame(PlayerState& playerState, const WorldState& worldState)
{
	MapData currentMap = worldState.Mapdatas[playerState.CurrentMapIndex];
	// 현재 플레이어가 위치한 방 정보를 저장하고 있는 클래스

	std::string mapstring = "";
	unsigned int currentSpace = 0;

	while (currentSpace < currentMap.MapInfo.size())
	{
		char playerToDisplay = currentMap.MapInfo[currentSpace];// 플레이어의 입력을 받을 변수

		if (currentSpace == PositionToIndex(playerState.CurrentPosition, currentMap.MapWidth))
		{
			playerToDisplay += '@';
		}

		mapstring += playerToDisplay;

		if (currentSpace % currentMap.MapWidth == (currentMap.MapWidth - 1))
		{
			mapstring += '\n';
		}
		currentSpace++;
	}

	std::cout << mapstring.c_str() << std::endl; // 맵에 저장되어 있는 문자열이 출력됨 개행문자 포함x

	
}

void GetInput(PlayerState& playerstate, const WorldState& worldstate)
{
	std::cout << "다음행동을 입력해주세요 : " << std::endl;
	std::cout << " -> ";
	ConsoleTextCommand command = ParseCommand();

	if (command.commandType == CommandTypeNorth)
	{
		playerstate.NewPosition.posY = playerstate.CurrentPosition.posY - 1;
	}
	else if(command.commandType == CommandTypeSouth)
	{
		playerstate.NewPosition.posY = playerstate.CurrentPosition.posY + 1;
	}
	else if (command.commandType == CommandTypeEast)
	{
		playerstate.NewPosition.posX = playerstate.CurrentPosition.posX + 1;
	}
	else if (command.commandType == CommandTypeWest)
	{
		playerstate.NewPosition.posX = playerstate.CurrentPosition.posX - 1;
	}
	else if (command.commandType == CommandTypeInventory)
	{

	}

	std::cout << std::endl;
}

void UpdateGame(PlayerState& playerState, WorldState& worldState)
{
	MapData currentMap = worldState.Mapdatas[playerState.CurrentMapIndex];

	if (IsSpaceOutsideMap(playerState.NewPosition, currentMap))
	{
		int newRoomIndex = 0;
		int playerExitType = 0;
		Position targetMapPos = currentMap.MapPosition;

		if (playerState.NewPosition.posX < 0)
		{
			// 서쪽으로 탈출
			targetMapPos.posX--;
			playerExitType = 1;
		}
		if (playerState.NewPosition.posX << 0 >= (int)currentMap.MapWidth)
		{
			// 동쪽으로 탈출
			targetMapPos.posX++;
			playerExitType = 2;
		}
		if (playerState.NewPosition.posY < 0)
		{
			// 북쪽으로 탈출
			targetMapPos.posY--;
			playerExitType = 3;
		}
		if (playerState.NewPosition.posY >= (int)(currentMap.MapInfo.size() / currentMap.MapWidth))
		{
			// 서쪽으로 탈출
			targetMapPos.posY++;
			playerExitType = 4;
		}

		bool foundMap = false;

		for (int i = 0; i < worldState.Mapdatas.size(); i++)
		{
			if (worldState.Mapdatas[i].MapPosition == targetMapPos)
			{
				foundMap = true;
				newRoomIndex = 1;
				break;
			}
		}
		if (foundMap == true)
		{
			playerState.CurrentMapIndex = newRoomIndex;
		}
		else
		{
			std::cout << "탈출 하는 맵에 해당하는 정보가 없습니다" << std::endl;
			playerState.NewPosition = playerState.CurrentPosition;
		}
		

	}

	if (IsSpaceCanMove(playerState.NewPosition, currentMap))
	{
		playerState.CurrentPosition = playerState.NewPosition;
	}
	else
	{
		std::cout << "이동할 수 없는 공간입니다." << std::endl;
		playerState.NewPosition = playerState.CurrentPosition;
	}
	
}

int PositionToIndex(const Position& position, int mapWidth)
{
	return position.posY * mapWidth + position.posX;
}

bool IsSpaceOutsideMap(const Position& pos, const MapData currentMap)
{
	return
		pos.posY < 0 ||
		pos.posX < 0 ||
		pos.posY >= (int)(currentMap.MapInfo.size() / currentMap.MapWidth) ||
		pos.posX >= (int)(currentMap.MapWidth);
}

bool IsSpaceCanMove(const Position& pos, const MapData currentMap)
{
	int spaceIndex = PositionToIndex(pos, currentMap.MapWidth);

	char currentSpace = currentMap.MapInfo[spaceIndex];

	return currentSpace == '.';
}

