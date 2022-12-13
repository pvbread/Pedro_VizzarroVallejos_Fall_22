#include "pch.h"
#include "Renderer.h"

namespace Abelian
{
	void Renderer::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Renderer;
	}
	void Renderer::Draw(Picture& picture, Shader& shader, int x, int y, int z)
	{
		mImplementation->Draw(picture, x, y, z, shader);
	}
	void Renderer::Draw(Picture& picture, int x, int y, int z)
	{
		mImplementation->Draw(picture, x, y, z);
	}
	Renderer::Renderer()
	{
#ifdef ABELIAN_OPENGL
		mImplementation = new OpenGLRenderer{};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}
}

