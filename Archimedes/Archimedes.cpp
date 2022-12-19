/*
	include Abelian.h
	Inherit a class from AbelianApp.
	Override method OnUpdate in it.
	Give name of class to START_ABELIAN_GAME macro
*/

#include "Abelian.h"
#include "GameBoard.h"
#include "SelectState.h"
#include "WinState.h"

namespace Archimedes
{
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
			if (mPlayState == WinState::PLAYING)
			{
				if (mSelectState == SelectState::MOVE_LEFT || mSelectState == SelectState::MOVE_RIGHT)
				{
					board.MoveSelection(mSelectState);
					mSelectState = SelectState::STILL;
				}
				else if (mSelectState == SelectState::CHOOSE)
				{
					board.PlayerPlacePiece();
					mSelectState = SelectState::STILL;
					mPlayState = board.CheckFinish();
				}
			}
			// instead of else, because I want to render it right away
			if (mPlayState != WinState::PLAYING)
			{
				switch (mPlayState)
				{
				case WinState::P1_WIN:
					Abelian::Renderer::GetRenderer()->Draw(p1WinsPic, 0, 800, 0);
					break;
				case WinState::P2_WIN:
					Abelian::Renderer::GetRenderer()->Draw(p2WinsPic, 0, 800, 0);
					break;
				case WinState::DRAW:
					Abelian::Renderer::GetRenderer()->Draw(gameDrawPic, 0, 800, 0);
					break;
				}
			}
			board.DrawBoard();

		}

	private:
		GameBoard board;

		SelectState mSelectState{ SelectState::STILL };
		WinState mPlayState{ WinState::PLAYING };
		Abelian::Picture p1WinsPic{ "../Assets/Textures/P1wins.png" };
		Abelian::Picture p2WinsPic{ "../Assets/Textures/P2wins.png" };
		Abelian::Picture gameDrawPic{ "../Assets/Textures/Draw.png" };

		void OnKeyPress(const Abelian::KeyPressedEvent& event)
		{
			switch (event.GetKeyCode())
			{
			case ABELIAN_KEY_LEFT:
				mSelectState = SelectState::MOVE_LEFT;
				break;
			case ABELIAN_KEY_RIGHT:
				mSelectState = SelectState::MOVE_RIGHT;
				break;
			case ABELIAN_KEY_ENTER:
				mSelectState = SelectState::CHOOSE;
				break;
			}
		}
	};
}

START_ABELIAN_GAME(Archimedes::ArchimedesGame)