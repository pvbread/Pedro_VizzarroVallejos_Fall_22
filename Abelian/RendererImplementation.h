#pragma once

#include "Shader.h"
#include "Picture.h"

namespace Abelian
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Picture& picture, int x, int y, int z, Shader& shader) = 0;
	};
}