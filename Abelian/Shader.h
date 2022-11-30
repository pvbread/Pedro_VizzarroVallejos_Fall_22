#pragma once

#include "AbelianUtil.h"
#include "ShaderImplementation.h"
#include "pch.h"

namespace Abelian
{
	class SOIL_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentShader);
		Shader(const std::string&& vertexFile, const std::string&& fragmentShader);
	private:
		ShaderImplementation* mImplementation;
	};
}