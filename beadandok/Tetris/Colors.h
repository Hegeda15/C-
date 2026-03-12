//
// Created by heged on 3/12/2026.
//
#include <vector>
#pragma once
#ifndef CLIONGRAPHICSKIT_COLORS_H
#define CLIONGRAPHICSKIT_COLORS_H

struct Color {
    int r;
    int g;
    int b;
    int a;
};

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;

std::vector<Color> GetCellColors();

#endif //CLIONGRAPHICSKIT_COLORS_H