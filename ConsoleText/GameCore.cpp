#include "GameCore.h"
#include "Parser.h"

void InitializeGame(PlayerState& playerState, WorldState& worldState)
{
	std::cout << "���� ���Ű��� ȯ���մϴ�" << std::endl;
	std::cout << "�� ���� ���� �߰� ������ �Է�" << std::endl;
	
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
		MapData map = MapData("�ʿ�", "��ġ�� �Ƹ��ٿ� ���̴�. �տ� �̵��� �� �ִ� ���� ���̴� �� ����", MapInfo);
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
		MapData map = MapData("����", "��â�� ������ �ѷ� �׿� �ִ�. ������ ���̷� ������ �� �ִ� ���� ���δ�", MapInfo);
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
	// ���� �÷��̾ ��ġ�� �� ������ �����ϰ� �ִ� Ŭ����

	std::string mapstring = "";
	unsigned int currentSpace = 0;

	while (currentSpace < currentMap.MapInfo.size())
	{
		char playerToDisplay = currentMap.MapInfo[currentSpace];// �÷��̾��� �Է��� ���� ����

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

	std::cout << mapstring.c_str() << std::endl; // �ʿ� ����Ǿ� �ִ� ���ڿ��� ��µ� ���๮�� ����x

	
}

void GetInput(PlayerState& playerstate, const WorldState& worldstate)
{
	std::cout << "�����ൿ�� �Է����ּ��� : " << std::endl;
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
			// �������� Ż��
			targetMapPos.posX--;
			playerExitType = 1;
		}
		if (playerState.NewPosition.posX << 0 >= (int)currentMap.MapWidth)
		{
			// �������� Ż��
			targetMapPos.posX++;
			playerExitType = 2;
		}
		if (playerState.NewPosition.posY < 0)
		{
			// �������� Ż��
			targetMapPos.posY--;
			playerExitType = 3;
		}
		if (playerState.NewPosition.posY >= (int)(currentMap.MapInfo.size() / currentMap.MapWidth))
		{
			// �������� Ż��
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
			std::cout << "Ż�� �ϴ� �ʿ� �ش��ϴ� ������ �����ϴ�" << std::endl;
			playerState.NewPosition = playerState.CurrentPosition;
		}
		

	}

	if (IsSpaceCanMove(playerState.NewPosition, currentMap))
	{
		playerState.CurrentPosition = playerState.NewPosition;
	}
	else
	{
		std::cout << "�̵��� �� ���� �����Դϴ�." << std::endl;
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

