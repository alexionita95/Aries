#ifndef PARTICLEFORCEHANDLER_H
#define PARTICLEFORCEHANDLER_H
#include<memory>
#include<vector>
#include<utility>
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
#include<Physics/Particles/Particle.h>

namespace aries {
namespace physics {
namespace particles {
using ParticleForce = std::pair<forcegenerators::ParticleForceGeneratorHandle, ParticleHandle>;

class ForceHandler
{
public:
    ForceHandler();
    ~ForceHandler();
    void add(const forcegenerators::ParticleForceGeneratorHandle& generator, const ParticleHandle& particle);
    void add(const ParticleForce&& force);
    void remove(const forcegenerators::ParticleForceGeneratorHandle& generator, const ParticleHandle& particle);
    void removeAll(const ParticleHandle& particle);
    void update(const float& dt);
    void clear();
private:
    std::vector<ParticleForce> forces;
};
}
}
}

#endif // PARTICLEFORCEHANDLER_H
