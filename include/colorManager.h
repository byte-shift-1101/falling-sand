#ifndef COLOR_MANAGER_H
#define COLOR_MANAGER_H

#include "utils.h"

#define HUE_STEP 20
#define SATURATION 100
#define LIGHTNESS 50
#define MAX_Hue 360
#define MAX_SL 100

static int initialHue = 0;
int* HSL2RGB(float, float, float);
int* _Hue2RGB(float);
Color ColorGenerator();

#endif