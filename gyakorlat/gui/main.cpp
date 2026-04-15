#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>

#include "StaticText.hpp"
using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}


int main()
{
    gout.open(400,400);
    vector<Widget*> w;
    ExampleCheckBox * b1 = new ExampleCheckBox(10,10,30,30);
    ExampleCheckBox * b2 = new ExampleCheckBox(10,50,40,40);
    StaticText *st = new StaticText(10,100,150,30, "");
    w.push_back(st);
    w.push_back(b1);
    w.push_back(b2);
    for (Widget * wg : w) {
        wg->draw();
    }

    gout << refresh;
    event_loop(w);
    return 0;
}