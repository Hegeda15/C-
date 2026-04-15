//
// Created by karar1 on 2026. 03. 25..
//

#include "StaticText.hpp"
#include "graphics.hpp"

using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy, std::string text) : Widget(x,y,sx,sy), _content(text) {
    _cursor_pos = _content.length();
}

void StaticText::draw() {
    canvas can(_size_x, _size_y);
    can << move_to(0, 0) << color(255, 255, 255) << box(_size_x, _size_y);

    int text_x = 5;
    int text_y = (_size_y + can.cascent() - can.cdescent()) / 2;
    can << move_to(text_x, text_y) << color(0, 0, 0) << text(_content);


    int vonal_eltolas = can.twidth(_content.substr(0, _cursor_pos));
    can << move_to(text_x + vonal_eltolas, 5) << color(0, 0, 0) << line(0, _size_y - 10);

    gout << stamp(can, _x, _y);
}

void StaticText::handle(genv::event ev) {
    if (ev.type == ev_key) {
        if (ev.keycode == key_left && _cursor_pos > 0) {
            _cursor_pos--;
        }
        if (ev.keycode == key_right && _cursor_pos < (int)_content.length()) {
            _cursor_pos++;
        }
        if (ev.keycode == key_backspace && _cursor_pos > 0) {
            _content.erase(_cursor_pos - 1, 1);
            _cursor_pos--;
        }
        if (ev.keycode >= 32 && ev.keycode <= 255) {
            std::string temp = "";
            temp += (char)ev.keycode;
            _content.insert(_cursor_pos, temp);
            _cursor_pos++;
        }
    }
}
