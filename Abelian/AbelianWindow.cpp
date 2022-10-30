#include "pch.h"
#include "AbelianWindow.h"

namespace Abelian
{
	void AbelianWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new AbelianWindow;
			//mInstance->mImplementation
		}
	}
	AbelianWindow* AbelianWindow::GetWindow()
	{
		return mInstance;
	}
	void AbelianWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);
	}
	void AbelianWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}
}