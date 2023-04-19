#include "Array2D.h"
#include <random>
#include <SFML/Graphics.hpp>

#define TILE_SIZE 16
#define windowX 800
#define windowY 600

struct field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class minesweeperBoard {
    int width;
    int height;
    int numOfMines;
    GameMode mode;
    GameState state;
    Array2D<field> boardArray {height, width};

    public:
        minesweeperBoard(int width, int height, GameMode mode);
        void setDiff(double mineRate);
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
        void checkNear(int row, int col);
};

class MSBoardTextView {
    minesweeperBoard &msboard;

public:
    MSBoardTextView(minesweeperBoard &board);
    void display();
};

class MSTextController {
    minesweeperBoard &msboard;
    MSBoardTextView &msview;

public:
    MSTextController(minesweeperBoard &board, MSBoardTextView &view);
    void play();
};

class help {
    bool restart;

    public:
        help();
        int getRestartState();
        void toggleRestart();
};

class MSSFMLView {
    int mouseX, mouseY;
    sf::Texture txtVec[15];
    sf::Sprite sprite[5];
    double scaleX,scaleY, spriteX, spriteY;
    minesweeperBoard &msboard;
    help &msctrl;

    public:
        MSSFMLView(minesweeperBoard &board, help &msctrl);
        void draw(sf::RenderWindow &window);
        void handleClick(sf::RenderWindow &window, sf::Event event);
        void handleExit(sf::RenderWindow &window, sf::Event event);
};

