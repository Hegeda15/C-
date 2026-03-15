//
// Created by heged on 3/15/2026.
//

#include "GamePlan.h"

#include <bits/fs_fwd.h>

#include "BlockTypes.h"
#include "graphics.hpp"
using namespace genv;


GamePlan::GamePlan() {
    grid = Grid();
    blocks = GetAllBlock();
    currBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    gameOver = false;
    score = 0;
    clearedRowsCount = 0;
}

Block GamePlan::GetRandomBlock() {
    if (blocks.empty()) {
        blocks=GetAllBlock();
    }
    int randI=rand() % blocks.size();
    Block block = blocks[randI];
    blocks.erase(blocks.begin()+randI);
    return block;
}

std::vector<Block>GamePlan:: GetAllBlock() {
    return {IBlock(),JBlock(),LBlock(),OBlock(),TBlock(),SBlock(),ZBlock()};
}


void GamePlan::Draw() {
    grid.Draw();
    currBlock.Draw(11,11);
    nextBlock.Draw(270,270);
}

void GamePlan::HandleMovement (genv::event ev){
    if (ev.type == ev_key)
    {
        if (gameOver) {
            gameOver = false;
            Reset();
        }
        switch(ev.keycode)
        {
            case key_left:
                MoveL();
                break;

            case key_right:
                MoveR();
                break;

            case key_down:
                MoveD();
                UpdateScore(0,1);
                break;
            case key_up:
                RotateBlock();
                break;
        }
    }
}

void GamePlan::MoveL() {
    if (!gameOver) {
        currBlock.Move(0,-1);
        if (isBlockOutOfWindow() || isBlockOnEachother()==false) {
            currBlock.Move(0,1);
        }
    }

}
void GamePlan::MoveR() {
    if (!gameOver) {
        currBlock.Move(0,1);
        if (isBlockOutOfWindow() || isBlockOnEachother()==false) {
            currBlock.Move(0,-1);
        }
    }

}
void GamePlan::MoveD() {
    if (!gameOver) {
        currBlock.Move(1,0);
        if (isBlockOutOfWindow() || isBlockOnEachother()==false) {
            currBlock.Move(-1,0);
            LockBlock();
        }
    }

}
bool GamePlan::isBlockOutOfWindow() {
    std::vector<Position> poss=currBlock.GetCellPosition();
    for (Position item : poss) {
        if (grid.isOutOfWindow(item.row,item.col)) {
            return true;
        }
    }
    return false;
}

void GamePlan::RotateBlock() {
    if (!gameOver) {
        currBlock.Rotate();
        if (isBlockOutOfWindow() || isBlockOnEachother()==false) {
            currBlock.CancleRotation();
        }
    }

}

void GamePlan::LockBlock() {
    std::vector<Position> poss = currBlock.GetCellPosition();
    for (Position item : poss) {
        grid.grid[item.row][item.col] = currBlock.id;
    }
    currBlock=nextBlock;
    if (isBlockOnEachother()==false) {
        gameOver=true;
    }
    nextBlock=GetRandomBlock();
   int rowsCleard= grid.ClearFullRow();
    UpdateScore(rowsCleard,0);
}

bool GamePlan::isBlockOnEachother() {
    std::vector<Position> poss = currBlock.GetCellPosition();
    for (Position item : poss) {
        if (grid.isCellEmpty(item.row,item.col)==false) {
            return false;
        }
    }
    return true;
}

void GamePlan::Reset() {
    grid.Init();
    blocks=GetAllBlock();
    currBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    score=0;
    clearedRowsCount=0;
}

void GamePlan::UpdateScore(int rowsCleared, int mowedDownScore) {
    clearedRowsCount += rowsCleared;
    switch (rowsCleared) {
        case 1:
            score+=100;
            break;
        case 2:
            score+=300;
            break;
        case 3:
            score+=500;
            break;
        case 4:
            score += 800;
            break;
        default:
            break;

    }
    score+=mowedDownScore;
}

int GamePlan::GetFallSpeed() {
    int level=clearedRowsCount/10;
    int delay=500-(level*40);
    if (delay<100) {
        return 100;
    }
    return delay;
}
