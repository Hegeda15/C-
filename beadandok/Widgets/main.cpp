#include "counter_widget.hpp"
#include "graphics.hpp"
#include "Application.hpp"
#include "widget.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "listBox_widget.hpp"
using namespace genv;


class MyApp : public Application {
public:
    MyApp() {
        std::vector<std::string>lwItems={"item1","item2","item3","item4","item5","item6","item7","item8","item9"};
        std::vector<std::string> lwItems2 = {"Audi", "BMW", "Honda", "Toyota", "Mercedes", "Opel"};
        new counter_widget(this, 10, 10, 40, 200, 0, 100);
        new counter_widget(this, 10, 100, 40, 200, -50, 10);
        new listBox_widget(this, 10, 200, 100, 200, lwItems);
        new listBox_widget(this, 300, 200, 100, 200, lwItems2);
    }
    virtual void action(std::string id) override {
        if (id == "save") {
            std::ofstream f("kimenet.txt");
            if (!f) {
                std::cerr << "HIBA: A fajlt nem sikerult letrehozni!" << std::endl;
                return;
            }

            std::cout << "Mentes folyamatban..." << std::endl;
            for (widget* w : _widgets) {
                f << w->getValue() << std::endl;
            }
            f.close();
            std::cout << "Mentes kesz!" << std::endl;
        }

    }
};



int main()
{
    gout.open(600, 600);
    MyApp app;
    app.event_loop();





    return 0;
}
