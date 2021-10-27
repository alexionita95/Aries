#ifndef PARTICLE_H
#define PARTICLE_H
#include<glm/glm.hpp>
#include<memory>
namespace aries {
namespace physics {
namespace particles {


class Particle
{
public:
    Particle();
    Particle(const glm::vec3& position_,const float& mass_);
    void setDamping(const float& damping_)
    {
        damping=damping_;
    }
    void setPosition(const glm::vec3& position_)
    {
        position = position_;
    }
    void setMass(const float& mass_)
    {
        mass=mass_;
        inverseMass = 1.0f/mass;
    }
    void setAcceleration(const glm::vec3& acceleration_)
    {
        acceleration = acceleration_;
    }
    void makeInfiniteMass(const bool& value)
    {
        infiniteMass = value;
    }
    bool hasInfiniteMass() const
    {
        return infiniteMass;
    }

    void integrate(float dt);
    void addForce(const glm::vec3& force);
    void ClearAccumulator()
    {
        forceAccumulator=glm::vec3(0);
    }

    const glm::vec3 &getPosition() const;
    const glm::vec3 &getVelocity() const;
    const glm::vec3 &getAcceleration() const;
    const glm::vec3 &getForceAccumulator() const;
    float getDamping() const;
    float getMass() const;
    float getInverseMass() const;

private:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 forceAccumulator;
    float damping;
    float mass;
    float inverseMass;
    bool infiniteMass;

};
using ParticleHandle = std::shared_ptr<Particle>;
}
}
}

#endif // PARTICLE_H
