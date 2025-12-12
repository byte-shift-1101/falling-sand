#ifndef PARTICLE_H
#define PARTICLE_H

#include "utils.h"

typedef struct Particle {
    int x;
    float y;
    float vy;
    Color color;
    bool fallen;
} Particle;

#endif