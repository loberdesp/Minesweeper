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