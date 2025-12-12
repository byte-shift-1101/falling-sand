#include "colorManager.h"

int main() {
    int h = 100;
    int *rgb = _Hue2RGB(h);
    printf("RGB value for HSL {%d, %d, %d}: {%d, %d, %d}\n", h, SATURATION, LIGHTNESS, rgb[0], rgb[1], rgb[2]);
}