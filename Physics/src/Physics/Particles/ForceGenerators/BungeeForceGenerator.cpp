#include <Physics/Particles/ForceGenerators/BungeeForceGenerator.h>
#include<iostream>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
BungeeForceGenerator::BungeeForceGenerator()
{

}

BungeeForceGenerator::BungeeForceGenerator(const ParticleHandle &other_, const float &springConstant_, const float &restLength_):
    other{other_},springConstant{springConstant_}, restLength{restLength_}
{

}

glm::vec3 BungeeForceGenerator::updateForce(PhysicsData& data, float dt)
{
    glm::vec3 force = data.position - other->getPosition();
    float magnitude = glm::length(force);
    if(magnitude<=restLength) glm::vec3(0);
    magnitude = springConstant*(magnitude - restLength);
    force = glm::normalize(force);
    force*=-magnitude;
    return force;





}
}
}
}
}
