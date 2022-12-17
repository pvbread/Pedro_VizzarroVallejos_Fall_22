#pragma once
#include "Abelian.h"
#include "SelectState.h"
#include "WinState.h"

namespace Archimedes
{
	class GameBoard
	{
	public:
		GameBoard();
		void DrawBoard();
		void MoveSelection(SelectState direction);
		void PlacePiece();

		WinState CheckFinish();

	private:
		bool p1Turn = true;
		int currSelectedCol = 0;
		std::pair<int, int> lastPieceCoords;
		int ROWS = 6;
		int COLS = 7;
		std::vector<std::vector<int>> board;
		std::vector<int> numOfPieces;
		Abelian::Picture emptyTile{ "../Assets/Textures/EmptyTile.png" };
		Abelian::Picture p1Tile{ "../Assets/Textures/BlueTile.png" };
		Abelian::Picture p2Tile{ "../Assets/Textures/RedTile.png" };
		Abelian::Picture selectedTile{ "../Assets/Textures/SelectedTile.png" };
	};
}