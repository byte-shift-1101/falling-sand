#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "raylib.h"

#define GRID_WIDTH 40
#define GRID_HEIGHT 40
#define PARTICLE_SIZE 10

#define SCREEN_WIDTH GRID_WIDTH * PARTICLE_SIZE
#define SCREEN_HEIGHT GRID_HEIGHT * PARTICLE_SIZE

#define COOLDOWN_PERIOD 0.1f
static double cooldownTimer;
static double deltaTime;

void RestartCooldown() { cooldownTimer = COOLDOWN_PERIOD; }
bool IsInCooldown() { return cooldownTimer > 0; }
void DecrementCooldown() {
    if (!IsInCooldown()) cooldownTimer -= deltaTime;
}

#endif