#ifndef PARTICLEBUNGEEFORCEGENERATOR_H
#define PARTICLEBUNGEEFORCEGENERATOR_H
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
    void updateForce(const std::shared_ptr<Particle> &particle, float dt);

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
