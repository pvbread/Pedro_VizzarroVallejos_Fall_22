#include "GameBoard.h"

namespace Archimedes
{
	GameBoard::GameBoard()
	{
		board = std::vector(6, std::vector<int>(7, EMPTY_TILE));
		numOfPieces = std::vector<int>(7, 0);
	}

	void GameBoard::DisplayTurn()
	{
		Abelian::Renderer::GetRenderer()->Draw(turnTexture, 800, 400, 0);
		if (p1Turn)
			Abelian::Renderer::GetRenderer()->Draw(p1Indicator, 850, 300, 0);
		if (!p1Turn)
			Abelian::Renderer::GetRenderer()->Draw(p2Indicator, 850, 300, 0);
	}

	void GameBoard::DrawBoard()
	{
		int x{ 0 }, y{ 0 };
		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[row].size(); col++)
			{
				if (col == currSelectedCol && numOfPieces[col] == row)
					Abelian::Renderer::GetRenderer()->Draw(selectedTile, x, y, 0);
				else
				{
					//query which tiletype it is
					switch (board[row][col])
					{
					case EMPTY_TILE:
						Abelian::Renderer::GetRenderer()->Draw(emptyTile, x, y, 0);
						break;
					case P1_TILE:
						Abelian::Renderer::GetRenderer()->Draw(p1Tile, x, y, 0);
						break;
					case P2_TILE:
						Abelian::Renderer::GetRenderer()->Draw(p2Tile, x, y, 0);
						break;
					case P1_WIN_TILE:
						Abelian::Renderer::GetRenderer()->Draw(p1WinTile, x, y, 0);
						break;
					case P2_WIN_TILE:
						Abelian::Renderer::GetRenderer()->Draw(p2WinTile, x, y, 0);
						break;
					}
					
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

	void GameBoard::PlayerPlacePiece()
	{
		if (p1Turn)
		{
			board[numOfPieces[currSelectedCol]][currSelectedCol] = 1;
		}
		else
		{
			//i have to make this for when it's 2 human players
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

	void GameBoard::AdversaryPlacePiece(int column)
	{
		if (numOfPieces[column] == 6)
			return;
		board[numOfPieces[column]][column] = 2;
		//keep memory of last coordinates (but last player is opposite whose turn it is now)
		lastPieceCoords = std::make_pair(numOfPieces[column], column);
		numOfPieces[column]++;
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

	WinState GameBoard::CheckFinish()
	{
		//brute force
		//idea make a horizontal, vertical, 
		//and diagonal(leftbottom to topright) 
		//diag(lefttop to rightbottom) size 4 window
		//check for equal 1s or 2s

		//less brute force, keep memory of last piece placed
		// the type is the opposite of whoever's turn it is now
		//check all possible involved tiles

		bool turn = !p1Turn;

		int r{ lastPieceCoords.first }, c{ lastPieceCoords.second };
		if (r >= 3 &&
			board[r][c] == board[r - 1][c] &&
			board[r][c] == board[r - 2][c] &&
			board[r][c] == board[r - 3][c])
		{
			//if p1 went last
			if (turn)
			{
				board[r][c] = P1_WIN_TILE;
				board[r-1][c] = P1_WIN_TILE;
				board[r-2][c] = P1_WIN_TILE;
				board[r-2][c] = P1_WIN_TILE;
				return WinState::P1_WIN;
			}
			else
			{
				board[r][c] = P2_WIN_TILE;
				board[r - 1][c] = P2_WIN_TILE;
				board[r - 2][c] = P2_WIN_TILE;
				board[r - 2][c] = P2_WIN_TILE;
				return WinState::P2_WIN;
			}
		}
		
		int left;
		int right;

		if (c <= 3)
		{
			left = 0;
		}
		else
		{
			left = c - 3;
		}
		right = left + 3;

		while (right < COLS && right < c + 3)
		{
			if (board[r][left] == board[r][left+1] &&
				board[r][left+1] == board[r][left + 2] &&
				board[r][left+2] == board[r][left + 3])
			{
				//if p1 went last
				if (turn)
				{
					board[r][left] = P1_WIN_TILE;
					board[r][left + 1] = P1_WIN_TILE;
					board[r][left + 2] = P1_WIN_TILE;
					board[r][left + 3] = P1_WIN_TILE;
					return WinState::P1_WIN;
				}
				else
				{
					board[r][left] = P2_WIN_TILE;
					board[r][left + 1] = P2_WIN_TILE;
					board[r][left + 2] = P2_WIN_TILE;
					board[r][left + 3] = P2_WIN_TILE;
					return WinState::P2_WIN;
				}
			}
			left++;
			right++;
		}
		
		int topLeftRow = -1;
		int topLeftCol = -1;
		if (r > 2)
		{
			if (c < 4)
			{
				if (r + c >= ROWS)
				{
					topLeftRow = ROWS - 1;
					topLeftCol = c - (ROWS - 1 - r);
				}
				else
				{
					topLeftRow = r + c;
					topLeftCol = c - (topLeftRow - r);
				}
			}
		}
		else if (c > 2)
		{
			//we know rows are <3
			topLeftRow = r + 3;
			//we know c is greater than r anyways
			topLeftCol = c - (topLeftRow - r);
		}
		else if (c < 3 && r < 3)
		{
			topLeftRow = r + c;
			if (topLeftRow >= 3)
				topLeftCol = c - (topLeftRow - r);
			//otherwise topLeftCol stays at -1
		}
		else
		{
			topLeftRow = ROWS - 1;
			//we need the column to be < 4
			if (topLeftRow - r < 4)
				topLeftCol = topLeftRow - r;
			//otherwise topLeftCol stays at -1
		}

		// check if it it's a valid coordinate
		while ((topLeftCol != -1 || topLeftRow != -1) &&
			topLeftCol <= c &&
			topLeftRow >= r &&
			topLeftCol + 3 < COLS &&
			topLeftRow - 3 >= 0)
		{
			if (board[topLeftRow][topLeftCol] == board[topLeftRow - 1][topLeftCol + 1] &&
				board[topLeftRow - 1][topLeftCol + 1] == board[topLeftRow - 2][topLeftCol + 2] &&
				board[topLeftRow - 2][topLeftCol + 2] == board[topLeftRow - 3][topLeftCol + 3])
			{
				//if p1 went last
				if (turn)
				{
					board[topLeftRow][topLeftCol] = P1_WIN_TILE;
					board[topLeftRow-1][topLeftCol+1] = P1_WIN_TILE;
					board[topLeftRow-2][topLeftCol+2] = P1_WIN_TILE;
					board[topLeftRow-3][topLeftCol+3] = P1_WIN_TILE;
					return WinState::P1_WIN;
				}
				else
				{
					board[topLeftRow][topLeftCol] = P2_WIN_TILE;
					board[topLeftRow - 1][topLeftCol + 1] = P2_WIN_TILE;
					board[topLeftRow - 2][topLeftCol + 2] = P2_WIN_TILE;
					board[topLeftRow - 3][topLeftCol + 3] = P2_WIN_TILE;
					return WinState::P2_WIN;
				}
			}
			topLeftRow--;
			topLeftCol++;
		}
		int bottomLeftRow;
		int bottomLeftCol;
		if (c < 4)
		{
			bottomLeftRow = r - c;
			if (c >= r)
				bottomLeftCol = c - r;
			else
				bottomLeftCol = 0;
		}
		else if (r < 3)
		{
			bottomLeftRow = r - 3;
			//we know c is greater than r anyways
			bottomLeftCol = c - r;
		}
		else
		{
			bottomLeftRow = r - 3;
			bottomLeftCol = c - 3;
		}
		if (bottomLeftRow < 0)
		{
			//ask the question, is it legal to make the row 0?
			//if we subtract the difference to the col, if it stays
			//within bounds we are safe to bring it up to 0
			if (c - bottomLeftRow < COLS)
			{
				bottomLeftRow = 0;
			}
		}

		// check if it it's a valid coordinate
		while (bottomLeftRow >= 0 &&
			bottomLeftRow < r &&
			bottomLeftCol < c &&
			bottomLeftRow + 3 < ROWS &&
			bottomLeftCol + 3 < COLS)
		{
			if (board[bottomLeftRow][bottomLeftCol] == board[bottomLeftRow + 1][bottomLeftCol + 1] &&
				board[bottomLeftRow + 1][bottomLeftCol + 1] == board[bottomLeftRow + 2][bottomLeftCol + 2] &&
				board[bottomLeftRow + 2][bottomLeftCol + 2] == board[bottomLeftRow + 3][bottomLeftCol + 3])
			{
				//if p1 went last
				if (turn)
				{
					board[bottomLeftRow][bottomLeftCol] = P1_WIN_TILE;
					board[bottomLeftRow + 1][bottomLeftCol + 1] = P1_WIN_TILE;
					board[bottomLeftRow + 2][bottomLeftCol + 2] = P1_WIN_TILE;
					board[bottomLeftRow + 3][bottomLeftCol + 3] = P1_WIN_TILE;
					return WinState::P1_WIN;
				}
				else
				{
					board[bottomLeftRow][bottomLeftCol] = P2_WIN_TILE;
					board[bottomLeftRow + 1][bottomLeftCol + 1] = P2_WIN_TILE;
					board[bottomLeftRow + 2][bottomLeftCol + 2] = P2_WIN_TILE;
					board[bottomLeftRow + 3][bottomLeftCol + 3] = P2_WIN_TILE;
					return WinState::P2_WIN;
				}
			}
			bottomLeftRow++;
			bottomLeftCol++;
		}

		//we have a full board and none of the other conditions matched
		if (currSelectedCol == -1)
			return WinState::DRAW;

		return WinState::PLAYING;
	}
	std::vector<int> GameBoard::GetValidMoves() const
	{
		std::vector<int> validMoves;
		for (int i = 0; i < numOfPieces.size(); i++)
		{
			//adds the index of columns that aren't full
			if (numOfPieces[i] < 6)
				validMoves.push_back(i);
		}

		return validMoves;
	}

	void GameBoard::ChangeTurn()
	{
		p1Turn = !p1Turn;
	}

	bool GameBoard::GetTurn() const
	{
		return p1Turn;
	}
}
