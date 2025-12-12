#include "../include/particle.h"

void AddParticle(Particle* particle) {
    *particle = (Particle) {
        .pos_x = GetMouseX(),
        .pos_y = GetMouseY(),
        .color = ColorGenerator(),
        .exists = true
    };
}

bool IsInBounds(Particle* particle) {
    bool xBounded = (0 <= particle -> pos_x && particle -> pos_x < SCREEN_WIDTH);
    bool yBounded = (0 <= particle -> pos_y && particle -> pos_y < SCREEN_HEIGHT);
    return xBounded && yBounded;
}