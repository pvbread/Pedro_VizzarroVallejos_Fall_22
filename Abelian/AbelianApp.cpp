#include "AbelianApp.h"
#include "AbelianUtil.h"
#include <iostream>

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