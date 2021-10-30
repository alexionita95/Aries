#ifndef PHYSICSDATA_H
#define PHYSICSDATA_H
#include<glm/glm.hpp>
namespace aries {
namespace physics {
namespace particles {
struct PhysicsData
{
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 forceAccumulator;
    float damping;
    float mass;
    float inverseMass;
    bool infiniteMass;
    PhysicsData(const glm::vec3& position_,
    const glm::vec3& velocity_,
    const glm::vec3& acceleration_,
    const glm::vec3& forceAccumulator_,
    const float& damping_,
    const float& mass_,
    const float& inverseMass_,
                const bool& infiniteMass_):
    position{position_},
    velocity{velocity_},
      acceleration{acceleration_},
      forceAccumulator{forceAccumulator_},
      damping{damping_},
      mass{mass_},
      inverseMass{inverseMass_},
      infiniteMass{infiniteMass_}
    {
    }
    PhysicsData():
    position{glm::vec3(0)},
    velocity{glm::vec3(0)},
    acceleration{glm::vec3(0)},
    forceAccumulator{glm::vec3(0)},
    damping{0},
    mass{0},
    inverseMass{0},
    infiniteMass{0}
    {

    }
    PhysicsData(const glm::vec3& position_, const float& mass_):
    position{position_},
    velocity{glm::vec3(0)},
    acceleration{glm::vec3(0)},
    forceAccumulator{glm::vec3(0)},
    damping{0},
    mass{mass_},
    inverseMass{0},
    infiniteMass{0}
    {

    }
};
}
}
}
#endif // PHYSICSDATA_H
