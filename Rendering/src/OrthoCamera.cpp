#include <OrthoCamera.h>
#include<glm/gtc/matrix_transform.hpp>
namespace aries {
namespace rendering {
OrthoCamera::OrthoCamera()
{
position = glm::vec3(0.0f);
size = glm::vec2(800,600);
updateProjection();
}

OrthoCamera::OrthoCamera(const float &x, const float &y, const float &width, const float &height)
{
    position = glm::vec3(x,y,0);
    size = glm::vec2(width,height);
    updateProjection();
}

void OrthoCamera::updateProjection()
{
    projection = glm::ortho(position.x,position.x+size.x,position.y + size.y,position.y);
}

}
}
