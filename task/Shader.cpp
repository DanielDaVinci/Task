#include "Shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	setVertex(vertexPath);
	setFragment(fragmentPath);
	setProgram();
}

string Shader::getVertexPath() const
{
	return vertexPath;
}

string Shader::getFragmentPath() const
{
	return fragmentPath;
}

void Shader::setVertex(const GLchar* path)
{
	vertexPath = (path == nullptr) ? "" : path;

	string vertexCode = getCodeFromFile(path);

	vertexShader = getShader(GL_VERTEX_SHADER, vertexCode.c_str());
}

void Shader::setFragment(const GLchar* path)
{
	fragmentPath = (path == nullptr) ? "" : path;

	string fragmentCode = getCodeFromFile(path);

	fragmentShader = getShader(GL_FRAGMENT_SHADER, fragmentCode.c_str());
}

void Shader::setProgram()
{
	if (Program != 0)
		glDeleteProgram(Program);

	Program = glCreateProgram();

	glAttachShader(Program, vertexShader);
	glAttachShader(Program, fragmentShader);
	glLinkProgram(Program);

	GLint success;
	GLchar infoLog[512];

	glGetProgramiv(Program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(Program, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}
}

void Shader::setUniform(const char* name, float r, float g, float b)
{
	GLint location = glGetUniformLocation(Program, name);
	glUseProgram(Program);
	glUniform3f(location, r, g, b);
}

void Shader::Use()
{
	glUseProgram(Program);
}

string Shader::getCodeFromFile(const GLchar* path)
{
	string shaderCode;
	ifstream shaderFile;

	shaderFile.exceptions(ifstream::badbit);
	try
	{
		shaderFile.open((path == nullptr) ? "" : path);

		stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();

		shaderFile.close();

		shaderCode = shaderStream.str();
	}
	catch (istream::failure e)
	{
		cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
	}

	return shaderCode;
}

GLuint Shader::getShader(GLenum type, const GLchar* source)
{
	GLuint shader = glCreateShader(type);

	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << endl << infoLog << endl;
	}

	return shader;
}
