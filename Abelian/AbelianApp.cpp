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
		AbelianWindow::GetWindow()->Create(600, 400, "TestWindow");

		Renderer::Init();

		Picture pic{ "../Assets/Textures/carl.png" };

		while (true)
		{
			Renderer::Clear();
			
			Renderer::Draw(pic, 100, 100, 1);
			
			AbelianWindow::GetWindow()->SwapBuffers();
			
			OnUpdate();
		}

		
	}
}