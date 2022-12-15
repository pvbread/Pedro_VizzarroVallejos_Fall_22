#include "pch.h"

#include "AbelianApp.h"
#include "AbelianUtil.h"
#include "AbelianWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"
#include "Keys.h"


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

		int x{ 200 }, y{ 200 };

		AbelianWindow::GetWindow()->SetKeyPressedCallback([&](const KeyPressedEvent& event) {
			ABELIAN_LOG(event.GetKeyCode());
			if (event.GetKeyCode() == ABELIAN_KEY_LEFT) x -= 10;
			else if (event.GetKeyCode() == ABELIAN_KEY_RIGHT) x += 10;
			});

		while (true)
		{
			Renderer::Clear();

			OnUpdate();
			
			Renderer::Draw(pic, x, y, 1);
			//ABELIAN_LOG(x);

			std::this_thread::sleep_until(mNextFrameTime);
			
			AbelianWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
			
		}

		
	}
}