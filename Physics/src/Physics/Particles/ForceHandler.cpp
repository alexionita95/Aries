#include <Physics/Particles/ForceHandler.h>
#include<algorithm>
namespace aries {
namespace physics {
namespace particles{
ForceHandler::ForceHandler()
{

}

ForceHandler::~ForceHandler()
{
    clear();
}

void ForceHandler::add(const forcegenerators::ParticleForceGeneratorHandle &generator, const ParticleHandle &particle)
{
    add(std::make_pair(generator,particle));

}

void ForceHandler::add(const ParticleForce &&force)
{
    if(std::find(forces.begin(),forces.end(),force) == forces.end())
    {
        forces.push_back(std::move(force));
    }
}

void ForceHandler::remove(const forcegenerators::ParticleForceGeneratorHandle &generator, const ParticleHandle &particle)
{
    std::remove_if(forces.begin(),forces.end(),[&generator, &particle](const auto& force){
        return force.first == generator && force.second == particle;
    });
}

void ForceHandler::removeAll(const ParticleHandle &particle)
{
    std::remove_if(forces.begin(),forces.end(),[&particle](const auto& force){
        return force.second == particle;
    });
}

void ForceHandler::update(const float &dt)
{
    for(const auto& force:forces)
    {
     //   force.first->updateForce(force.second,dt);
    }
}

void ForceHandler::clear()
{
    forces.clear();
}
}
}
}
