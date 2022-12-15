#pragma once
#include "pch.h"
#include "Event.h"

namespace Abelian
{
	class WindowImplementation
	{
	public:
		virtual void Create(int width, int height, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback) = 0;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) = 0;
	private:
	};
}