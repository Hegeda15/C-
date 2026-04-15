//
// Created by heged on 4/14/2026.
//

#ifndef CLIONGRAPHICSKIT_LISTBOX_WIDGET_HPP
#define CLIONGRAPHICSKIT_LISTBOX_WIDGET_HPP
#include "widget.hpp"


class listBox_widget:public widget{
protected:
    std::vector<std::string> items;
    int selectedItemIndex;
public:
    listBox_widget(int x,int y,int w,int h,const std::vector<std::string>& items);

    virtual void draw() override;
    virtual void handle(genv::event ev) override;

    virtual std::string getValue() const override;
};


#endif //CLIONGRAPHICSKIT_LISTBOX_WIDGET_HPP