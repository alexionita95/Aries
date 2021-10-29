#include <Physics/Particles/Particle.h>

namespace aries {
namespace physics {
namespace particles{
Particle::Particle():
    position{glm::vec3(0)}, velocity{glm::vec3(0)}, acceleration { glm::vec3(0)}, damping {0.0f}, infiniteMass{false}
{
}

Particle::Particle(const glm::vec3 &position_, const float &mass_):
    position{position_}, velocity{glm::vec3(0)}, acceleration { glm::vec3(0)}, damping {0.0f}, infiniteMass{false}
{
    setMass(mass_);
}

void Particle::integrate(float dt)
{
    position += velocity*dt;
    glm::vec3 resultAcc = forceAccumulator*inverseMass;
    velocity +=resultAcc*dt;
    velocity*= pow(damping,dt);
    ClearAccumulator();
}

void Particle::addForce(const glm::vec3 &force)
{
    forceAccumulator += force;
}

const glm::vec3 &Particle::getPosition() const
{
    return position;
}

const glm::vec3 &Particle::getVelocity() const
{
    return velocity;
}

const glm::vec3 &Particle::getAcceleration() const
{
    return acceleration;
}

const glm::vec3 &Particle::getForceAccumulator() const
{
    return forceAccumulator;
}

float Particle::getDamping() const
{
    return damping;
}

float Particle::getMass() const
{
    return mass;
}

float Particle::getInverseMass() const
{
    return inverseMass;
}
}
}
}
