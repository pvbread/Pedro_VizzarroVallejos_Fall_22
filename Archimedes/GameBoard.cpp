#include "GameBoard.h"

namespace Archimedes
{
	GameBoard::GameBoard()
	{
		board = std::vector(6, std::vector<int>(7, 0));
		numOfPieces = std::vector<int>(7, 0);
	}

	void GameBoard::DrawBoard(Abelian::Renderer* renderer)
	{
		int x{ 0 }, y{ 0 };
		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[row].size(); col++)
			{
				if (col == currSelectedCol && numOfPieces[col] == row)
					renderer->Draw(selectedTile, x, y, 0);
				else
				{
					//query which tiletype it is
					if (board[row][col] == 0)
						renderer->Draw(emptyTile, x, y, 0);
					else if (board[row][col] == 1)
						renderer->Draw(p1Tile, x, y, 0);
					else if (board[row][col] == 2)
						renderer->Draw(p2Tile, x, y, 0);
				}
				x += 100;
			}
			x = 0;
			y += 100;
		}
	}

	void GameBoard::MoveSelection(SelectState direction)
	{
		if (direction == SelectState::MOVE_LEFT)
		{
			if (currSelectedCol != 0)
				currSelectedCol--;
		}
		else if (direction == SelectState::MOVE_RIGHT)
		{
			if (currSelectedCol != COLS-1)
				currSelectedCol++;
		}
	}

	void GameBoard::PlacePiece()
	{
		if (p1Turn)
		{
			board[numOfPieces[currSelectedCol]][currSelectedCol] = 1;
		}
		else
		{
			board[numOfPieces[currSelectedCol]][currSelectedCol] = 2;
		}
		//keep memory of last coordinates (but last player is opposite whose turn it is now)
		lastPieceCoords = std::make_pair(numOfPieces[currSelectedCol], currSelectedCol);
		numOfPieces[currSelectedCol]++;
		p1Turn = !p1Turn;
		currSelectedCol = 0;
		while (numOfPieces[currSelectedCol] == 6)
		{
			currSelectedCol++;
			//all columns 0-6 are full, check for win conditions after
			if (currSelectedCol == 7)
			{
				currSelectedCol = -1;
				break;
			}
		}
	}

	int GameBoard::CheckFinish()
	{
		//brute force
		//idea make a horizontal, vertical, 
		//and diagonal(leftbottom to topright) 
		//diag(lefttop to rightbottom) size 4 window
		//check for equal 1s or 2s

		//less brute force, keep memory of last piece placed
		// the type is the opposite of whoever's turn it is now
		//check all possible involved tiles

		return 0;
	}
}
