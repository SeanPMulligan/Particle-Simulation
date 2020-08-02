#include "Particle.h"
#include <stdlib.h>
#include <cmath>
namespace scr {

  Particle::Particle(): m_xCord(0), m_yCord(0) {
    init();
  }

  void Particle::init() {
    m_xCord = 0;
    m_yCord = 0;
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.04 * rand())/RAND_MAX;

    m_speed *= m_speed;

  }

  void Particle::update(int interval) {
    m_direction += interval*0.0004;
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_xCord += xspeed * interval;
    m_yCord += yspeed * interval;

    if (m_xCord < -1 || m_xCord > 1 || m_yCord < -1 || m_yCord > 1) {
      init();
    }

    if (rand() < RAND_MAX/100) {
      init();
    }
  }
}
