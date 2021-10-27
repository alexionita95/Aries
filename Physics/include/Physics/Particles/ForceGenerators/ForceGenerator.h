#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H
#include<Physics/Particles/Particle.h>
#include<memory>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
class ForceGenerator
{
public:
    virtual void updateForce(const std::shared_ptr<Particle>& particle, float dt) = 0;
};
using ParticleForceGeneratorHandle = std::shared_ptr<ForceGenerator>;
}
}
}
}
#endif // FORCEGENERATOR_H
