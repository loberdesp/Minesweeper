#include "MinesweeperBoard.h"


int main() {    
    help ctrl;
    do {
        ctrl.toggleRestart();
        sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Minesweeper");
        window.setVerticalSyncEnabled(false);
        window.setFramerateLimit(30);
        minesweeperBoard board(12, 9, EASY);
        MSSFMLView view (board, ctrl);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                view.handleClick(window, event);
                view.handleExit(window, event);
            }
        window.clear();
        view.draw(window);
        window.display();
        } 
    }
    while(ctrl.getRestartState()==1);
}