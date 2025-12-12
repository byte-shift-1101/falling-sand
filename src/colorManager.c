#include "../include/colorManager.h"

int* HSL2RGB(float h, float s, float l) {
    float chroma = (1 - abs(2 * l - 1)) * s;
    float rgb_face_index = h / 60;
    float x = (1 - abs(fmodf(rgb_face_index, 2.0) - 1)) * chroma;

    float r1 = 0, g1 = 0, b1 = 0;
    switch ((int)rgb_face_index) {
    case 0:
        r1 = chroma;
        g1 = x;
        break;
    case 1:
        r1 = x;
        g1 = chroma;
        break;
    case 2:
        g1 = chroma;
        b1 = x;
        break;
    case 3:
        g1 = x;
        b1 = chroma;
        break;
    case 4:
        r1 = x;
        b1 = chroma;
        break;
    case 5:
        r1 = chroma;
        b1 = x;
        break;
    }

    float m = l - chroma / 2;
    int* rgb = (int*) malloc(3 * sizeof(int));
    rgb[0] = (r1 + m) * 255;
    rgb[1] = (g1 + m) * 255;
    rgb[2] = (b1 + m) * 255;
    return rgb;
}

int* _Hue2RGB(float h) {
    return HSL2RGB(fmodf(h, MAX_Hue), SATURATION / MAX_SL, LIGHTNESS / MAX_SL);
}
