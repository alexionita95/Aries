#ifndef PARTICLEANCHOREDSPRINGFORCEGENERATOR_H
#define PARTICLEANCHOREDSPRINGFORCEGENERATOR_H
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
#include<glm/glm.hpp>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{

class AnchoredSpringForceGenerator : public ForceGenerator
{
public:
    AnchoredSpringForceGenerator();
    AnchoredSpringForceGenerator(const glm::vec3& anchor_, const float& springConstant_, const float& restLength_);

    // ForceGenerator interface
    void updateForce(const std::shared_ptr<Particle> &particle, float dt);

private:
    glm::vec3 anchor;
    float springConstant;
    float restLength;

};
}
}
}
}

#endif // PARTICLEANCHOREDSPRINGFORCEGENERATOR_H
