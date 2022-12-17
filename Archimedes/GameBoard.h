#pragma once
#include "Abelian.h"
#include "SelectState.h"

namespace Archimedes
{
	class GameBoard
	{
	public:
		GameBoard();
		void DrawBoard(Abelian::Renderer* renderer);
		void MoveSelection(SelectState direction);
		void PlacePiece();

		//returns 0 for no, 1 for p1 win, 2 for p2 win, 3 for draw
		int CheckFinish();

	private:
		bool p1Turn = true;
		int currSelectedCol = 0;
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