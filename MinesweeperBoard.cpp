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
    numOfMines = std::ceil(boardSize/mineRate);
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
    this->height = height;
    this->width = width;
    this->mode = mode;
    this->state = RUNNING;
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


void minesweeperBoard::debug_display() const {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j==0) {
                if(i==0) {
                    std::cout << "   ";
                    for(int k = 0; k < width; k++) {
                        if(k<10) {
                            std::cout << "  " << k << "  ";
                        } else {
                            std::cout << " " << k << "  ";
                        }
                    }
                std::cout << std::endl;
                }
                if(i<9) {
                    std::cout << i << "  ";
                } else {
                    std::cout << i << " ";
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

int minesweeperBoard::getBoardWidth() const {
    return width;
}

int minesweeperBoard::getBoardHeight() const {
    return height;
}

int minesweeperBoard::getMineCount() const {
    int counter;
    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++) {
            if(boardArray[i][j].hasMine==1) {
                counter++;
            }
        }
    }
    return counter;
}

int minesweeperBoard::checkMine(int row, int col) const {
    if(boardArray[row][col].hasMine==1) {
        return 1;
    } else {
        return 0;
    }
}

int minesweeperBoard::countMines(int row, int col) const {
    int counter;
    if(boardArray[row][col].isRevealed==1 && row>=0 && row<height && col>=0 && col<width) {
        if(row==0) {
            if(col==0 || col==width-1) {
                if(col==0) {
                    counter += checkMine(row+1, col);
                    counter += checkMine(row+1, col+1);
                    counter += checkMine(row, col+1);
                } else {
                    counter += checkMine(row+1, col);
                    counter += checkMine(row+1, col-1);
                    counter += checkMine(row, col-1);
                }

            } else {
                counter += checkMine(row, col-1);
                counter += checkMine(row+1, col-1);
                counter += checkMine(row+1, col);
                counter += checkMine(row+1, col+1);
                counter += checkMine(row, col+1);
            }
        }
        if(row==height-1) {
            if(col==0 || col==width-1) {
                if(col==0) {
                    counter += checkMine(row-1, col);
                    counter += checkMine(row-1, col+1);
                    counter += checkMine(row, col+1);
                } else {
                    counter += checkMine(row-1, col);
                    counter += checkMine(row-1, col-1);
                    counter += checkMine(row, col-1);
                }

            } else {
                counter += checkMine(row, col-1);
                counter += checkMine(row-1, col-1);
                counter += checkMine(row-1, col);
                counter += checkMine(row-1, col+1);
                counter += checkMine(row, col+1);
            }
        }
        if(row!=0 && row!=height-1) {
            if(col==0) {
                counter += checkMine(row-1, col);
                counter += checkMine(row-1, col+1);
                counter += checkMine(row, col+1);
                counter += checkMine(row+1, col+1);
                counter += checkMine(row+1, col);
            }
            if(col==width-1) {
                counter += checkMine(row-1, col);
                counter += checkMine(row-1, col-1);
                counter += checkMine(row, col-1);
                counter += checkMine(row+1, col-1);
                counter += checkMine(row+1, col);
            }
        }
        if(row!=0 && row!=height-1 && col!=0 && col!=width-1) {
                counter += checkMine(row-1, col);
                counter += checkMine(row-1, col+1);
                counter += checkMine(row, col+1);
                counter += checkMine(row+1, col+1);
                counter += checkMine(row+1, col);
                counter += checkMine(row+1, col-1);
                counter += checkMine(row, col-1);
                counter += checkMine(row-1, col-1);
        }
        return counter;
    } else {
        return -1;
    }
}

bool minesweeperBoard::hasFlag(int row, int col) const {
    if(row < 0 || row >= height || col < 0 || col >= width || boardArray[row][col].isRevealed==1 || boardArray[row][col].hasFlag==0) {
        return false;
    } else {
        return true;
    }
}


void minesweeperBoard::toggleFlag(int row, int col) {
    if(row > 0 && row <= height && col > 0 && col<= width && boardArray[row][col].isRevealed==0 && state==RUNNING) {
        if(boardArray[row][col].hasFlag==0) {
            boardArray[row][col].hasFlag=1;
        } else {
            boardArray[row][col].hasFlag=0;
        }
    }

}

void minesweeperBoard::revealField(int row, int col) {
    if(row > 0 && row <= height && col > 0 && col<= width && boardArray[row][col].isRevealed==0 && boardArray[row][col].hasFlag==0) {
        if(boardArray[row][col].hasMine==0) {
            boardArray[row][col].isRevealed=1;
        } else {
            int count=0;
            for(int i=0;i < height; i++) {
                for(int j=0; j < width; j++) {
                    if(boardArray[i][j].isRevealed==0) {
                        count++;
                    }
                }
            }
            if(count==(width*height)) {
                boardArray[row][col].hasMine=0;
                std::random_device rd;
                std::mt19937 mt(rd());
                std::uniform_int_distribution<std::mt19937::result_type> distWidth(0,width-1);
                std::uniform_int_distribution<std::mt19937::result_type> distHeight(0,height-1);
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
            } else {
                state=FINISHED_LOSS;
            }
            boardArray[row][col].isRevealed=1;
        }
    }
}

bool minesweeperBoard::isRevealed(int row, int col) const {
    if(boardArray[row][col].isRevealed==1) {
        return true;
    } else {
        return false;
    }
}

GameState minesweeperBoard::getGameState() const {
    int count;
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            if(boardArray[i][j].isRevealed==0) {
                if(boardArray[i][j].hasMine==1) {
                    count++;
                } else {
                    return state;
                }
            }
        }
    }
    if(count==numOfMines) {
        return FINISHED_WIN;
    }
    return state;
}

char minesweeperBoard::getFieldInfo(int row, int col) const {
    if(row < 0 || row >= height || col < 0 || col >= width) {
        return '#';
    }
    if(boardArray[row][col].isRevealed==0) {
        if(boardArray[row][col].hasFlag==1) {
            return 'F';
        } else {
            return '_';
        }
    } else {
        if(boardArray[row][col].hasMine==1) {
            return 'x';
        }
        if(countMines(row,col)==(-1)) {
            return ' ';
        } else {
           return countMines(row,col); 
        }
    }
}