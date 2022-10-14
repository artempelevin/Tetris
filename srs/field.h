#ifndef FIELD_H
#define FIELD_H

#ifdef WINDOWS
#include <SDL_stdinc.h>
#endif // WINDOWS
#ifdef LINUX

#include <SDL2/SDL_stdinc.h>

#endif // LINUX

#include "pieces.h"

//Поле
class Field {
private:
    short col;          //Кол-во столбцов игрового поля
    short str;          //Кол-во строк игрового поля
    char **cells;       //Матрица игрового поля (Хранит цвета!)
public:
    Field();

    short getCol();

    short getStr();

    char **getCells();

    void setCell(int x, int y, int val);    //Устанавливает определённую ячейку в массиве cells
    void setFigure(Pieces *pieces);         //Устанавливает фигиру на игровое поле
    bool checkColision(Pieces *pieces);     //Проверка столкновений с другими фигурами
    bool checkScreenOff(Pieces *pieces);    //Проверка выхода за пределы игрового поля
    short cleanRows();                      //Очищает заполенные ряды
};

#endif
