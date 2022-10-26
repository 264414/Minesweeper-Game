#include "Minesweeper.h"
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard() {

}

void MinesweeperBoard::Revel(Minesweeper m1, int _x, int _y) {
    m1.RevelFields(_x, _y);
}

int MinesweeperBoard::CheckStateOfGame(Minesweeper m1) {
    return m1.getStateOfGame();
}

void MinesweeperBoard::ShowCurrenBoard(MSTextBoardView a1, Minesweeper m1) {
    a1.GameDisplay(m1);
}

void MinesweeperBoard::SetFlag(Minesweeper m1, int _x, int _y) {
    m1.setFlag(_x, _y);
}
