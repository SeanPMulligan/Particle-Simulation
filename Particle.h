#pragma once

namespace scr {
  class Particle {
    public:
      double m_xCord;
      double m_yCord;
      double m_speed;
      double m_direction;

    public:
      Particle();
      void init();
      void update(int interval);
  };
}
