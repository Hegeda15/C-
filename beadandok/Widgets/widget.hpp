
#include "graphics.hpp"

#ifndef CLIONGRAPHICSKIT_WIDGET_HPP
#define CLIONGRAPHICSKIT_WIDGET_HPP


class widget {
protected:
    int x,y,w,h;
public:
    widget(int x,int y,int h,int w);
    virtual ~widget(){};
    virtual void draw()=0;
    virtual void handle(genv::event ev)=0;

    virtual std::string getValue() const =0;
};


#endif //CLIONGRAPHICSKIT_WIDGET_HPP