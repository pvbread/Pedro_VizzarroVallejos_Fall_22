#pragma once
#include "Abelian.h"

namespace Archimedes
{
	class GameBoard
	{
	public:
		GameBoard();
		void DrawBoard(Abelian::Renderer* renderer);
	private:
		std::vector<std::vector<int>> board;
		Abelian::Picture emptyTile{ "../Assets/Textures/EmptyTile.png" };
	};
}