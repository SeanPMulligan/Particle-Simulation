#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "Screen.h"

int main() {
  std::srand(std::time(NULL));

  scr::Screen screen;

  if (!screen.init()) {
    std::cout << "Error initializing screen" << std::endl;
  }

  scr::Swarm swarm;

  while (true) {
    const scr::Particle *pParticles = swarm.getParticles();
    int elapsed = SDL_GetTicks();
    unsigned char green = (1 + std::sin(elapsed * 0.002)) * 128;
    unsigned char red = (1 + std::sin(elapsed * 0.001)) * 128;
    unsigned char blue = (1 + std::sin(elapsed * 0.003)) * 128;

    swarm.update(elapsed);

    for (int i = 0; i < scr::Swarm::NPARTICLES; i++) {
      scr::Particle particle = pParticles[i];

      int x = (particle.m_xCord + 1) * scr::Screen::SCREEN_WIDTH / 2;
      int y = particle.m_yCord * scr::Screen::SCREEN_WIDTH / 2 + scr::Screen::SCREEN_HEIGHT / 2;

      screen.setPixel(x, y, red, green, blue);
    }

    screen.boxBlur();

    screen.update();

    if (!screen.processEvents()) {
      break;
    }
  }

  screen.close();

  return 0;
}
