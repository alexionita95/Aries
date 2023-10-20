#pragma once
#include <glm/glm.hpp>
namespace aries {
namespace rendering {
struct Vertex2D
{
    glm::vec3 Position;
    glm::vec2 TexCoords;
    Vertex2D(const float& x, const float& y, const float& z, const float& texX, const float& texY):
        Position {glm::vec3(x,y,z)},
        TexCoords{glm::vec2{texX,texY}}
    {

    }
};
}
}
