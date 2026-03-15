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

            int x=col*cellSize+11;
            int y=row*cellSize+11;

            DrawRectangle(x, y, cellSize-1, cellSize-1, c);
        }
    }
}

bool Grid::isOutOfWindow(int row, int col) {
    return !(row >= 0 && row < numRow && col >= 0 && col < numColumn);
}

bool Grid::isCellEmpty(int row, int col) {

    if (grid[row][col] == 0) {
        return true;
    }
    return false;
}
int Grid::ClearFullRow() {
    int completedRows = 0;
    for (int row = numRow - 1; row >= 0; row--) {
        if (isRowFull(row)) {
            ClearRow(row);
            completedRows++;
        }
        else if (completedRows>0) {
            MoveRowDown(row,completedRows);
        }
    }
    return completedRows;
}

bool Grid::isRowFull(int row) {
    for (int column = 0; column < numColumn; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for (int column = 0; column < numColumn; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows) {
    for (int i = 0; i < numColumn; ++i) {
        grid[row+numRows][i] = grid[row][i];
        grid[row][i] = 0;
    }
}


