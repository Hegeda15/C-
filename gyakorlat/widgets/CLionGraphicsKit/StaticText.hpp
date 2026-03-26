//
// Created by hegkr3 on 2026. 03. 26..
//

#ifndef CLIONGRAPHICSKIT_STATICTEXT_HPP
#define CLIONGRAPHICSKIT_STATICTEXT_HPP
#include "widgets.hpp"


class StaticText:public Widget {

protected:
    std::string _text;
public:
    StaticText(int, int, int, int,std::string);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};


#endif //CLIONGRAPHICSKIT_STATICTEXT_HPP