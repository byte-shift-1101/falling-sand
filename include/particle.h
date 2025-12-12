#ifndef PARTICLE_H
#define PARTICLE_H

#include "utils.h"
#include "colorManager.h"

typedef struct Particle {
    int pos_x, pos_y;
    Color color;
    bool exists;
} Particle;

void AddParticle(Particle*);
bool IsInBounds(Particle*);

#endif