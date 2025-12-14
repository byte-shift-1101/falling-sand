#include "../include/utils.h"
#include "../include/particle.h"

Particle* particles;
int particleCount;

void StartSimulation() {
    InitSystem();

    particles = (Particle*) calloc(MAX_PARTICLES, sizeof(Particle));
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].exists = false;
    }
    particleCount = 0;
}

void LoopSimulation() {
    SystemLoop();

    // Needs Refinement
    // 1. Contained in Grid Check (and overall check to see if init particle is allowed)
    // 2. Internal working of particleCount++ is a uneasy
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !IsInCooldown() && particleCount < MAX_PARTICLES && IsPixelInGrid(mouseCoords) && !ParticleAt(particles, Pixel2Grid(mouseCoords))) {
        InitParticle(&particles[particleCount], mouseCoords);
        particleCount++;
        RestartCooldown();
    }

    for (int i = 0; i < particleCount; i++) {
        DrawParticle(&particles[i]);
        SimulateFall(&particles[i], particles);
    }
}

void EndSimulation() {
    free(particles);

    CloseSystem();
}

int main() {
    StartSimulation();
    while (!WindowShouldClose()) {
        BeginDrawing();
            LoopSimulation();
        EndDrawing();
    }
    EndSimulation();

    return 0;
}