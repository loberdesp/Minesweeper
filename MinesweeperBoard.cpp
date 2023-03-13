#include "MinesweeperBoard.h"


minesweeperBoard::minesweeperBoard() {
    height=15;
    width=8;
    boardArray.resize(height, width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            boardArray[i][j].hasMine = false;
            boardArray[i][j].isRevealed = false;
            boardArray[i][j].hasFlag = false;
        }
    }
    boardArray[0][0].hasMine = true;
    boardArray[0][0].isRevealed = false;
    boardArray[0][0].hasFlag = false;
            
    boardArray[1][1].hasMine = false;
    boardArray[1][1].isRevealed = true;
    boardArray[1][1].hasFlag = false;

    boardArray[0][2].hasMine = true;
    boardArray[0][2].isRevealed = false;
    boardArray[0][2].hasFlag = true;
}


void minesweeperBoard::setDiff(double mineRate) {
    int boardSize = height*width;
    int numOfMines = std::ceil(boardSize/mineRate);
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<std::mt19937::result_type> distWidth(0,width-1);
            std::uniform_int_distribution<std::mt19937::result_type> distHeight(0,height-1);
            for(int i=0; i < numOfMines; i++) {

                int rngHeight = distHeight(mt);
                int rngWidth = distWidth(mt);

                if(boardArray[rngHeight][rngWidth].hasMine==false) {
                    boardArray[rngHeight][rngWidth].hasMine = true;
                } else {
                    while(boardArray[rngHeight][rngWidth].hasMine==true) {
                        rngHeight = distHeight(mt);
                        rngWidth = distWidth(mt);
                    }
                    boardArray[rngHeight][rngWidth].hasMine = true;
                }
            }
}


minesweeperBoard::minesweeperBoard(int height, int width, GameMode mode) {
    this->height=height;
    this->width=width;
    boardArray.resize(height, width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            boardArray[i][j].hasMine = false;
            boardArray[i][j].isRevealed = false;
            boardArray[i][j].hasFlag = false;
        }
    }
    double mineRate;
    switch(mode) {
        case DEBUG: 
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    if(i==0) {
                        boardArray[i][j].hasMine = true;
                    }
                    if(i==j) {
                        boardArray[i][j].hasMine = true;
                    }
                    if(i%2==0 && j==0) {
                        boardArray[i][j].hasMine = true;
                    }
                }
            }
        break;
        case EASY:
            mineRate = (double)10/1;
            setDiff(mineRate);
        break;
        case NORMAL:
            mineRate = (double)10/2;
            setDiff(mineRate);
        break;
        case HARD:
            mineRate = (double)10/3;
            setDiff(mineRate);
        break;
    }
}


void minesweeperBoard::debug_display() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j==0) {
                if(i==0) {
                    std::cout << "   ";
                    for(int k = 0; k < width; k++) {
                        if(k<10) {
                            std::cout << "  " << k+1 << "  ";
                        } else {
                            std::cout << " " << k+1 << "  ";
                        }
                    }
                std::cout << std::endl;
                }
                if(i<9) {
                    std::cout << i+1 << "  ";
                } else {
                    std::cout << i+1 << " ";
                }
            }
            std::cout << "[";
            if(boardArray[i][j].hasMine==true) {
                std::cout << "M";
            } else {
                std::cout << ".";
            }
            if(boardArray[i][j].isRevealed==true) {
                std::cout << "o";
            } else {
                std::cout << ".";
            }
            if(boardArray[i][j].hasFlag==true) {
                std::cout << "f";
            } else {
                std::cout << ".";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}
