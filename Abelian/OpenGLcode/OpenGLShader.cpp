#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
#include "AbelianUtil.h"

namespace Abelian
{
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
        std::string vertexCode;
        std::ifstream vertexSource{ vertexFile };

        if (!vertexSource.is_open())
            ABELIAN_LOG("Error: failed to open vertex shader file");

        std::stringstream vertexTemp;
        vertexTemp << vertexSource.rdbuf();
        vertexCode = vertexTemp.str();
        const char* ansiVertex{ vertexCode.c_str() };

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &ansiVertex, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            ABELIAN_LOG(infoLog);
        }
        // fragment shader
        std::string fragmentCode;
        std::ifstream fragmentSource{ fragmentFile };

        if (!fragmentSource.is_open())
            ABELIAN_LOG("Error: failed to open fragment shader file");

        std::stringstream fragmentTemp;
        fragmentTemp << fragmentSource.rdbuf();
        fragmentCode = fragmentTemp.str();
        const char* ansiFragment{ fragmentCode.c_str() };

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &ansiFragment, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            ABELIAN_LOG("Error: failed to open fragment shader file")
        }
        // link shaders
        mShaderProg = glCreateProgram();
        glAttachShader(mShaderProg, vertexShader);
        glAttachShader(mShaderProg, fragmentShader);
        glLinkProgram(mShaderProg);
        // check for linking errors
        glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
            ABELIAN_LOG(infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
	}
    OpenGLShader::OpenGLShader(const std::string&& vertexFile, const std::string&& fragmentFile)
    {
        std::string vertexCode;
        std::ifstream vertexSource{ vertexFile };

        if (!vertexSource.is_open())
            ABELIAN_LOG("Error: failed to open vertex shader file");

        std::stringstream vertexTemp;
        vertexTemp << vertexSource.rdbuf();
        vertexCode = vertexTemp.str();
        const char* ansiVertex{ vertexCode.c_str() };

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &ansiVertex, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            ABELIAN_LOG(infoLog);
        }
        // fragment shader
        std::string fragmentCode;
        std::ifstream fragmentSource{ fragmentFile };

        if (!fragmentSource.is_open())
            ABELIAN_LOG("Error: failed to open fragment shader file");

        std::stringstream fragmentTemp;
        fragmentTemp << fragmentSource.rdbuf();
        fragmentCode = fragmentTemp.str();
        const char* ansiFragment{ fragmentCode.c_str() };

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &ansiFragment, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            ABELIAN_LOG("Error: failed to open fragment shader file")
        }
        // link shaders
        mShaderProg = glCreateProgram();
        glAttachShader(mShaderProg, vertexShader);
        glAttachShader(mShaderProg, fragmentShader);
        glLinkProgram(mShaderProg);
        // check for linking errors
        glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
            ABELIAN_LOG(infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    void OpenGLShader::Activate()
    {
        glUseProgram(mShaderProg);
    }

    void OpenGLShader::ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals)
    {
        GLint location{ glGetUniformLocation(mShaderProg, valueName.c_str()) };

        Activate();

        switch (vals.size())
        {
        case 1:
            glUniform1f(location, vals[0]);
            break;
        case 2:
            glUniform2f(location, vals[0], vals[1]);
            break;
        case 3:
            glUniform3f(location, vals[0], vals[1], vals[2]);
            break;
        case 4:
            glUniform4f(location, vals[0], vals[1], vals[2], vals[3]);
            break;
        default:
            ABELIAN_LOG("Error: Shader vals must be vetors of size 1-4");
            break;
        }
    }

    void OpenGLShader::ProvideFloatValues(const std::string&& valueName, const std::vector<float>& vals)
    {
        GLint location{ glGetUniformLocation(mShaderProg, valueName.c_str()) };

        Activate();

        switch (vals.size())
        {
        case 1:
            glUniform1f(location, vals[0]);
            break;
        case 2:
            glUniform2f(location, vals[0], vals[1]);
            break;
        case 3:
            glUniform3f(location, vals[0], vals[1], vals[2]);
            break;
        case 4:
            glUniform4f(location, vals[0], vals[1], vals[2], vals[3]);
            break;
        default:
            ABELIAN_LOG("Error: Shader vals must be vetors of size 1-4");
            break;
        }
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(mShaderProg);
    }
    
}