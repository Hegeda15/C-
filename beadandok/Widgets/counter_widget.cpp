//
// Created by heged on 4/14/2026.
//

#include "counter_widget.hpp"
using namespace genv;


counter_widget::counter_widget(int x, int y, int w, int h, int min, int max)
    : widget(x,y,w,h), min(min), max(max)
{
    value = min;
}
void counter_widget::draw()
{
    // háttér
    gout << move_to(x, y)
         << color(215,255,255)
         << box(w, h);

    // szám
    gout << move_to(x + 5,y + h/2)
         << color(0,0,0)
         << text(std::to_string(value));

    // ↑ gomb
    gout << move_to(x + w - 20, y)
         << color(200,200,200)
         << box(20, h/2);

    gout << move_to(x + w - 18, y+3 + 12)
         << color(0,0,0)
         << text("/\\");

    // ↓ gomb
    gout << move_to(x + w - 20, y + h/2)
         << color(200,200,200)
         << box(20, h/2);

    gout << move_to(x + w - 18, y+3 + h - 10)
         << color(0,0,0)
         << text("\\/");
}


void counter_widget::handle(genv::event ev)
{
    if (ev.type == genv::ev_mouse && ev.button == btn_left)
    {
        if (ev.pos_x >= x && ev.pos_x <= x + w &&
            ev.pos_y >= y && ev.pos_y <= y + h)
        {
            // ↑ gomb
            if (ev.pos_x > x + w - 20 &&
                ev.pos_y < y + h/2)
            {
                value++;
            }
            // ↓ gomb
            else if (ev.pos_x > x + w - 20 &&
                     ev.pos_y >= y + h/2)
            {
                value--;
            }

            if (value < min) value = min;
            if (value > max) value = max;
        }
    }
}

std::string counter_widget::getValue() const
{
    return std::to_string(value);
}

