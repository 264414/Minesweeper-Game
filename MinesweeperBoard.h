#include "Minesweeper.h"
#include "MSTextBoardView.h"

#ifndef UNTITLED_MINESWEEPERBOARD_H
#define UNTITLED_MINESWEEPERBOARD_H
class MinesweeperBoard {
private:
public:
    MinesweeperBoard();
    void Revel(Minesweeper m1, int _x, int _y);
    void SetFlag(Minesweeper m1, int _x, int _y);
    int CheckStateOfGame(Minesweeper m1);
    void ShowCurrenBoard(MSTextBoardView a1, Minesweeper m1);

};


#endif //UNTITLED_MINESWEEPERBOARD_H
