#ifndef PARTICLE_H
#define PARTICLE_H

#include "utils.h"
#include "colorManager.h"

#define MAX_PARTICLES (GRID_WIDTH * GRID_HEIGHT)

typedef struct Particle {
    IntVector2 gridCoords;
    Vector2 velocity, acceleration;
    float _fallTimer;
    Color color;
    bool exists, fallen;
} Particle;

void InitParticle(Particle*, IntVector2);
bool IsInBounds(Particle*);
void DrawParticle(Particle*);
Particle* ParticleAt(Particle*, IntVector2);
void SimulateFall(Particle*, Particle*);

#endif