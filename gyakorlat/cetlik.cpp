#include "graphics.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace genv;
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

struct Cetli {

    Cetli(int x, int y, int m, int s): x(x), y(y), m(m), s(s) {
        _kijelolve = false;
    }

    void cetli_rajz() {

        if (!_kijelolve) {
            gout << color(255,0,0) << move_to(x,y)
                 << box(m,s)
                 << color(0,0,230)
                 << move_to(x+5,y+5)
                 << box(m-10,s-10);
        }
        else {
            gout << color(0,0,255) << move_to(x,y)
                 << box(m,s)
                 << color(230,0,0)
                 << move_to(x+5,y+5)
                 << box(m-10,s-10);
        }
    }

    bool folotte(int mx,int my) {
        return mx >= x && mx <= x+m && my >= y && my <= y+s;
    }

    void kijelolve() {
        _kijelolve = true;
    }

    void nem_kijelolve() {
        _kijelolve = false;
    }
    void mozog(int mx,int my) {
        x=mx+_dx;y=my+_dy;
    }
    bool isKijelolve() {
        return _kijelolve;
    }
    void megmarad(int mx,int my) {
        _dx = mx-x;
        _dy = my-y;
    }


private:
   
    int x,y;
    int m,s;
    bool _kijelolve;
    int count =0;
    int _dx,_dy;

};

int main() {

    srand(time(0));

    gout.open(WIDTH, HEIGHT);

    vector<Cetli*> cetlis;

    for (int i=0;i<20;i++) {
        cetlis.push_back(new Cetli(rand()%WIDTH,rand()%HEIGHT,
                                   rand()%40+80,rand()%30+50));
    }

    event ev;

    while (gin >> ev) {

        if (ev.type == ev_mouse && ev.button == btn_left) {

            for (Cetli* c : cetlis) {
                if (c->folotte(ev.pos_x, ev.pos_y)) {
                    c->kijelolve();
                }
                else {
                    c->nem_kijelolve();
                }
            }
        }else if (ev.button==0) {
            for (Cetli* c : cetlis) {
                if (c->isKijelolve()) {
                    c->mozog(ev.pos_x, ev.pos_y);
                }
            }
        }

        gout << color(0,0,0) << move_to(0,0) << box(WIDTH,HEIGHT);

        for (Cetli* c : cetlis) {
            c->cetli_rajz();
        }

        gout << refresh;
    }

    return 0;
}