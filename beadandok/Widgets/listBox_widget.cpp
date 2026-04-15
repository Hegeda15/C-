//
// Created by heged on 4/14/2026.
//


#include "listBox_widget.hpp"
using namespace genv;

listBox_widget::listBox_widget(int x, int y, int w, int h, const std::vector<std::string>& items)
    : widget(x,y,w,h), items(items)
{
    selectedItemIndex = 0;
}
int scrollOffset = 0;

void listBox_widget::draw()
{
    int lineHeight = 20;
    int maxVisible = h / lineHeight;

    // Háttér és keret (marad a régi)
    gout << move_to(x, y) << color(220,220,220) << box(w, h);
    gout << move_to(x, y) << color(0,0,0) << line(w,0) << line(0,h) << line(-w,0) << line(0,-h);

    // Elemek kirajzolása eltolással
    for (int i = 0; i < maxVisible; i++)
    {
        int actualIndex = i + scrollOffset; // Ez a valódi index a listában
        if (actualIndex >= items.size()) break; // Ha elfogytak az elemek, megállunk

        int itemY = y + i * lineHeight;

        // Kijelölés (most már az actualIndex alapján!)
        if (actualIndex == selectedItemIndex)
        {
            gout << move_to(x+1, itemY+1)
                 << color(150,150,255)
                 << box(w-2, lineHeight-2);
        }

        // Szöveg kirajzolása
        gout << move_to(x + 5, itemY + lineHeight - 5)
             << color(0,0,0)
             << text(items[actualIndex]);


    }

    if (items.size() > 0) {
        int scrollB_width=15;
        int scrollB_x=x+w-scrollB_width;

        int visibility=h/20;
        double ratio=(double)visibility/items.size();
        if (ratio > 1.0) ratio = 1.0;
        int scrollB_height=ratio*h;
        if (scrollB_height < 20) scrollB_height = 20;

        double scrollMove=0;
        if (items.size()>visibility) {
            scrollMove=(double)scrollOffset/(items.size()-visibility);
        }
        int scrollY=y+scrollMove*(h-scrollB_height);

        gout<<move_to(scrollB_x+15,scrollY)
        <<color(100,100,100)
        <<box(scrollB_width-4,scrollB_height);
    }
}
void listBox_widget::handle(event ev)
{

    int scrollB_W=15;
    int visibility=h/20;
    if (ev.type==ev_mouse && ev.button==btn_left) {
        if (ev.pos_x>=x+w-scrollB_W&&ev.pos_x<=x+w) {
            double ratio=(double)(ev.pos_y-y)/h;
            scrollOffset=ratio*(items.size()-visibility);

            if (scrollOffset<0) scrollOffset=0;
            if (scrollOffset>items.size()-visibility) scrollOffset=items.size()-visibility;
        }
    }

    // 1. Ellenőrizzük, hogy a listbox felett van-e az egér
    bool isOver = ev.pos_x >= x && ev.pos_x <= x+w+10 &&
                  ev.pos_y >= y && ev.pos_y <= y+h;

    if (isOver) {
        // Kattintás kezelése
        if (ev.type == ev_mouse && ev.button == btn_left) {
            int clickedIndex = ((ev.pos_y - y) / 20) + scrollOffset;
            if (clickedIndex >= 0 && clickedIndex < items.size()) {
                selectedItemIndex = clickedIndex;
            }
        }

        // Görgetés kezelése (ev_mouse típusú, de nem bal gomb!)
        if (ev.type == ev_mouse) {
            if (ev.button == btn_wheelup) {
                if (scrollOffset > 0) scrollOffset--;
            }
            else if (ev.button == btn_wheeldown) {
                // Csak akkor görgetünk le, ha van még mit
                int maxVisible = h / 20;
                if (scrollOffset + maxVisible < items.size()) {
                    scrollOffset++;
                }
            }
        }
    }
}

std::string listBox_widget::getValue() const
{
    if (selectedItemIndex >= 0 && selectedItemIndex < items.size())
        return items[selectedItemIndex];

    return "";
}