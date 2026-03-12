//
// Created by heged on 3/12/2026.
//

#include "Grid.h"
#include "HelperFn.h"
#include <iostream>

#include "graphics.hpp"
#include "Colors.h"
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



void Grid::Draw()
{
    for (int row = 0; row < numRow; row++) {
        for (int col = 0; col < numColumn; col++) {
            int cellVal= grid[row][col];
            Color c=colors[cellVal];

            int x=col*cellSize+1;
            int y=row*cellSize+1;

            DrawRectangle(x, y, cellSize-1, cellSize-1, c);
        }
    }
}
