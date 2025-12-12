#include "../include/colorManager.h"

int main(int argc, char** argv) {
    int h = argc > 1 ? atoi(argv[1]) : initialHue;
    int *rgb = _Hue2RGB(h);
    printf("RGB value for HSL {%d, %d, %d}: {%d, %d, %d}\n", h, SATURATION, LIGHTNESS, rgb[0], rgb[1], rgb[2]);
}