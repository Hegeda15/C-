#include "graphics.hpp"
#include <cmath>
#include <ctime>
#include <random>
#include <vector>

using namespace genv;
using namespace std;

const int szel = 600;
const int mag = 600;

struct Ho {
    Ho(int xx, int yy): x(xx), y(yy) {}

    void rajzol() {
        gout << color(255,255,255)
             << move_to(x,y)
             << dot;
    }

    void mozog(int dx, int dy) {
        x += dx;

        if (x < 0) x = szel-1;
        if (x >= szel) x = 0;

        y = (y + dy) % mag;
    }

private:
    int x,y;
};

int main()
{
    srand(time(0));

    int n = 1000;
    gout.open(szel,mag);

    vector<Ho> v;

    for (int i = 0; i < n; i++) {
        v.push_back(Ho(rand()%szel, rand()%mag));
    }

    int eger_x = szel/2;

    event ev;
    gin.timer(50);

    while (gin >> ev) {

        // Egér pozíció mentése
        if (ev.type == ev_mouse) {
            eger_x = ev.pos_x;
        }

        if (ev.type == ev_timer) {

            // Egérből számolt szél
            int szel_irany = (eger_x - szel/2) / 40;

            // háttér törlés
            gout << move_to(0,0)
                 << color(0,0,0)
                 << box(szel,mag);

            for (int i = 0; i < v.size(); i++) {

                // EREDETI random mozgás
                int random_dx = rand()%7 - 3;
                int random_dy = rand()%11 - 3;

                // hozzáadjuk az egér által vezérelt szelet
                v[i].mozog(random_dx + szel_irany, random_dy);
                v[i].rajzol();
            }

            gout << refresh;
        }
    }

    return 0;
}