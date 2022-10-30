#pragma once

#include "pch.h"
#include "AbelianUtil.h"
#include "WindowImplementation.h"

namespace Abelian
{
	class ABELIAN_API AbelianWindow
	{
	public:
		void Init();
		AbelianWindow* GetWindow();

		void Create(int width, int height, const std::string& windowName);
		void SwapBuffers();
	private:
		AbelianWindow();

		inline static AbelianWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };
	};
}