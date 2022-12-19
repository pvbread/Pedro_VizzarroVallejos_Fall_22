#pragma once
#include "Abelian.h"
#include "GameBoard.h"

namespace Archimedes
{
	class Adversary
	{
	public:
		int PickNextMove(const GameBoard& board, std::string strategy = "random");
	};
}