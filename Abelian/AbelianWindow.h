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

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);
	private:
		//question about why this is here
		//AbelianWindow();

		inline static AbelianWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}