//
// Created by hegkr3 on 2026. 03. 26..
//

#include "graphics.hpp"
#include "StaticText.hpp"
using namespace genv;
StaticText::StaticText(int x, int y, int sx, int sy,std::string text):Widget(x,y,sx,sy),_text(text) {

}

void StaticText::draw() {
   // gout.load_font("")
    canvas can(_size_x, _size_y);
    can << move_to(0, 0) << color(255,0,0) << box(_size_x, _size_y)<< move_to(5, 5) << color(255,255,255)<<text(_text);
    gout<<stamp(can,_x,_y);
}

void StaticText::handle(event) {

}


