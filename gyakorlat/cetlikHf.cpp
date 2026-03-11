#include "graphics.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace genv;
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

struct Cetli {
private:
    int x, y;
    int m, s;
    bool _kijelolve;
    int szamlalo;
    int _dx, _dy;

public:
    Cetli(int x, int y, int m, int s) : x(x), y(y), m(m), s(s) {
        _kijelolve = false;
        szamlalo = 0;
        _dx = 0; _dy = 0;
    }

    void cetli_rajz() {
        if (!_kijelolve) {
            gout << color(255, 0, 0) << move_to(x, y) << box(m, s)
                 << color(0, 0, 230) << move_to(x + 5, y + 5) << box(m - 10, s - 10);
        } else {
            gout << color(0, 0, 255) << move_to(x, y) << box(m, s)
                 << color(230, 0, 0) << move_to(x + 5, y + 5) << box(m - 10, s - 10);
        }

        string s_szam = to_string(szamlalo);
        gout << color(255, 255, 255)
             << move_to(x + m/2 - gout.twidth(s_szam)/2, y + s/2 + (gout.cascent()-gout.cdescent())/2)
             << text(s_szam);
    }

    bool folotte(int mx, int my) {
        return mx >= x && mx <= x + m && my >= y && my <= y + s;
    }

    void kijelolve(int mx, int my) {
        _kijelolve = true;
        _dx = x - mx;
        _dy = y - my;
    }

    void nem_kijelolve() { _kijelolve = false; }

    bool isKijelolve() { return _kijelolve; }

    void modosit_szamlalo(int d) { szamlalo += d; }

    void mozog(int mx, int my) {
        x = mx + _dx;
        y = my + _dy;

        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x + m > WIDTH) x = WIDTH - m;
        if (y + s > HEIGHT) y = HEIGHT - s;
    }
};

int main() {
    srand(time(0));
    gout.open(WIDTH, HEIGHT);

    vector<Cetli*> cetlis;
    for (int i = 0; i < 15; i++) {
        cetlis.push_back(new Cetli(rand() % (WIDTH-120), rand() % (HEIGHT-80),
                                   rand() % 40 + 80, rand() % 30 + 50));
    }

    event ev;
    bool vonszol = false;

    while (gin >> ev) {
        if (ev.type == ev_key && ev.keycode == key_escape) break;
        if (ev.button == btn_right) {
            int uj_m = rand() % 40 + 80;
            int uj_s = rand() % 30 + 50;

            int korrigalt_x = ev.pos_x;
            int korrigalt_y = ev.pos_y;
            if (korrigalt_x + uj_m > WIDTH) korrigalt_x = WIDTH - uj_m;
            if (korrigalt_y + uj_s > HEIGHT) korrigalt_y = HEIGHT - uj_s;

            cetlis.push_back(new Cetli(korrigalt_x, korrigalt_y, uj_m, uj_s));
        }
        if (ev.type == ev_mouse) {
            if (ev.button == btn_left) {
                vonszol = false;
                for (int i = cetlis.size() - 1; i >= 0; i--) {
                    if (!vonszol && cetlis[i]->folotte(ev.pos_x, ev.pos_y)) {
                        cetlis[i]->kijelolve(ev.pos_x, ev.pos_y);
                        vonszol = true;
                    } else {
                        cetlis[i]->nem_kijelolve();
                    }
                }
            }

            if (ev.button == -btn_left) {
                vonszol = false;
            }

            if (vonszol) {
                for (Cetli* c : cetlis) {
                    if (c->isKijelolve()) c->mozog(ev.pos_x, ev.pos_y);
                }
            }

            if (ev.button == btn_wheelup || ev.button == btn_wheeldown) {
                for (Cetli* c : cetlis) {
                    if (c->isKijelolve()) {
                        c->modosit_szamlalo(ev.button == btn_wheelup ? 1 : -1);
                    }
                }
            }
        }


        gout << color(0, 0, 0) << move_to(0, 0) << box(WIDTH, HEIGHT);
        for (Cetli* c : cetlis) {
            c->cetli_rajz();
        }
        gout << refresh;
    }

    return 0;
}