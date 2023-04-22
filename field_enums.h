struct field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };