#include "pch.h"
#include "Shader.h"
#include "OpenGLcode/OpenGLShader.h"

namespace Abelian
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentShader)
	{
#ifdef ABELIAN_OPENGL
		mImplementation = new OpenGLShader{ vertexFile, fragmentShader };
#else
		
#endif
	}
	Shader::Shader(const std::string&& vertexFile, const std::string&& fragmentShader)
	{
#ifdef ABELIAN_OPENGL
		mImplementation = new OpenGLShader{ vertexFile, fragmentShader };
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}
	void Shader::Activate()
	{
		mImplementation->Activate();
	}
	void Shader::ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals)
	{
		mImplementation->ProvideFloatValues(valueName, vals);
	}
	void Shader::ProvideFloatValues(const std::string&& valueName, const std::vector<float>&& vals)
	{
		mImplementation->ProvideFloatValues(valueName, vals);
	}
}