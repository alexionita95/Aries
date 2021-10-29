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

void BungeeForceGenerator::updateForce(const std::shared_ptr<Particle> &particle, float dt)
{
    glm::vec3 force = particle->getPosition() - other->getPosition();
    float magnitude = glm::length(force);
    if(magnitude<=restLength) return;
    magnitude = springConstant*(magnitude - restLength);
    force = glm::normalize(force);
    force*=-magnitude;
    particle->addForce(force);





}
}
}
}
}
