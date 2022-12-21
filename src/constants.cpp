#include "constants.h"

float Hypot(float ax, float ay, float bx, float by, float r) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

float FixRotation(float r) {
    if (r < 0) 
        r += 2 * PI;
    if (r > 2 * PI)
        r -= 2 * PI;
    return r;
}
