#pragma once
#include"Block.h"
#include"Grid.h"
#include "graphics.hpp"

#ifndef CLIONGRAPHICSKIT_GAMEPLAN_H
#define CLIONGRAPHICSKIT_GAMEPLAN_H




class GamePlan {
public:
    GamePlan();

    Block GetRandomBlock();
    void Draw();
    void HandleMovement(genv::event ev);
    void MoveL();
    void MoveR();
    void MoveD();
    int GetFallSpeed();
    std::vector<Block> GetAllBlock();
    bool gameOver;
    Grid grid;
    int score;
    int clearedRowsCount;
private:
    bool isBlockOutOfWindow();
    void RotateBlock();
    void LockBlock();
    bool isBlockOnEachother();
    void Reset();
    void UpdateScore(int rowsCleared,int mowedDownScore);

    std::vector<Block> blocks;
    Block currBlock;
    Block nextBlock;

};


#endif //CLIONGRAPHICSKIT_GAMEPLAN_H