#include "pch.h"

#include "AbelianApp.h"
#include "AbelianUtil.h"



namespace Abelian
{
	void AbelianApp::OnUpdate()
	{

	}

	void AbelianApp::Run()
	{
		while (true)
		{
			ABELIAN_LOG("Abelian running..");
			OnUpdate();
		}
	}
}