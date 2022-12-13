#pragma once
#include "AbelianUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h"

namespace Abelian
{
	class ABELIAN_API Renderer
	{
	public:
		static void Init();
		static void Draw(Picture& picture, Shader& shader, int x, int y, int z);
		static void Draw(Picture& picture, int x, int y, int z);

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		inline static Shader mDefaultShader{ "Assets/Shaders/defaultAbelianVertex.glsl", 
			"Assets/Shaders/defaultAbelianFragment.glsl" };
	};
}