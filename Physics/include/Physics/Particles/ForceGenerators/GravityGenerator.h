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
    void updateForce(const std::shared_ptr<Particle> &particle, float dt);

private:
    glm::vec3 gravity;
};
}
}
}
}
#endif // GRAVITYGENERATOR_H
