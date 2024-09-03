#include "TicTacToe.h"

bool board::isNum(std::string& s)
{
	std::string::const_iterator it = s.begin();

	while (it != s.end() && std::isdigit(*it))
	{
		++it;
	}

	
	return !s.empty() && it == s.end();
}

board::board()
{
	size = 3;
	bMap = new std::string * [size];

	for (int i = 0; i < size; i++)
	{
		bMap[i] = new std::string[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::string num = std::to_string((i*size)+j);
			bMap[i][j] = num;
		}
	}
}

bool board::insert_x(int pos)
{
	int col = pos / size;
	int row = pos % size;

	if (isNum(bMap[col][row]))
	{
		bMap[col][row] = "X";
		return true;
	}
	else
		return false;
	
}

bool board::insert_o(int pos)
{
	int col = pos / size;
	int row = pos % size;

	if (isNum(bMap[col][row]))
	{
		bMap[col][row] = "O";
		return true;
	}
	else
		return false;
}

std::string board::get_item(int pos) const
{
	int col = pos / size;
	int row = pos % size;
	return bMap[col][row];
}

std::string board::get_item(int col, int row) const
{
	return bMap[col][row];
}

void board::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << bMap[i][j];
		}
	}
}


bool board::x_win()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; i < size; j++)
		{
			if (bMap[i][j] != "X")
				break;
			if (j == (size - 1))
				return true;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; i < size; j++)
		{
			if (bMap[i][j] != "X")
				break;
			if (j == (size - 1))
				return true;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (bMap[i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}

	for (int i = 0; i < size; i++)
	{
		if (bMap[(size - 1) - i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}
	return false;
}

bool board::o_win()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; i < size; j++)
		{
			if (bMap[i][j] != "O")
				break;
			if (j == (size - 1))
				return true;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; i < size; j++)
		{
			if (bMap[i][j] != "O")
				break;
			if (j == (size - 1))
				return true;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (bMap[i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}

	for (int i = 0; i < size; i++)
	{
		if (bMap[(size - 1) - i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const board& b)
{
	// TODO: 여기에 return 문을 삽입합니다.
	for (int i = 0; i < b.GetSize();++i)
	{
		out << std::endl;
		for (int j = 0; j < b.GetSize(); ++j)
		{
			out << "----";
		}
		out << "-" << std::endl << "│";

		for (int j = 0; j < b.GetSize(); ++j)
		{
			std::string item = b.get_item(i, j);
			int len = item.length();

			if (len <= 1)
				out << std::setw(2) << item << std::setw(2) << "│";
			else if (len == 2)
				out << std::setw(1) << item << std::setw(2) << "│";
			else if (len == 3)
				out << std::setw(0) << item << std::setw(2) << "│";
		}
	}
	out << std::endl;
	for (int j = 0; j < b.GetSize(); ++j)
	{
		out << "----";
	}
	out << std::endl;
	out << std::endl;
	return out;
}



void board::GamePlay()
{
	bool xTurn = true;
	while (!x_win() && !o_win())
	{
		std::cout << std::string(10, '\n');
		std::cout << *this;

		if (xTurn)
		{
			bool inserted = false;

			while (!inserted)
			{
				int pos;
				std::cout << "X의 차례입니다. 숫자를 입력해주세요" << std::endl;
				std::cin >> pos;
				inserted = insert_x(pos);
			}
			xTurn = false;
			

		}
		else if (!xTurn)
		{
			bool inserted = false;

			while (!inserted)
			{
				int pos;
				std::cout << "O의 차례입니다. 숫자를 입력해주세요" << std::endl;
				std::cin >> pos;
				inserted = insert_o(pos);
			}
			xTurn = true;
		}

		if (x_win())
		{
			std::cout << "x의 승리입니다" << std::endl;
		}
		else
		{
			std::cout << "O의 승리입니다" << std::endl;
		}

	}
}