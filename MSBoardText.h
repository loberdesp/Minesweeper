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