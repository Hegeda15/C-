//
// Created by heged on 3/12/2026.
//
#include "HelperFn.h"
#include "Block.h"
Block::Block() {

    cellSize = 30;
    rotationState = 0;
    colors=GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX,int offsetY) {

    std::vector<Position> tiles=GetCellPosition();
    for (Position item : tiles) {
        DrawRectangle(item.col*cellSize+offsetX,item.row*cellSize+offsetY,cellSize-1,cellSize-1,colors[id]);
    }
}

void Block::Move(int rows,int cols)
{
    rowOffset += rows;
    columnOffset += cols;

}

std::vector<Position>Block::GetCellPosition() {

    std::vector<Position> tiles=cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPosition(item.row+rowOffset,item.col+columnOffset);
        movedTiles.push_back(newPosition);
    }
    return movedTiles;
}

void Block::Rotate() {
    rotationState++;
    if (rotationState ==(int)cells.size()) rotationState = 0;
}

void Block::CancleRotation() {
    rotationState--;
    if (rotationState ==-1) rotationState = (int)cells.size()-1;
}

