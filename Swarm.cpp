#include "Swarm.h"
namespace scr {

  Swarm::Swarm(): lastTime(0) {
    m_Particles = new Particle[NPARTICLES];
  }

  Swarm::~Swarm() {
    delete[] m_Particles;
  }

  Particle* Swarm::getParticles() {
    return m_Particles;
  }

  void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;

    for (int i = 0; i < scr::Swarm::NPARTICLES; i++) {
      m_Particles[i].update(interval);
    }

    lastTime = elapsed;
  }
}

