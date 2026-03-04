#include "graphics.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace genv;
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int N = 10000;

// Fizikai konstansok
const double vonzas = 40000.0;
const double ido = 0.1;
const double lassitas = 0.99;

struct Particle {
    double x, y;
    double vx, vy;
    unsigned char r, g, b;
};

//random hely és sebessége a részecskéknek
void init_reszecskek(vector<Particle>& p) {
    srand(time(0));

    for (int i = 0; i < N; i++) {
        p[i].x = rand() % WIDTH;
        p[i].y = rand() % HEIGHT;

        p[i].vx = (rand() % 20 - 10);
        p[i].vy = (rand() % 20 - 10);

        p[i].r = 160;
        p[i].g = 180;
        p[i].b = 255;
    }
}

int main() {
    gout.open(WIDTH, HEIGHT);
    gin.timer(10);

    vector<Particle> particles(N);
    init_reszecskek(particles);

    double mx = WIDTH / 2;
    double my = HEIGHT / 2;

    event ev;

    while (gin >> ev) {

        //vonzás az egerhez
        if (ev.type == ev_mouse) {
            mx = ev.pos_x;
            my = ev.pos_y;
        }

        if (ev.type == ev_timer) {

            gout << move_to(0, 0)
                 << color(0, 0, 0)
                 << box(WIDTH, HEIGHT);

            for (int i = 0; i < N; i++) {
                    //részecske mozgasa egérhez
                    double dx = mx - particles[i].x;
                    double dy = my - particles[i].y;

                    double r2 = dx * dx + dy * dy + 400.0;
                    double r = sqrt(r2);

                    double a = vonzas / r2;

                    double ax = a * (dx / r);
                    double ay = a * (dy / r);

                    particles[i].vx = (particles[i].vx + ax * ido) * lassitas;
                    particles[i].vy = (particles[i].vy + ay * ido) * lassitas;

                    particles[i].x += particles[i].vx * ido;
                    particles[i].y += particles[i].vy * ido;

                    double target_dist = 40.0;

                //gyűrü
                if (r < target_dist && r > 0.0001) {
                    //györü átméröje
                    particles[i].vx -= (target_dist - r) * 0.1 * (dx / r);
                    particles[i].vy -= (target_dist - r) * 0.1 * (dy / r);

                    //forgatás
                    particles[i].vx += (-dy / r) * 0.5;
                    particles[i].vy += ( dx / r) * 0.5;
                }

                //sebesseg
                int v = min(255.0,
                    (particles[i].vx * particles[i].vx +
                     particles[i].vy * particles[i].vy) * 2);

                gout << move_to(particles[i].x, particles[i].y)
                     << color(v, 180, 255)
                     << dot;
            }

            gout << refresh;
        }

        if (ev.type == ev_key && ev.keycode == key_escape)
            break;
    }

    return 0;
}