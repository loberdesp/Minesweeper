#include "MinesweeperBoard.h"


int main() {    
    help ctrl;
    do {
        ctrl.toggleRestart();
        sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
        window.setVerticalSyncEnabled(false);
        window.setFramerateLimit(30);
        minesweeperBoard board(5, 5, EASY);
        MSSFMLView view (board, ctrl);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                view.handleClick(event);
                view.handleExit(window, event);
            }
        window.clear();
        view.draw(window);
        window.display();
        } 
    }
    while(ctrl.getRestartState()==1);
}