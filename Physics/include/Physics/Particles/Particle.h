#ifndef PARTICLE_H
#define PARTICLE_H
#include<glm/glm.hpp>
#include<memory>

#include<Physics/Particles/PhysicsData.h>
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
#include<vector>

namespace aries {
namespace physics {
namespace particles {


class Particle
{
public:
    Particle();
    Particle(const glm::vec3& position_,const float& mass_);
    ~Particle()
    {
        generators.clear();
        debugForcesVector.clear();
    }
    void setDamping(const float& damping_)
    {
        data.damping=damping_;
    }
    void setPosition(const glm::vec3& position_)
    {
        data.position = position_;
    }
    void setMass(const float& mass_)
    {
        data.mass=mass_;
        data.inverseMass = 1.0f/mass_;
    }
    void setAcceleration(const glm::vec3& acceleration_)
    {
        data.acceleration = acceleration_;
    }
    void makeInfiniteMass(const bool& value)
    {
        data.infiniteMass = value;
    }
    bool hasInfiniteMass() const
    {
        return data.infiniteMass;
    }

    void update(float dt);
    void addForce(const glm::vec3& force);
    void addGenerator(const forcegenerators::ParticleForceGeneratorHandle& generator);
    void ClearAccumulator()
    {
        data.forceAccumulator=glm::vec3(0);
    }

    const glm::vec3 &getPosition() const;
    const glm::vec3 &getVelocity() const;
    const glm::vec3 &getAcceleration() const;
    const glm::vec3 &getForceAccumulator() const;
    float getDamping() const;
    float getMass() const;
    float getInverseMass() const;
    std::vector<glm::vec3> debugForcesVector;

private:
    PhysicsData data;
    std::vector<forcegenerators::ParticleForceGeneratorHandle> generators;

    void calculateResultantForce(const float& dt);

};
using ParticleHandle = std::shared_ptr<Particle>;
}
}
}

#endif // PARTICLE_H
