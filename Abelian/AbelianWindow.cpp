#include "pch.h"
#include "AbelianWindow.h"
#include "GLFWcode/GLFWimplementation.h"

namespace Abelian
{
	void AbelianWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new AbelianWindow;
#ifdef ABELIAN_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
#elif defined ABELIAN_MAC
			mInstance->mImplementation = new GLFWimplementation;
#else
			mInstance->mImplementation = new GLFWimplementation;
#endif
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