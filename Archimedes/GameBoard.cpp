#include "GameBoard.h"

Archimedes::GameBoard::GameBoard()
{
	board = std::vector(6, std::vector<int>(7, 0));
}

void Archimedes::GameBoard::DrawBoard(Abelian::Renderer* renderer)
{
	int x{ 0 }, y{ 0 };
	for (auto row : board)
	{
		for (auto col : row)
		{
			renderer->Draw(emptyTile, x, y, 0);
			y += 100;
		}
		y = 0;
		x += 100;
	}
}
