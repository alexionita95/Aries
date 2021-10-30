#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H
#include<Physics/Particles/PhysicsData.h>
#include<memory>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
class ForceGenerator
{
public:
    virtual glm::vec3 updateForce(PhysicsData& data, float dt) = 0;
};
using ParticleForceGeneratorHandle = std::shared_ptr<ForceGenerator>;
}
}
}
}
#endif // FORCEGENERATOR_H
