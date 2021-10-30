#include <Physics/Particles/Particle.h>
#include<iostream>
#include<algorithm>
namespace aries {
namespace physics {
namespace particles{
Particle::Particle():
    data{PhysicsData()}
{
}

Particle::Particle(const glm::vec3 &position_, const float &mass_):
    data{PhysicsData(position_,mass_)}
{
    setMass(mass_);
}

void Particle::update(float dt)
{
    ClearAccumulator();
    calculateResultantForce(dt);
    data.position += data.velocity*dt;
    glm::vec3 resultAcc =data.acceleration + data.forceAccumulator*data.inverseMass;
    data.velocity +=resultAcc*dt;
    //data.velocity*= powf(data.damping,dt);
    //std::cout<<"velocity:"<<velocity.x<<" "<<velocity.y<<" "<<velocity.z<<std::endl;

}

void Particle::addForce(const glm::vec3 &force)
{
    data.forceAccumulator += force;
}

void Particle::addGenerator(const forcegenerators::ParticleForceGeneratorHandle &generator)
{
     if(std::find(generators.begin(),generators.end(),generator) == generators.end())
     {
         generators.push_back(generator);
     }
}

const glm::vec3 &Particle::getPosition() const
{
    return data.position;
}

const glm::vec3 &Particle::getVelocity() const
{
    return data.velocity;
}

const glm::vec3 &Particle::getAcceleration() const
{
    return data.acceleration;
}

const glm::vec3 &Particle::getForceAccumulator() const
{
    return data.forceAccumulator;
}

float Particle::getDamping() const
{
    return data.damping;
}

float Particle::getMass() const
{
    return data.mass;
}

float Particle::getInverseMass() const
{
    return data.inverseMass;
}

void Particle::calculateResultantForce(const float &dt)
{
    debugForcesVector.clear();
    for(const auto& generator : generators)
    {
        glm::vec3 force =generator->updateForce(data,dt);
        debugForcesVector.push_back(force);
        data.forceAccumulator += force;
    }
}
}
}
}
