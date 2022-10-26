#include <iostream>
#include "MSTextBoardView.h"

MSTextBoardView::MSTextBoardView(Minesweeper m1){}

MSTextBoardView::MSTextBoardView() {}

void MSTextBoardView::GameDisplay(Minesweeper m1) {
    for (int i = 0; i < m1.getHeight() ; ++i) {
        for (int j = 0; j < m1.getWidth(); ++j) {
            std::cout << "[";
            if(m1.GetGameField(i, j).isReveled == true)
            {
                if(m1.GetGameField(i,j).hasMine == true) std::cout << "M";
                else std::cout << m1.GetGameField(i, j).bombsArround;
            }
            else
            {
                if(m1.GetGameField(i,j).hasFlag == true) std::cout << "F";
                else std::cout << "_";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

void MSTextBoardView::GameDisplayVideo(Minesweeper m1) {

}
