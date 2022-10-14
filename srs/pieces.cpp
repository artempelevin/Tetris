#include <iostream>

#include "pieces.h"
#include "figures.h"
#include "setting.h"

short Pieces::getType() { return type; }

short Pieces::getX() { return x; }

short Pieces::getY() { return y; }

int Pieces::getColor() { return color; }

int Pieces::getColorBord() { return colorBord; }

int Pieces::getColorFlare() { return colorFlare; }

char **Pieces::getFigure() { return figure; }

void Pieces::setType(short type) { this->type = type; }

void Pieces::setX(short x) { this->x = x; }

void Pieces::setY(short y) { this->y = y; }

void Pieces::setFigure(char **figure) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->figure[i][j] = figure[i][j];
        }
    }
}


/*--- Устанавливает цвет фигуры  ---*/
void Pieces::setColor(int type) {
    int colors[7] = {COLOR_1, COLOR_2, COLOR_3, COLOR_4, COLOR_5, COLOR_6, COLOR_7};
    color = colors[type];
}

/*--- Устанавливает цвет рамки  ---*/
void Pieces::setColorBord(int type) {
    int bordColors[7] = {COLOR_BORD_1, COLOR_BORD_2, COLOR_BORD_3, COLOR_BORD_4, COLOR_BORD_5, COLOR_BORD_6,
                         COLOR_BORD_7};
    colorBord = bordColors[type];
}

/*--- Устанавливает цвет блика  ---*/
void Pieces::setColorFlare(int type) {
    int flareColors[7] = {COLOR_FLARE_1, COLOR_FLARE_2, COLOR_FLARE_3, COLOR_FLARE_4, COLOR_FLARE_5, COLOR_FLARE_6,
                          COLOR_FLARE_7};
    colorFlare = flareColors[type];
}


/*--- Конструктор. Нужен лишь для фигуры которая проверяет столкновение! ---*/
Pieces::Pieces() {
    x = 0;
    y = 0;
    type = 0;
    figure = new char *[5];
    for (int i = 0; i < 5; i++) {
        figure[i] = new char[5];
    }
}

/*--- Конструктор ---*/
Pieces::Pieces(short type) {
    this->type = type;
    x = (WIDTH / SIZE_CUBE / 2 - 2) * SIZE_CUBE;    //Центруем по X
    y = 0;
    figure = new char *[5];
    setColor(type);
    setColorBord(type);
    setColorFlare(type);

    //Создаём двумерный массив, представляющий фигуру
    for (int i = 0; i < 5; i++) {
        figure[i] = new char[5];
        for (int j = 0; j < 5; j++) {
            figure[i][j] = figures[type][i][j];
        }
    }
}


/*--- Функция возращающая случайно одну из 7ми фигур ---*/
Pieces *addFigure() {
    int type = std::rand() % 7;
    if (type < 3) return new Pieces(type);
    else if (type == 3) return new Cube(type);
    else if (type == 4) return new Snake(type);
    else if (type == 5) return new Snake(type);
    else if (type == 6) return new Line(type);
    else return nullptr;;            //If error
}

/*--- Функция возращающая указатель на копию созданной фигуры ---*/
Pieces *getFigure(Pieces *figure) {
    //Следующие строки - говнокод ебанный.
    Pieces *tmp;
    if (figure->getType() < 3) tmp = new Pieces(figure->getType());
    else if (figure->getType() == 3) tmp = new Cube(figure->getType());
    else if (figure->getType() == 4) tmp = new Snake(figure->getType());
    else if (figure->getType() == 5) tmp = new Snake(figure->getType());
    else if (figure->getType() == 6) tmp = new Line(figure->getType());

    tmp->setType(figure->getType());
    tmp->setX(figure->getX());
    tmp->setY(figure->getY());
    tmp->setFigure(figure->getFigure());

    return tmp;
}


Pieces &Pieces::operator=(Pieces &pieces) {
    x = pieces.x;
    y = pieces.y;
    type = pieces.type;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->figure[i][j] = pieces.figure[i][j];
        }
    }
    return *this;
}


Pieces::~Pieces() {
    for (int i = 0; i < 5; i++) {
        delete[] figure[i];
    }

    delete[] figure;
}

void Pieces::moveLeft() {
    this->x -= SIZE_CUBE;
}

void Pieces::moveRight() {
    this->x += SIZE_CUBE;
}

void Pieces::moveDown() {
    this->y += SIZE_CUBE;
}

/*--- Транспонирование матрицы фигуры(Принимает "лево" или "право") ---*/
void Pieces::transposing(std::string turnType) {
    //Копируем текущее расположение
    char tmp[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[i][j] = figure[i][j];
        }
    }

    //Транспонируем
    for (int i = 4; i > -1; i--) {
        for (int j = 0; j < 5; j++) {
            if (turnType == "влево") figure[j][i] = tmp[i][j];
            if (turnType == "вправо") figure[j][4 - i] = tmp[i][j];
        }
    }
}

/*--- Смещение матрицы фигуры на 1 вправо или влево ---*/
void Pieces::offsetX(std::string offType) {
    int s_x, e_x, dx;
    if (offType == "вправо") {
        s_x = 5;
        e_x = 0;
        dx = -1;
    }
    if (offType == "влево") {
        s_x = 0;
        e_x = 4;
        dx = 1;
    }
    //Само смещение
    for (int i = 0; i < 5; i++) {
        for (int j = s_x; j != e_x; j += dx) {
            figure[i][j] = figure[i][j + dx];
        }
    }

}


/*--- Возвращает 'true', если фигурка 'змейки' в вертикальном положении ---*/
bool Snake::isVertical() {
    if (figure[1][2] || figure[1][3]) return true;
    return false;
}


/*--- Вращение для фигур 'I=', 'I_', '_I' ---*/
void Pieces::turn() {
    transposing("вправо");
}

/*--- Вращение для куба (отсутствует) ---*/
void Cube::turn() {}

/*--- Вращение для линии  ---*/
void Line::turn() {
    transposing("влево");
}

/*--- Вращение для змейки  ---*/
void Snake::turn() {
    if (type == 4) {          //Вращаем один тип змейки
        if (isVertical()) {
            transposing("вправо");
        } else {
            transposing("вправо");
            offsetX("вправо");
        }
    }
    if (type == 5) {          //Вращаем другой тип змейки
        if (isVertical()) {
            transposing("вправо");
        } else {
            transposing("вправо");
            offsetX("вправо");
        }
    }
}