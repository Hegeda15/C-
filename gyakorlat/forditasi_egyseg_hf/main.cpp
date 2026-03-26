#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "komplex.h"
using namespace genv;
using namespace std;

const int XX = 800;
const int YY = 600;
const int MAX_ITER = 255;

void render(double cx, double cy, double zoom) {
    for (int x = 0; x < XX; x++) {
        for (int y = 0; y < YY; y++) {
            
            komplex c = komplex::from_screen(x, y, XX, YY, cx, cy, zoom);
            komplex z(0, 0);
            int t = 0;

            while (z.re() * z.re() + z.im() * z.im() < 4.0 && t < MAX_ITER) {
                z = z * z + c;
                ++t;
            }


            int color_val = (t == MAX_ITER) ? 0 : (t * 12) % 256;
            gout << move_to(x, y) << color(color_val, color_val, color_val) << dot;
        }
        if (x % 40 == 0) gout << refresh;
    }
    gout << refresh;
}

int main() {
    gout.open(XX, YY);
    double cx = -0.5, cy = 0.0, zoom = 1.0;

    render(cx, cy, zoom);

    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse) {
            bool valtozott = false;

            if (ev.button == btn_wheelup) {
                zoom *= 1.4;
                valtozott = true;
            } else if (ev.button == btn_wheeldown) {
                zoom /= 1.4;
                valtozott = true;
            } else if (ev.button == btn_left) {

                komplex uj_kozep = komplex::from_screen(ev.pos_x, ev.pos_y, XX, YY, cx, cy, zoom);
                cx = uj_kozep.re();
                cy = uj_kozep.im();
                valtozott = true;
            }

            if (valtozott) {

                render(cx, cy, zoom);
            }
        }
    }
    return 0;
}