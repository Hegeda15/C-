//
// Created by heged on 3/12/2026.
//
#include<vector>
#include<map>
#include "Position.h"
#include "Colors.h"
#pragma once
#ifndef CLIONGRAPHICSKIT_BLOCK_H
#define CLIONGRAPHICSKIT_BLOCK_H


class Block {
public:
    Block();
    void Draw();
    void Move(int rows,int cols);

    std::vector<Position> GetCellPosition();

    int id;
    std::map<int,std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};


#endif //CLIONGRAPHICSKIT_BLOCK_H