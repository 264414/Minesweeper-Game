#include "Minesweeper.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Minesweeper::Minesweeper(int _width, int _height, int _level) {
    Fields = _width * _height;

    //0 - rozpoczecie gry, 1 - wygrana, 2 - przegrana
    StateOfGame = 0;
    level = _level;
    height = _height;
    width = _width;
    Minesweeper::checkValues();

    Bombs = width*height*level/10;

}

Minesweeper::Minesweeper(){}

int Minesweeper::getLevel() {
    return level;
}

void Minesweeper::DebugMode() {
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            std::cout << "[";
            if(GameField[i][j].hasMine == true)std::cout << "M";
            else std::cout << ".";
            if(GameField[i][j].isReveled == true) std::cout << "O";
            else std::cout << ".";
            if(GameField[i][j].hasFlag == true) std::cout << "F";
            else std::cout << ".";
            std::cout << "]";
        }
        std::cout << std::endl;
    }

}

void Minesweeper::setValues(int _width, int _height, int _level) {
    width = _width;
    height = _height;
    level = _level;
}

Field Minesweeper::GetGameField(int _x, int _y) {
    return GameField[_x][_y];
}

int Minesweeper::getWidth() {
    return width;
}

int Minesweeper::getHeight() {
    return height;
}

void Minesweeper::countMines() {

    for (int _x = 0; _x < width; ++_x) {
        for (int _y = 0; _y < height; ++_y) {

            if(GameField[_x-1][_y-1].hasMine == true && (_x-1 >= 0 && _x-1<width && _y-1>=0 && _y-1<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x-1][_y].hasMine == true && (_x-1 >= 0 && _x-1<width && _y>=0 && _y<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x-1][_y+1].hasMine == true && (_x-1 >= 0 && _x-1<width && _y+1>=0 && _y+1<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x][_y+1].hasMine == true && (_x >= 0 && _x<width && _y+1>=0 && _y+1<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x+1][_y+1].hasMine == true && (_x+1 >= 0 && _x+1<width && _y+1>=0 && _y+1<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x+1][_y].hasMine == true && (_x+1 >= 0 && _x+1<width && _y>=0 && _y<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x+1][_y-1].hasMine == true && (_x+1 >= 0 && _x+1<width && _y-1>=0 && _y-1<height)) GameField[_x][_y].bombsArround++;
            if(GameField[_x][_y-1].hasMine == true && (_x >= 0 && _x<width && _y-1>=0 && _y-1<height)) GameField[_x][_y].bombsArround++;

            if(GameField[_x][_y].hasMine == true) GameField[_x][_y].bombsArround = -1;

        }
    }

}

int Minesweeper::getBombs() {
    return Bombs;
}

int Minesweeper::getReveledField() {
    int ReavledField = 0;
    for(int i = 0 ; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            if(GameField[i][j].isReveled == true && GameField[i][j].hasMine == false) ReavledField++;
        }
    }
    return ReavledField;
}

int Minesweeper::getStateOfGame() {
    return StateOfGame;
}

void Minesweeper::checkValues() {
    if(width > MAX_WIDTH) width = MAX_WIDTH;
    if(width < MIN_WIDTH) width = MIN_WIDTH;
    if(height > MAX_HEIGHT) height = MAX_HEIGHT;
    if(height < MIN_HEIGHT) height = MIN_HEIGHT;
    if(level > MAX_LEVEL) level = MAX_LEVEL;
    if(level > MIN_LEVEL) level = MIN_LEVEL;
}

void Minesweeper::SetArrayClear() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            GameField[i][j].hasMine = false;
            GameField[i][j].isReveled = false;
            GameField[i][j].hasFlag = false;
        }
    }
}

void Minesweeper::setFlag(int _x, int _y) {
    if(GameField[_x][_y].isReveled == true) return;
    else
    {
        if(GameField[_x][_y].hasFlag == false) GameField[_x][_y].hasFlag = true;
        else GameField[_x][_y].hasFlag = false;
    }
}

void Minesweeper::setBombs() {
    Bombs = width*height*level/10;
}

void Minesweeper::setLevel(int level) {
    this->level = level;
}

void Minesweeper::setHeight(int height) {
    this->height = height;
}

void Minesweeper::setWidth(int width) {
    this->width = width;
}

void Minesweeper::RevelFields(int row, int col) {

    if(row>width || col > height || row<0 || col <0 ) return;

    if(GameField[row][col].isReveled == true || GameField[row][col].hasFlag == true) return;

    GameField[row][col].isReveled = true;

    if(GameField[row][col].bombsArround != 0) return;

    //Sprawdzanie czy wok� pola znajduj� si� pola puste
    if(GameField[row-1][col].isReveled == false && GameField[row-1][col].bombsArround == 0 && GameField[row-1][col].hasMine == false) RevelFields(row-1, col);
    //if(GameField[row-1][col-1].isReveled == false && GameField[row-1][col-1].bombsArround == 0 && GameField[row-1][col-1].hasMine == false) RevelFields(row-1, col-1);
    //if(GameField[row-1][col+1].isReveled == false && GameField[row-1][col+1].bombsArround == 0 && GameField[row-1][col+1].hasMine == false) RevelFields(row-1, col+1);
    if(GameField[row][col+1].isReveled == false && GameField[row][col+1].bombsArround == 0 && GameField[row][col+1].hasMine== false) RevelFields(row, col+1);
    if(GameField[row][col-1].isReveled == false && GameField[row][col-1].bombsArround == 0 && GameField[row][col-1].hasMine == false) RevelFields(row, col-1);
    if(GameField[row+1][col].isReveled == false && GameField[row+1][col].bombsArround == 0&& GameField[row+1][col].hasMine == false) RevelFields(row+1, col);
    //if(GameField[row+1][col-1].isReveled == false && GameField[row+1][col-1].bombsArround == 0 && GameField[row+1][col-1].hasMine == false) RevelFields(row+1, col-1);
    //if(GameField[row+1][col+1].isReveled == false && GameField[row+1][col+1].bombsArround == 0 && GameField[row+1][col+1].hasMine == false) RevelFields(row+1, col+1);


    if(GameField[row][col].isReveled == true && GameField[row][col].bombsArround == 0)
    {
        if(GameField[row-1][col].hasMine == false)RevelFields(row-1, col);
        if(GameField[row+1][col+1].hasMine == false)RevelFields(row+1, col+1);
        if(GameField[row+1][col-1].hasMine == false)RevelFields(row+1, col-1);
        if(GameField[row+1][col].hasMine == false)RevelFields(row+1, col);
        if(GameField[row][col-1].hasMine == false) RevelFields(row, col-1);
        if(GameField[row][col+1].hasMine == false)RevelFields(row, col+1);
        if(GameField[row-1][col+1].hasMine == false)RevelFields(row-1, col+1);
        if(GameField[row-1][col-1].hasMine == false) RevelFields(row-1, col-1);
    }

}

void Minesweeper::GenereteMines() {
    int _bombs = Bombs;
    if(level!=4)
    {
        srand(time(NULL));
        while(_bombs > 0)
        {
            int i = rand()%width;
            int j = rand()%height;

            if(GameField[i][j].hasMine==false && _bombs>0)
            {
                _bombs--;
                GameField[i][j].hasMine = true;
            }
        }
    }
    else
    {
        for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                if(i == 0) GameField[i][j].hasMine = true;
                if(i == j) GameField[i][j].hasMine = true;
                if(j == 0) GameField[i][j].hasMine = true;
            }
        }
    }
}
