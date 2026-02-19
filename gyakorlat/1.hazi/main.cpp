#include "graphics.hpp"
#include <cmath>

using namespace genv;

const int W = 600;
const int H = 600;

double angle = 0.0;
double zoom = 1.0;
bool dragging = false;
int last_x = 0, last_y = 0;

void transform_point(double x, double y, int &rx, int &ry) {
    double sx = x * zoom;
    double sy = y * zoom;
    double s = sin(angle);
    double c = cos(angle);
    double xr = sx * c - sy * s;
    double yr = sx * s + sy * c;
    rx = W / 2 + (int)round(xr);
    ry = H / 2 + (int)round(yr);
}

void draw() {

    gout << color(0, 0, 0) << move_to(0, 0) << box(W, H);


    gout << color(80, 80, 80);



    int base_size = 250;
    int step = 10;
    for (int i = 0; i <= base_size; i += step) {
        double t = (double)i / base_size;
        int r_c = 255 * (1 - t);
        int b_c = 255 * t;
        int x1, y1, x2, y2;


        transform_point(i, 0, x1, y1);
        transform_point(0, -(base_size - i), x2, y2);
        gout << color(r_c, 0, b_c) << move_to(x1, y1) << line_to(x2, y2);


        transform_point(-i, 0, x1, y1);
        transform_point(0, -(base_size - i), x2, y2);
        gout << color(b_c, 0, r_c) << move_to(x1, y1) << line_to(x2, y2);


        transform_point(-i, 0, x1, y1);
        transform_point(0, (base_size - i), x2, y2);
        gout << color(r_c, 0, b_c) << move_to(x1, y1) << line_to(x2, y2);


        transform_point(i, 0, x1, y1);
        transform_point(0, (base_size - i), x2, y2);
        gout << color(b_c, 0, r_c) << move_to(x1, y1) << line_to(x2, y2);
    }


    gout << refresh;
}

int main() {
    gout.open(W, H);
    draw();
    event ev;
    while (gin >> ev) {
        if (ev.type == ev_key && ev.keycode == key_escape) break;
        if (ev.type == ev_mouse && ev.button == btn_left) {
            dragging = true;
            last_x = ev.pos_x;
            last_y = ev.pos_y;
        }
        if (ev.type == ev_mouse && ev.button == -btn_left) dragging = false;
        if (ev.type == ev_mouse && dragging) {
            angle += (ev.pos_x - last_x) * 0.01;
            zoom += (last_y - ev.pos_y) * 0.005;
            if (zoom < 0.1) zoom = 0.1;
            last_x = ev.pos_x;
            last_y = ev.pos_y;
            draw();
        }
    }
    return 0;
}