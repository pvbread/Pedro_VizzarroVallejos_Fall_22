#pragma once
#include "AbelianUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h"
#include "Unit.h"

namespace Abelian
{
	class ABELIAN_API Renderer
	{
	public:
		static Renderer* GetRenderer();
		static void Init();
		static void Draw(Picture& picture, int x, int y, int z, Shader& shader);
		static void Draw(Picture& picture, int x, int y, int z);
		static void Draw(Unit& u, Shader& shader);
		static void Draw(Unit& u);

		static void Clear();

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		Shader mDefaultShader{ "../Assets/Shaders/defaultAbelianVertex.glsl", 
			"../Assets/Shaders/defaultAbelianFragment.glsl" };
	};
}