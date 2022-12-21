#include "map.h"

Map::Map(int s) {
    x=8, y=8, size=s;

    walls = {
        1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,1,
        1,0,0,1,1,1,1,1,
        1,0,0,0,0,0,0,0,
        1,0,0,1,1,1,1,1,
        1,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,
    };
}

void Map::Draw(Player* p) {
    int ix, iy, xo, yo;
    for (iy = 0; iy < y; iy++) {
        for (ix = 0; ix < x; ix++) {
            if (walls[iy*x+ix]==1) 
                glColor3f(1,1,1);
            else
                glColor3f(0,0,0);
            xo = ix * size;
            yo = iy * size;
            glBegin(GL_QUADS);
                glVertex2i(xo + 1, yo + 1);
                glVertex2i(xo + 1, yo + size - 1);
                glVertex2i(xo - 1 + size, yo + size - 1);
                glVertex2i(xo - 1 + size, yo + 1);
            glEnd();
        }
    }
    DrawRays(p);
}

void Map::DrawRays(Player* p) {
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo, disT;

    ra = FixRotation(p->GetR() - DEG2RAD * 30);

    for(r = 0; r < 480; r++) {
        // Horizontal
        dof = 0;
        float disH = 100000, hx = p->GetPos()->x, hy = p->GetPos()->y;
        float aTan=-1/tan(ra);
        if (ra > PI) {
            ry = (((int)p->GetPos()->y/64)*64)-0.0001;
            rx = (p->GetPos()->y - ry) * aTan + p->GetPos()->x;
            yo = -size;
            xo = -yo * aTan;
        }
        if (ra < PI) {
            ry = (((int)p->GetPos()->y/64)*64)+64;
            rx = (p->GetPos()->y - ry) * aTan + p->GetPos()->x;
            yo = size;
            xo = -yo * aTan;
        }
        if (ra == 0 || ra == PI) {
            rx = p->GetPos()->x;
            ry = p->GetPos()->y;
            dof = 8;
        }
        while (dof < 8) {
            mx = (int)(rx)/64;
            my = (int)(ry)/64;
            mp = my * x + mx;
            if (mp > 0 && mp < x * y && walls[mp] == 1) {
                hx = rx;
                hy = ry;
                disH = Hypot(p->GetPos()->x, p->GetPos()->y, hx, hy, ra);
                dof = 8;
            }
            else {
                rx += xo;
                ry += yo;
                dof++;
            }
        }

        // Vertical
        dof = 0;
        float disV = 100000, vx = p->GetPos()->x, vy = p->GetPos()->y;
        float nTan=-tan(ra);
        if (ra > P2 && ra < P3) {
            rx = (((int)p->GetPos()->x/64)*64)-0.0001;
            ry = (p->GetPos()->x - rx) * nTan + p->GetPos()->y;
            xo = -size;
            yo = -xo * nTan;
        }
        if (ra < P2 || ra > P3) {
            rx = (((int)p->GetPos()->x/64)*64)+64;
            ry = (p->GetPos()->x - rx) * nTan + p->GetPos()->y;
            xo = size;
            yo = -xo * nTan;
        }
        if (ra == 0 || ra == PI) {
            rx = p->GetPos()->x;
            ry = p->GetPos()->y;
            dof = 8;
        }
        while (dof < 8) {
            mx = (int)(rx)/64;
            my = (int)(ry)/64;
            mp = my * x + mx;
            if (mp > 0 && mp < x * y && walls[mp] == 1) {
                vx = rx;
                vy = ry;
                disV = Hypot(p->GetPos()->x, p->GetPos()->y, vx, vy, ra);
                dof = 8;
            }
            else {
                rx += xo;
                ry += yo;
                dof++;
            }
        }
        if (disV < disH) { 
            rx = vx;
            ry = vy;
            disT = disV;
            glColor3f(0, (1 / disT) * 90, (1 / disT) * 70);
        }
        if (disH < disV) {
            rx = hx;
            ry = hy;
            disT = disH;
            glColor3f((1 / disT) * 70, 0, (1 / disT) * 90);
        }
        DrawLine(1, p->GetPos()->x, p->GetPos()->y, rx, ry);
        // draw walls (TODO separate function)
        float ca = FixRotation(p->GetR() - ra);
        // this fixes the fisheye effect
        disT = disT * cos(ca);
        float lineH = (size * 320) / disT;
        if (lineH > 320) lineH = 320;
        float lineO = 160 - (lineH / 2);
        int pntY;
        for (pntY = 0; pntY < lineH; pntY++)
            DrawPoint(1, r + 530, pntY+lineO);
        ra = FixRotation(ra += DEG2RAD / 8);
    }
}
