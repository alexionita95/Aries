#include<glad/glad.h>
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
namespace aries {
namespace rendering {
Shader::Shader()
{

}

void Shader::Load(const std::string& vertexPath, const std::string& fragmentPath)
{
std::string vertexCode;
std::string fragmentCode;
std::ifstream vertexFile;
std::ifstream fragmentFile;
std::stringstream vertexSteam, fragmentStream;


vertexFile.open(vertexPath);
fragmentFile.open(fragmentPath);
vertexSteam << vertexFile.rdbuf();
fragmentStream << fragmentFile.rdbuf();

vertexFile.close();
fragmentFile.close();

vertexCode = vertexSteam.str();
fragmentCode = fragmentStream.str();

vertex = glCreateShader(GL_VERTEX_SHADER);
const char* vertexShaderSource = vertexCode.c_str();
glShaderSource(vertex, 1, &vertexShaderSource, NULL);
glCompileShader(vertex);

int  success;
char infoLog[512];
glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

if(!success)
{
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
}

fragment = glCreateShader(GL_FRAGMENT_SHADER);
const char* fragmentShaderSource = fragmentCode.c_str();
glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
glCompileShader(fragment);

glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

if(!success)
{
    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
}
program = glCreateProgram();
glAttachShader(program, vertex);
glAttachShader(program, fragment);
glLinkProgram(program);

glGetProgramiv(program, GL_LINK_STATUS, &success);
if(!success) {
    glGetProgramInfoLog(program, 512, NULL, infoLog);
   std::cout << "ERROR::LINK\n" << infoLog << std::endl;
}

}

void Shader::Use()
{
    glUseProgram(program);
}

void Shader::setInt(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}
}
}
