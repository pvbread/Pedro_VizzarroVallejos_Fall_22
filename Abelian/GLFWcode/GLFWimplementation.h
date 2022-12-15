#pragma once


#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../WindowImplementation.h"

namespace Abelian
{
	class GLFWimplementation : public WindowImplementation
	{
	public:
		GLFWimplementation();
		virtual void Create(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		~GLFWimplementation();

		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback) override;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) override;
	private:
		GLFWwindow* mWindow{ nullptr };

		struct Callbacks
		{
			std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
		} mCallbacks;
	};
}