#include "../include/particle.h"

void InitParticle(Particle* particle, IntVector2 mouseCoords) {
    *particle = (Particle) {
        .gridCoords = Pixel2Grid(mouseCoords),
        .velocity = ZERO_VECTOR,
        .acceleration = GRAVITY,
        ._fallTimer = 0.0f,
        .color = ColorGenerator(),
        .exists = true,
        .fallen = false
    };
}

bool IsInBounds(Particle* particle) {
    return IsInGrid(particle -> gridCoords);
}

bool IsAtBottom(Particle* particle) {
    return particle -> gridCoords.y == GRID_HEIGHT - 1;
}

void DrawParticle(Particle* particle) {
    IntVector2 pixelCoords = Grid2Pixel(particle -> gridCoords);
    DrawRectangle(
        pixelCoords.x,
        pixelCoords.y,
        CELL_SIZE,
        CELL_SIZE,
        particle -> color
    );
}

Particle* ParticleAt(Particle* particles, IntVector2 gridCoords) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].exists && particles[i].gridCoords.x == gridCoords.x && particles[i].gridCoords.y == gridCoords.y) {
            return &particles[i];
        }
    }
    return NULL;
}

void SimulateFall(Particle* particle, Particle* particles) {
    particle -> _fallTimer += deltaTime;
    particle -> velocity.y += particle -> acceleration.y;

    Particle* belowParticle = ParticleAt(particles, (IntVector2) {particle -> gridCoords.x, particle -> gridCoords.y + 1});
    if (!IsAtBottom(particle) && particle -> _fallTimer >= 1.0f / particle -> velocity.y && (belowParticle == NULL || !belowParticle -> fallen)) {
        if (belowParticle != NULL && !belowParticle ->fallen) {
            particle -> velocity.y = belowParticle -> velocity.y;            
        }
        particle -> gridCoords.y++;
        particle -> _fallTimer = 0.0f;
    }

    if (IsAtBottom(particle) || (belowParticle != NULL && belowParticle -> fallen)) {
        particle -> fallen = true;
    }
}