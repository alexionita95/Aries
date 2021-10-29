#include <Physics/Particles/ForceGenerators/BuoyancyForceGenerator.h>
namespace aries {
namespace physics {
namespace particles{
namespace forcegenerators{
BuoyancyForceGenerator::BuoyancyForceGenerator()
{

}

BuoyancyForceGenerator::BuoyancyForceGenerator(const float &maxDepth_, const float &volume_, const float &liquidHeight_, const float &liquidDensity_):
    maxDepth{maxDepth_}, volume{volume_}, liquidHeight{liquidHeight_}, liquidDensity{liquidDensity_}
{

}

void BuoyancyForceGenerator::updateForce(const std::shared_ptr<Particle> &particle, float dt)
{
    float depth = particle->getPosition().y;
    if(depth >= liquidHeight + maxDepth) return;

    glm::vec3 force(0);
    if(depth <=liquidHeight - maxDepth)
     {
        force.y = liquidDensity*volume;
        particle->addForce(force);
        return;
    }

    force.y = liquidDensity*volume*(depth-maxDepth-liquidHeight)/2*maxDepth;
    particle->addForce(force);
}
}
}
}
}
