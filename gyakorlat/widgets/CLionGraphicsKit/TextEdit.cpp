//
// Created by hegkr3 on 2026. 03. 26..
//

#include "TextEdit.hpp"
using namespace genv;
TextEdit::TextEdit(int x, int y, int sx, int sy, std::string text):Widget(x,y,sx,sy),_text(text) {

}

void TextEdit::draw() {
    canvas can(_size_x, _size_y);

    can<< move_to(0,0)
        <<color(255,255,255)
        <<box(_size_x,_size_y)
        <<move_to(5,5)
    <<color(0,0,0)
    <<text(_text);
    gout<<stamp(can,_x, _y);
}

void TextEdit::handle(event ev) {
    if (ev.type==ev_key) {

            _text+=ev.keyutf8;

    }
}