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
	void OnUpdate() override
	{

	}
};


START_ABELIAN_GAME(ArchimedesGame)