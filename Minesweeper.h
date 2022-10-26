#ifndef UNTITLED_MINESWEEPER_H
#define UNTITLED_MINESWEEPER_H
#include "Variables.h"

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isReveled;
    int bombsArround = 0;
};


class Minesweeper {
private:
    //0 - rozpoczecie gry, 1 - wygrana, 2 - przegrana
    int StateOfGame;
    int Fields;
    int ReavledField;
    int Bombs;
    Field GameField[MAX_WIDTH][MAX_HEIGHT];

    int level, width, height;

public:
    //Konstruktory
    Minesweeper(int _width, int _height, int _level);
    Minesweeper();

    //Funkcje
    void RevelFields(int _x, int _y);
    void SetArrayClear();
    void checkValues();
    void countMines();
    void setValues(int _width, int _height, int _level);
    void GenereteMines();
    void setFlag(int _x, int _y);
    void DebugMode();
    Field GetGameField(int _x, int _y);

    //Zwracanie wartosci
    int getReveledField();
    int getBombs();
    int getStateOfGame();
    int getWidth();
    int getHeight();
    int getLevel();

    //Zmienianie wartosci
    void setWidth(int width);
    void setHeight(int height);
    void setLevel(int level);
    void setBombs();
};


#endif //UNTITLED_MINESWEEPER_H
