#include <Physics/Particles/ForceGenerators/GravityGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
GravityGenerator::GravityGenerator():
    gravity{glm::vec3(0)}
{

}

GravityGenerator::GravityGenerator(const glm::vec3 &gravity_):
    gravity{gravity_}
{

}

glm::vec3 GravityGenerator::updateForce(PhysicsData& data, float dt)
{
    if(data.infiniteMass)
        return glm::vec3(0);
    return gravity*data.mass;
}
}
}
}
}
