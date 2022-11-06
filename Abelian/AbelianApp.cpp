#include "pch.h"

#include "AbelianApp.h"
#include "AbelianUtil.h"
#include "AbelianWindow.h"


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


		while (true)
		{
			AbelianWindow::GetWindow()->SwapBuffers();
			
			OnUpdate();
		}

		
	}
}