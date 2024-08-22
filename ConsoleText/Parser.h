#pragma once
#include <string>

enum CommandType
{
	CommandTypeNone,

	CommandTypeNorth,
	CommandTypeSouth,
	CommandTypeEast,
	CommandTypeWest,

	CommandTypeQuit,
	CommandTypeGet,
	CommandTypeInventory,
	CommandTypeHelp,
	CommandTypeInfo
};

// char* char[]
// c++ string Ŭ����
// TypeString "w" -> commandTypeNorth

class ConsoleTextCommand
{
public:
	CommandType commandType;
	std::string Parameter;

};

ConsoleTextCommand ParseCommand();
