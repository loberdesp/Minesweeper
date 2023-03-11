#include "Array2D.h"

struct field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class minesweeperBoard {
    Array2D<field> boardArray {width, height};
    int width;
    int height;

    public:
        minesweeperBoard() {
            height=21;
            width=40;
            boardArray.resize(width, height);
            for(int i = 0; i < width; i++) {
                for(int j = 0; j < height; j++) {
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
        void debug_display();
};


        void minesweeperBoard::debug_display() {
            for(int i = 0; i < width; i++) {
                for(int j = 0; j < height; j++) {
                    if(j==0) {
                        if(i==0) {
                            std::cout << "   ";
                            for(int k = 0; k < height; k++) {
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


int main() {
    minesweeperBoard plansza;
    plansza.debug_display();
    return 0;
}