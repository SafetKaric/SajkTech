#include "GL/glew.h"
#include "Shader.h"
#include <sstream>
#include <fstream>
#include <iostream>

Shader::Shader(const std::string& filepath)
    :m_RendererID(0), m_Filepath(filepath)
{
    ShaderProgramSource source = ParseShader(m_Filepath);
    m_RendererID = CreateShader(source.vertexSource, source.fragmentSource);
}

Shader::~Shader()
{
}

ShaderProgramSource Shader::ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    std::string line;
    std::stringstream ss[2];
    ShaderSourceType mode = ShaderSourceType::NONE;


    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                mode = ShaderSourceType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                mode = ShaderSourceType::FRAGMENT;
            }
        }
        else {
            ss[(int)mode] << line << std::endl;
        }

    }

    return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(const unsigned int& type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex " : "Fragment ") << "Shader!" << std::endl;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void Shader::Bind() const
{
    glUseProgram(m_RendererID);
}

void Shader::UnBind() const
{
    glUseProgram(0);
}