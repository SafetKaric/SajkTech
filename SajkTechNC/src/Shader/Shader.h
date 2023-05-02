#pragma once
#include <string>

struct ShaderProgramSource {
	std::string vertexSource;
	std::string fragmentSource;
};

enum ShaderSourceType {
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_Filepath;

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void UnBind() const;

	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(const unsigned int& type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexSource, const std::string& fragmentSource);

};

