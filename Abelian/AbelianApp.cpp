#include "pch.h"

#include "AbelianApp.h"
#include "AbelianUtil.h"

#include "GLFW/glfw3.h"


namespace Abelian
{
	void AbelianApp::OnUpdate()
	{

	}

	void AbelianApp::Run()
	{
		ABELIAN_LOG("Abelian running..");

		if (!glfwInit())
			ABELIAN_LOG("error with glfw init");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow* win{ glfwCreateWindow(600, 400, "Test window", NULL, NULL) };
		glfwMakeContextCurrent(win);

		if (!win)
			ABELIAN_LOG("error loading window");

		while (true)
		{
			glfwSwapBuffers(win);
			glfwPollEvents();
			
			OnUpdate();
		}

		glfwTerminate();
	}
}