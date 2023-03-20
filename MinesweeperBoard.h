#include "Array2D.h"
#include <random>

struct field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class minesweeperBoard {
    Array2D<field> boardArray {width, height};
    int width;
    int height;
    int numOfMines;
    GameMode mode;
    GameState state;

    public:
        minesweeperBoard();
        void setDiff(double mineRate);
        minesweeperBoard(int width, int height, GameMode mode);
        void debug_display() const;
        int getBoardWidth() const;
        int getBoardHeight() const;
        int getMineCount() const;
        int countMines(int row, int col) const;
        int checkMine(int row, int col) const;
        bool hasFlag(int row, int col) const;
        void toggleFlag(int row, int col);
        void revealField(int row, int col);
        bool isRevealed(int row, int col) const;
        GameState getGameState() const;
        char getFieldInfo(int row, int col) const;
};