#include "pch.h"

#include "AbelianApp.h"
#include "AbelianUtil.h"
#include "AbelianWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"


namespace Abelian
{
	void AbelianApp::OnUpdate()
	{

	}

	void AbelianApp::Run()
	{
		ABELIAN_LOG("Abelian running..");

		AbelianWindow::Init();
		AbelianWindow::GetWindow()->Create(800, 600, "TestWindow");

		Renderer::Init();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		Picture pic{ "../Assets/Textures/carl.png" };

		AbelianWindow::GetWindow()->SetKeyPressedCallback([&](const KeyPressedEvent& event) {
			if (event.GetKeyCode() == ABELIAN_KEY_LEFT) x -= 10;
			else if (event.GetKeyCode() == ABELIAN_KEY_RIGHT) x += 10;
			});

		while (true)
		{
			Renderer::Clear();

			OnUpdate();
			
			Renderer::Draw(pic, 100, 100, 1);

			std::this_thread::sleep_until(mNextFrameTime);
			
			AbelianWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
			
		}

		
	}
}