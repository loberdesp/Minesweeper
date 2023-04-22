MSBoardTextView::MSBoardTextView(minesweeperBoard &board) : msboard(board){
}

void MSBoardTextView::display() {
    int height = msboard.getBoardHeight();
    int width = msboard.getBoardWidth();
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j==0) {
                if(i==0) {
                    std::cout << "   ";
                    for(int k = 0; k < width; k++) {
                        if(k<10) {
                            std::cout << " " << k << " ";
                        } else {
                            std::cout << " " << k;
                        }
                    }
                std::cout << std::endl;
                }
                if(i<=9) {
                    std::cout << i << "  ";
                } else {
                    std::cout << i << " ";
                }
            }
            std::cout << "[" << msboard.getFieldInfo(i,j) << "]";
        }
        std::cout << std::endl;
    }
}

MSTextController::MSTextController(minesweeperBoard &board, MSBoardTextView &view) : msboard(board), msview(view) {
}

void MSTextController::play() {
    int state = msboard.getGameState();
    int row, col;
    char op;
    msview.display();
    while(state==RUNNING) {
        std::cout << "daj pole i operacje jaka chcesz zrobic" << std::endl;
        std::cin >> row;
        std::cin >> col;
        std::cin >> op;
        switch(op) {
            case 'r':
                msboard.revealField(row,col);
            break;
            case 'f':
                msboard.toggleFlag(row,col);
            break;
        }
        msview.display();
        state = msboard.getGameState();
    }
}