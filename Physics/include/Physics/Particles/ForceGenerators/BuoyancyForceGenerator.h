#ifndef PARTICLEBUOYANCYFORCEGENERATOR_H
#define PARTICLEBUOYANCYFORCEGENERATOR_H
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{

class BuoyancyForceGenerator : public ForceGenerator
{
public:
    BuoyancyForceGenerator();
    BuoyancyForceGenerator(const float& maxDepth_, const float& volume_, const float& liquidHeight_, const float& liquidDensity_ = 1000.0f);

    // ForceGenerator interface
    void updateForce(const std::shared_ptr<Particle> &particle, float dt);
private:
    float maxDepth;
    float volume;
    float liquidHeight;
    float liquidDensity;
};
}
}
}
}

#endif // PARTICLEBUOYANCYFORCEGENERATOR_H
