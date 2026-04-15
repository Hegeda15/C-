//
// Created by karar1 on 2026. 03. 25..
//

#ifndef CLIONGRAPHICSKIT_STATICTEXT_HPP
#define CLIONGRAPHICSKIT_STATICTEXT_HPP
#include "widgets.hpp"
#include <string>

class StaticText: public Widget {
protected:

    std::string _content;
    int _cursor_pos;
public:
    StaticText(int x, int y, int sx, int sy, std::string text);

    virtual void draw() override;

    virtual void handle(genv::event ev) override;
};


#endif //CLIONGRAPHICSKIT_STATICTEXT_HPP