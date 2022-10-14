#ifndef PIECES_H
#define PIECES_H

#include <iostream>

//Фигуры 'I=', 'I_', '_I'
class Pieces {
protected:
    short x, y;      //Координаты фигуры    
    short type;      //Её тип [0;6] т.к. фигур 7 штук!
    char **figure;   //Двум. массив, представляющий фигуру
    int color;       //Цвет фигуры
    int colorBord;   //Цвет рамки
    int colorFlare;  //Цвет блика

    void setColor(int type);            //Устанавливает цвет фигуры
    void setColorBord(int type);        //Устанавливает цвет рамки
    void setColorFlare(int type);       //Устанавливает цвет блика
    void transposing(std::string turnType);  //Транспонирование матрицы фигуры(Принимает "лево" или "право")
    void offsetX(std::string offType);       //Смещение матрицы фигуры на 1 вправо или лево   
public:
    Pieces();                   //Создаёт фигуру без 'type' и  цветов. Нужен лишь для проверки столкновений
    Pieces(short type);         //Создаём полностью настраиваемую фигуру     
    Pieces &operator=(Pieces &figure);

    ~Pieces();

    short getType();

    short getX();

    short getY();

    int getColor();

    int getColorBord();

    int getColorFlare();

    char **getFigure();

    void setType(short type);

    void setX(short x);

    void setY(short y);

    void setFigure(char **figure);

    virtual void turn();        //Поворот для фигур 'I=', 'I_', '_I'
    void moveLeft();            //Движение влево
    void moveRight();           //Движение вправо
    void moveDown();            //Движение вниз

};

//Фигура 'куб'
class Cube : public Pieces {
public:
    Cube(short type) : Pieces(type) {}

    virtual void turn();            //Отсутствует вращение
};

//Фигура 'линия'
class Line : public Pieces {
public:
    Line(short type) : Pieces(type) {}

    virtual void turn();            //Своя реализация 2х вращений
};

//Фигура 'змейка'
class Snake : public Pieces {
private:
    bool isVertical();              //Возвращает 'true', если фигура в вертикальном положении
public:
    Snake(short type) : Pieces(type) {}

    virtual void turn();            //Своя реализация 2х вращений
};

//Функция возращающая случайно одну из 7ми фигур
Pieces *addFigure();

//Функция возращающая указатель на копию созданной фигуры
Pieces *getFigure(Pieces *figure);

#endif