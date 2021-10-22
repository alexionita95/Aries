#ifndef ORTHOCAMERA_H
#define ORTHOCAMERA_H
#include <glm/glm.hpp>
namespace aries {
namespace rendering {
class OrthoCamera
{
public:
    OrthoCamera();
    OrthoCamera(const float& x, const float& y, const float& width, const float& height);
    glm::mat4 getProjection(){return projection;}
    glm::vec3 getPosition(){return position;}
    void setPosition(glm::vec3 value){
        position = glm::vec3(value);
        updateProjection();
    }
    glm::vec2 getSize(){return size;}
    void setSize(glm::vec2 value)
    {
        size = glm::vec2(value);
        updateProjection();
    }

private:

    void updateProjection();

    glm::mat4 projection;
    glm::vec3 position;
    glm::vec2 size;
};
}
}

#endif // ORTHOCAMERA_H
