#include "graphics.hpp"
#include <cstdlib>
#include <ctime>
#include "HelperFn.h"
#include "Grid.h"
#include "BlockTypes.h"
#include "GamePlan.h"
#include <string>
using namespace genv;

const int WIDTH = 500;
const int HEIGHT = 620;
int lastDrop=0;
int main()
{
    srand(time(0));

    gout.open(WIDTH, HEIGHT);


    GamePlan game=GamePlan();

    gin.timer(16);   // 60 FPS

    event ev;

    while (gin >> ev)
    {
        if (ev.type == ev_timer|| ev.type == ev_key)
        {
            // háttér törlés
            gout << move_to(0,0)
                 << color(0,0,0)
                 << box(WIDTH, HEIGHT);

            if (ev.time-lastDrop>game.GetFallSpeed()) {
                game.MoveD();
                lastDrop = ev.time;
            }
            int currentLevel = (game.clearedRowsCount / 10) + 1;

            DrawTxt(380,30,"Score");
            DrawTxt(395,60,std::to_string(game.score));


            DrawTxt(380, 140, "Level");
            DrawTxt(397, 170, std::to_string(currentLevel));
            DrawTxt(380,250,"Next");
            if (game.gameOver) {
                DrawTxt(370,400,"GAME OVER");
                DrawTxt(370, 430, "PRESS ANY KEY");
            }

            game.HandleMovement(ev);
            game.Draw();
            gout << refresh;
        }
        if (ev.type == ev_key && ev.keycode == key_escape)
            break;

    }

    return 0;
}