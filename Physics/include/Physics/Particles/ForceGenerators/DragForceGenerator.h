#ifndef PARTICLEDRAGFORCEGENERATOR_H
#define PARTICLEDRAGFORCEGENERATOR_H
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
class DragForceGenerator : public ForceGenerator
{
public:
    DragForceGenerator();
    DragForceGenerator(const float& k1_, const float& k2_);

    // ForceGenerator interface
    void updateForce(const std::shared_ptr<Particle> &particle, float dt);
private:
    float k1;
    float k2;
};
}
}
}
}
#endif // PARTICLEDRAGFORCEGENERATOR_H
