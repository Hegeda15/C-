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

void DrawTxt(int x,int y,std::string txt) {
    gout << color(255,255,0)
        << move_to(x,y)
        << text(txt);
}