#pragma once

#include "pch.h"
#include "AbelianUtil.h"
#include "WindowImplementation.h"

namespace Abelian
{
	class ABELIAN_API AbelianWindow
	{
	public:
		static void Init();
		static AbelianWindow* GetWindow();

		virtual void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();
	private:
		//question about why this is here
		//AbelianWindow();

		inline static AbelianWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };
	};
}