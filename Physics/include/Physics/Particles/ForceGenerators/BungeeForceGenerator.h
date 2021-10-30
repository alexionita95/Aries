#ifndef PARTICLEBUNGEEFORCEGENERATOR_H
#define PARTICLEBUNGEEFORCEGENERATOR_H
#include<Physics/Particles/Particle.h>
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
class BungeeForceGenerator : public ForceGenerator
{
public:
    BungeeForceGenerator();
    BungeeForceGenerator(const ParticleHandle& other_, const float& springConstant_, const float& restLength_);

    // ForceGenerator interface
    glm::vec3 updateForce(PhysicsData& data, float dt);

private:
    ParticleHandle other;
    float springConstant;
    float restLength;
};
}
}
}
}

#endif // PARTICLEBUNGEEFORCEGENERATOR_H
