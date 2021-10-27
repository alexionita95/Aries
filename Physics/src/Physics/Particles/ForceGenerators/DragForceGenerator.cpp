#include <Physics/Particles/ForceGenerators/DragForceGenerator.h>

#include<glm/glm.hpp>

namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
DragForceGenerator::DragForceGenerator()
{

}

DragForceGenerator::DragForceGenerator(const float &k1_, const float &k2_):
    k1{k1_},k2(k2_)
{

}

void DragForceGenerator::updateForce(const std::shared_ptr<Particle> &particle, float dt)
{
    glm::vec3 force = particle->getVelocity();
    float dragCoeff = force.length();
    dragCoeff = k1*dragCoeff + k2*dragCoeff*dragCoeff;
    force = glm::normalize(force);
    force*=-dragCoeff;
    particle->addForce(force);
}
}
}
}
}
