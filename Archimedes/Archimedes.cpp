/*
	include Abelian.h
	Inherit a class from AbelianApp.
	Override method OnUpdate in it.
	Give name of class to START_ABELIAN_GAME macro
*/

#include "Abelian.h"

class ArchimedesGame : public Abelian::AbelianApp
{
public:
	ArchimedesGame()
	{
	}
	
	void OnUpdate() override
	{
		Abelian::Renderer::GetRenderer()->Draw(pic, 0, 0, 0);
		Abelian::Renderer::GetRenderer()->Draw(pic, 200, 300, 0);
	}

private:
	//Abelian::Unit test{ "../Assets/Textures/carl.png", 0 };
	Abelian::Picture pic{ "../Assets/Textures/carl.png" };

};


START_ABELIAN_GAME(ArchimedesGame)