#pragma once

#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace Abelian
{
	class GLFWimplementation : public WindowImplementation
	{
	public:
		GLFWimplementation();
		virtual void Create(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		~GLFWimplementation();
	private:
		GLFWwindow* mWindow{ nullptr };
	};
}