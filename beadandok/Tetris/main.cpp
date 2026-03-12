#include "graphics.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Grid.h"
using namespace genv;
using namespace std;

const int WIDTH = 400;
const int HEIGHT = 600;


int main() {
    srand(time(0));
    gout.open(WIDTH, HEIGHT);
    Grid grid=Grid();
    grid.Print();

    event ev;

    while (gin >> ev) {
        event ev;
        gin >> ev;

        grid.Draw();
        gout << refresh;
    }

    return 0;
}