#include <Physics/Particles/ForceGenerators/SpringForceGenerator.h>
#include<math.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
SpringForceGenerator::SpringForceGenerator()
{

}

SpringForceGenerator::SpringForceGenerator(const ParticleHandle &other_, const float& springConstant_, const float& restLength_):
    other{other_}, springConstant{springConstant_}, restLength{restLength_}
{

}

void SpringForceGenerator::updateForce(const std::shared_ptr<Particle> &particle, float dt)
{
glm::vec3 force = particle->getPosition();
force-=other->getPosition();
float magnitude = glm::length(force);
magnitude =magnitude-restLength;
magnitude*=springConstant;
force = glm::normalize(force);
force*=-magnitude;
particle->addForce(force);
}
}
}
}
}
