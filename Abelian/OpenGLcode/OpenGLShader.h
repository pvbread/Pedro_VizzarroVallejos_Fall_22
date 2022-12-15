#pragma once

#include "../ShaderImplementation.h"

namespace Abelian
{
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		OpenGLShader(const std::string&& vertexFile, const std::string&& fragmentFile);
		virtual void Activate() override;
		virtual void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals) override;
		virtual void ProvideFloatValues(const std::string&& valueName, const std::vector<float>& vals) override;

		~OpenGLShader();
	private:
		unsigned int mShaderProg{ 0 };

	};
}