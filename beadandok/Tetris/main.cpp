#include "graphics.hpp"
#include <cstdlib>
#include <ctime>

#include "Grid.h"
#include "BlockTypes.h"

using namespace genv;

const int WIDTH = 300;
const int HEIGHT = 600;

int main()
{
    srand(time(0));

    gout.open(WIDTH, HEIGHT);

    Grid grid;
    IBlock block=IBlock();


    gin.timer(16);   // 60 FPS

    event ev;

    while (gin >> ev)
    {
        if (ev.type == ev_timer)
        {
            // háttér törlés
            gout << move_to(0,0)
                 << color(0,0,0)
                 << box(WIDTH, HEIGHT);

            grid.Draw();
            block.Draw();

            gout << refresh;
        }


    }

    return 0;
}