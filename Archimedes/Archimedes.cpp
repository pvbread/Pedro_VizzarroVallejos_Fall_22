/*
	include Abelian.h
	Inherit a class from AbelianApp.
	Override method OnUpdate in it.
	Give name of class to START_ABELIAN_GAME macro
*/

#include "Abelian.h"
#include "GameBoard.h"
#include "SelectState.h"

class ArchimedesGame : public Abelian::AbelianApp
{
public:
	ArchimedesGame()
	{
		Abelian::AbelianWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Abelian::KeyPressedEvent& event) {OnKeyPress(event); }
		);

	}
	
	void OnUpdate() override
	{
		//Abelian::Renderer::GetRenderer()->Draw(emptyTile, 0, 0, 0);
		if (m_State == SelectState::MOVE_LEFT || m_State == SelectState::MOVE_RIGHT)
		{
			board.MoveSelection(m_State);
			m_State = SelectState::STILL;
		}
		else if (m_State == SelectState::CHOOSE)
		{
			board.PlacePiece();
			m_State = SelectState::STILL;
		}
		board.DrawBoard(Abelian::Renderer::GetRenderer());
		
	}

private:
	Archimedes::GameBoard board;

	SelectState m_State{ SelectState::STILL };

	void OnKeyPress(const Abelian::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case ABELIAN_KEY_LEFT:
			m_State = SelectState::MOVE_LEFT;
			break;
		case ABELIAN_KEY_RIGHT:
			m_State = SelectState::MOVE_RIGHT;
			break;
		case ABELIAN_KEY_ENTER:
			m_State = SelectState::CHOOSE;
			break;
		}
	}
};


START_ABELIAN_GAME(ArchimedesGame)