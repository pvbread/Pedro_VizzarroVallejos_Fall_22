#pragma once
#include "Abelian.h"
#include "SelectState.h"
#include "WinState.h"
#include "TileType.h"

namespace Archimedes
{
	class GameBoard
	{
	public:
		GameBoard();
		void DrawBoard();
		void MoveSelection(SelectState direction);
		void PlayerPlacePiece();
		void AdversaryPlacePiece(int column);
		void ChangeTurn();
		void DisplayTurn();

		std::vector<int> GetValidMoves() const;
		bool GetTurn() const;
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
		Abelian::Picture p2WinTile{ "../Assets/Textures/WinRedTile.png" };
		Abelian::Picture p1WinTile{ "../Assets/Textures/WinBlueTile.png" };
		Abelian::Picture turnTexture{ "../Assets/Textures/Turn.png" };
		Abelian::Picture p1Indicator{ "../Assets/Textures/BlueTileIndicator.png" };
		Abelian::Picture p2Indicator{ "../Assets/Textures/RedTileIndicator.png" };


		friend class Adversary;
	};

	
}