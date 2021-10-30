#include <Physics/Particles/ForceGenerators/DragForceGenerator.h>

#include<glm/glm.hpp>
#include<iostream>

namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
DragForceGenerator::DragForceGenerator():k1{0},k2{0}
{

}

DragForceGenerator::DragForceGenerator(const float &k1_, const float &k2_):
    k1{k1_},k2(k2_)
{
std::cout<<"Coeffs:"<<k1<<" "<<k2<<std::endl;
}

glm::vec3 DragForceGenerator::updateForce(PhysicsData& data, float dt)
{
    glm::vec3 force = data.velocity;
    float dragCoeff = glm::length(force);
    dragCoeff = k1*dragCoeff + k2*dragCoeff*dragCoeff;
    if(force==glm::vec3(0)) return force;
    force = glm::normalize(force);
    force*=-dragCoeff;

    return force;
}
}
}
}
}
