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

void GravityGenerator::updateForce(const std::shared_ptr<Particle> &particle, float dt)
{
    if(particle->hasInfiniteMass())
        return;
    particle->addForce(gravity*particle->getMass());
}
}
}
}
}
