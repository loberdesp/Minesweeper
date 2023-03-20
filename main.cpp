#include "MinesweeperBoard.h"


int main() {
    minesweeperBoard plansza(5,5,HARD);
    plansza.revealField(2,2);
    plansza.debug_display();
}