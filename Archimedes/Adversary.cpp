#include "Adversary.h"

namespace Archimedes
{
	int Adversary::PickNextMove(const GameBoard& board, std::string strategy)
	{
		std::vector<int> validMoves = board.GetValidMoves();
		
		if (strategy == "random")
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dist(0, validMoves.size()-1);

			return dist(gen);
		}
		return -1;
	}
}