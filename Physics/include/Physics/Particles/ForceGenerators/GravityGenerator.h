#ifndef GRAVITYGENERATOR_H
#define GRAVITYGENERATOR_H
#include<glm/glm.hpp>

#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
class GravityGenerator : public ForceGenerator
{
public:
    GravityGenerator();
    GravityGenerator(const glm::vec3& gravity_);

    // ParticleForceGenerator interface
    glm::vec3 updateForce(PhysicsData& data, float dt);

private:
    glm::vec3 gravity;
};
}
}
}
}
#endif // GRAVITYGENERATOR_H
