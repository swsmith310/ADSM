#include "gfx.h"

void DrawLine(int w, float x1, float y1, float x2, float y2) {
    glLineWidth(w);
    glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
    glEnd();
}

void DrawPoint(int w, float x, float y) {
    glPointSize(w);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

