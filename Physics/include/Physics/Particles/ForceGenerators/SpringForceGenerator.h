#ifndef PARTICLESPRINGFORCEGENERATOR_H
#define PARTICLESPRINGFORCEGENERATOR_H
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
#include<Physics/Particles/Particle.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
class SpringForceGenerator : public ForceGenerator
{
public:
    SpringForceGenerator();
    SpringForceGenerator(const ParticleHandle& other_, const float& springConstant_, const float& restLength_);

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
#endif // PARTICLESPRINGFORCEGENERATOR_H
