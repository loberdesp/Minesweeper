#include "MinesweeperBoard.h"


int main() {
    minesweeperBoard plansza(10,10,HARD);
    MSBoardTextView view(plansza);
    MSTextController ctrl(plansza,view);
    plansza.getFieldInfo(1,1);
    ctrl.play();
}