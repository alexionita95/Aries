#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
namespace aries {
namespace rendering {
class Shader
{
public:
    Shader();
    void Load(const std::string& vertexPath, const std::string& fragmentPath);
    void Use();
    void setInt(const std::string& name, int value);
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    int getId(){return program;}
private:
    int program;
    int vertex;
    int fragment;
};
}
}

#endif // SHADER_H
