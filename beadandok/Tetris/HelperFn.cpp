//
// Created by heged on 3/12/2026.
//

#include "HelperFn.h"
using namespace genv;

void DrawRectangle(int x, int y, int width, int height, Color c)
{
    gout << move_to(x, y)
         << color(c.r, c.g, c.b)
         << box(width, height);
}