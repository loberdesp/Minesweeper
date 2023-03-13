#include "Array2D.h"
#include <random>

struct field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode  { DEBUG, EASY, NORMAL, HARD };

class minesweeperBoard {
    Array2D<field> boardArray {width, height};
    int width;
    int height;

    public:
        minesweeperBoard();
        void setDiff(double mineRate);
        minesweeperBoard(int width, int height, GameMode mode);
        void debug_display();
};