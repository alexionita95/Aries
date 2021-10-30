#include <Physics/Particles/ForceGenerators/AnchoredSpringForceGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
AnchoredSpringForceGenerator::AnchoredSpringForceGenerator()
{

}

AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(const glm::vec3 &anchor_, const float &springConstant_, const float &restLength_):
    anchor{anchor_}, springConstant {springConstant_}, restLength{restLength_}
{

}

glm::vec3 AnchoredSpringForceGenerator::updateForce(PhysicsData& data, float dt)
{
    glm::vec3 force = data.position;
    force-=anchor;
    float magnitude = glm::length(force);
    magnitude =magnitude-restLength;
    magnitude*=springConstant;
    force= glm::normalize(force);
    force*=-magnitude;
    return force;
}
}
}
}
}
