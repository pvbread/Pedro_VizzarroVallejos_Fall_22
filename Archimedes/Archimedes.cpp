/*
	include Abelian.h
	Inherit a class from AbelianApp.
	Override method OnUpdate in it.
	Give name of class to START_ABELIAN_GAME macro
*/

#include "Abelian.h"
#include "GameBoard.h"

class ArchimedesGame : public Abelian::AbelianApp
{
public:
	ArchimedesGame()
	{
		
	}
	
	void OnUpdate() override
	{
		//Abelian::Renderer::GetRenderer()->Draw(emptyTile, 0, 0, 0);
		//Abelian::Renderer::GetRenderer()->Draw(emptyTile, 200, 300, 0);
		board.DrawBoard(Abelian::Renderer::GetRenderer());
	}

private:
	//Abelian::Unit test{ "../Assets/Textures/carl.png", 0 };
	//Abelian::Picture emptyTile{ "../Assets/Textures/EmptyTile.png" };
	Archimedes::GameBoard board;

};


START_ABELIAN_GAME(ArchimedesGame)