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

glm::vec3 SpringForceGenerator::updateForce(PhysicsData& data, float dt)
{
glm::vec3 force = data.position;
force-=other->getPosition();
float magnitude = glm::length(force);
magnitude =magnitude-restLength;
magnitude*=springConstant;
force = glm::normalize(force);
force*=-magnitude;
return force;
}
}
}
}
}
