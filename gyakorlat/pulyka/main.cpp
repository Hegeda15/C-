#include "graphics.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace genv;
using namespace std;

struct Csirke {

    Csirke(string fajlnev) {
        ifstream befajl(fajlnev);
        int szel, mag;

        befajl >> szel >> mag;

        v = vector<vector<vector<int>>>(mag,
            vector<vector<int>>(szel, vector<int>(3)));

        for (int j = 0; j < mag; j++) {
            for (int i = 0; i < szel; i++) {
                befajl >> v[j][i][0]
                        >> v[j][i][1]
                        >> v[j][i][2];
            }
        }

        befajl.close();
    }

    
    void rajzol(int px, int py) {
        for (int j = 0; j < v.size(); j++) {
            for (int i = 0; i < v[j].size(); i++) {

                int r = v[j][i][0];
                int g = v[j][i][1];
                int b = v[j][i][2];

                gout << color(r, g, b)
                     << move_to(px + i, py + j)
                     << dot;
            }
        }
    }

    int szelesseg() { return v[0].size(); }
    int magassag() { return v.size(); }

private:
    vector<vector<vector<int>>> v;
};

int main() {
    Csirke csirke("a.kep");

    int ablak_sz = 800;
    int ablak_mag = 600;

    gout.open(ablak_sz, ablak_mag);

    int x = 100;
    int y = 100;

    event ev;

    while (gin >> ev) {


        if (ev.type == ev_mouse && ev.button == 0) {
            x = ev.pos_x - csirke.szelesseg()/2;
            y = ev.pos_y - csirke.magassag()/2;
        }


        gout << move_to(0,0)
            << color(0,0,0)
             << box(ablak_sz, ablak_mag);


        csirke.rajzol(x, y);

        gout << refresh;
    }

    return 0;
}