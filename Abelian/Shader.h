#pragma once

#include "AbelianUtil.h"
#include "ShaderImplementation.h"
#include "pch.h"

namespace Abelian
{
	class ABELIAN_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentShader);
		Shader(const std::string&& vertexFile, const std::string&& fragmentShader);

		void Activate();
		void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideFloatValues(const std::string&& valueName, const std::vector<float>&& vals);
	private:
		ShaderImplementation* mImplementation;
	};
}