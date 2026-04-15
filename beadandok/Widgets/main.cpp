#include "counter_widget.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include <fstream>

#include "listBox_widget.hpp"
using namespace genv;

void event_loop(std::vector<widget*>& widgets) {
    event ev;

    while (gin >> ev) {

        // 1. esemény feldolgozás
        for (widget* w : widgets) {
            w->handle(ev);
        }
        if (ev.type == ev_key && ev.keycode > 0)
        {
            if (ev.keycode == 's' || ev.keycode == 'S')
            {
                std::ofstream f("output.txt");

                for (widget* w : widgets) {
                    f << w->getValue() << std::endl;
                }
            }
        }
        // 2. kirajzolás
        gout << color(255,255,255) << move_to(0,0) << box(600,600); // háttér törlés

        for (widget* w : widgets) {
            w->draw();
        }

        gout << refresh;


    }
}



int main()
{
    std::vector<std::string>lwItems={"item1","item2","item3","item4","item5","item6","item7","item8","item9"};
    gout.open(600,600);
    std::vector<widget*> widgets;
    counter_widget *cw1 =new counter_widget(10,10,40,200,0,100);
    counter_widget *cw2 =new counter_widget(10,100,40,200,-50,50);

    listBox_widget* lw1= new listBox_widget(10,200,100,200,lwItems);

    widgets.push_back(cw1);
    widgets.push_back(cw2);
    widgets.push_back(lw1);


    event_loop(widgets);

    return 0;
}
