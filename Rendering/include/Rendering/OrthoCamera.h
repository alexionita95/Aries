#ifndef ORTHOCAMERA_H
#define ORTHOCAMERA_H
#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
namespace aries {
namespace rendering {
class OrthoCamera
{
public:
    OrthoCamera();
    OrthoCamera(const float left, const float right, const float bottom, const float top);
    const glm::mat4& getProjection() const {return projection;}
    const glm::mat4& getView() const { return view; }
    const float& getZoom() const { return zoom; }
    glm::vec3 getPosition(){return position;}
    void setPosition(glm::vec3 value){
        position = glm::vec3(value);
        calculateViewMatrix();
    }
    void setZoom(const float value)
    {
        zoom = value;
        calculateViewMatrix();
    }
    glm::vec2 getSize(){return size;}

private:
    void calculateViewMatrix();
    glm::vec3 position;
    glm::vec2 size;
    float zoom;
    glm::mat4 projection;
    glm::mat4 view;
};
}
}

#endif // ORTHOCAMERA_H
