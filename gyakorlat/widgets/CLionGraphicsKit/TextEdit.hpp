//
// Created by hegkr3 on 2026. 03. 26..
//

#ifndef CLIONGRAPHICSKIT_TEXTEDIT_HPP
#define CLIONGRAPHICSKIT_TEXTEDIT_HPP
#include "widgets.hpp"


class TextEdit:public Widget {

protected:
    std::string _text;

public:
    TextEdit(int, int, int, int,std::string);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};


#endif //CLIONGRAPHICSKIT_TEXTEDIT_HPP