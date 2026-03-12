//
// Created by heged on 3/12/2026.
//

#include "Grid.h"

#include <iostream>

#include "graphics.hpp"
using namespace genv;
Grid::Grid() {
    numRow = 20;
    numColumn = 10;
    cellSize=30;
    Init();
    colors = GetCellColors();
}

void Grid::Init() {

    for (int row = 0; row < numRow; row++) {
        for (int col = 0; col < numColumn; col++) {
            grid[row][col] = 0;
        }
    }
}
void Grid::Print() {
    for (int row = 0; row < numRow; row++) {
        for (int col = 0; col < numColumn; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<Color> Grid::GetCellColors() {
    Color darkGrey={26,31,40,255};
    Color green={47,230,23,255};
    Color red={232,18,18,255};
    Color orange={226,116,17,255};
    Color yellow={237,234,4,255};
    Color purple={166,0,247,255};
    Color cyan={21,204,209,255};
    Color blue={13,64,216,255};

    return {darkGrey,green,red,orange,yellow,purple,cyan,blue};
}

void Grid::Draw()
{
    for (int row = 0; row < numRow; row++) {
        for (int col = 0; col < numColumn; col++) {
            int cellVal= grid[row][col];
            Color c=colors[cellVal];

            int x=col*cellSize;
            int y=row*cellSize;

            gout<< move_to(x,y)<<color(c.r,c.g,c.b)
            <<box(cellSize,cellSize);
        }
    }
}
