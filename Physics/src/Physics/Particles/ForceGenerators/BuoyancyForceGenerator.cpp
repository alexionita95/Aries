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

glm::vec3 BuoyancyForceGenerator::updateForce(PhysicsData& data, float dt)
{
    float depth = data.position.y;
    if(depth >= liquidHeight + maxDepth) return glm::vec3(0);

    glm::vec3 force(0);
    if(depth <=liquidHeight - maxDepth)
     {
        force.y = liquidDensity*volume;
        return force;
    }

    force.y = liquidDensity*volume*(depth-maxDepth-liquidHeight)/2*maxDepth;
    return force;
}
}
}
}
}
