//
// Created by heged on 3/12/2026.
//
#include <cstdlib>
#ifndef CLIONGRAPHICSKIT_GRID_H
#define CLIONGRAPHICSKIT_GRID_H
#include<vector>

struct Color {
    int r;
    int g;
    int b;
    int a;
};

class Grid {
public:
    Grid();
    void Init();
    void Print();
    void Draw();
    int grid[20][10];
private:
    std::vector<Color>GetCellColors();
    int numRow;
    int numColumn;
    int cellSize;
    std::vector<Color>colors;

};


#endif //CLIONGRAPHICSKIT_GRID_H