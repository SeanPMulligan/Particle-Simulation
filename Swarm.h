#pragma once
#include "Particle.h"

namespace scr {
  class Swarm {
    public:
      const static int NPARTICLES = 5000;
    private:
      Particle *m_Particles;
      int lastTime;
    public:
      Swarm();
      virtual ~Swarm();
      Particle *getParticles();
      void update(int elapsed);
  };
}
