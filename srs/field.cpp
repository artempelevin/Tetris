#ifdef WINDOWS
#include <SDL_timer.h>
#include <SDL_stdinc.h>
#endif // WINDOWS
#ifdef LINUX

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_stdinc.h>

#endif //LINUX

#include <iostream>

#include "setting.h"
#include "field.h"

short Field::getCol() { return col; }

short Field::getStr() { return str; }

char **Field::getCells() { return cells; }

/*--- Устанавливает определённую ячейку в массиве cells  ---*/
void Field::setCell(int x, int y, int val) {
    cells[y][x] = val;
}


/*--- Конструктор ---*/
Field::Field() {
    col = WIDTH / SIZE_CUBE;        //Получаем кол-во столбцов
    str = HEIGHT / SIZE_CUBE;       //Получаем кол-во строк
    //Создаём массив ячеек
    cells = new char *[str];
    for (int i = 0; i < str; i++) {
        cells[i] = new char[col];
        for (int j = 0; j < col; j++) {
            cells[i][j] = 0;
        }
    }

}


/*--- Устанавливает фигиру на игровое поле ---*/
void Field::setFigure(Pieces *pieces) {
    //Получаем фигуру и её текущие координаты
    char **figure = pieces->getFigure();
    short col = pieces->getX() / SIZE_CUBE;
    short str = pieces->getY() / SIZE_CUBE;

    //Копируем фигуру в ячейки игрого поля
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (figure[i][j]) cells[str][col] = figure[i][j];
            col++;
        }
        col = pieces->getX() / SIZE_CUBE;
        str++;
    }
}


/*--- Проверка столкновения ---*/
bool Field::checkColision(Pieces *pieces) {
    char **figure = pieces->getFigure();
    short col = pieces->getX() / SIZE_CUBE;
    short str = pieces->getY() / SIZE_CUBE;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            //Если ячейка фигуры и ячейка поля содержат что-то - это пересечение!
            if (figure[i][j] && cells[str][col]) return true;
            col++;
        }
        col = pieces->getX() / SIZE_CUBE;
        str++;
    }

    return false;
}


/*--- Проверка выхода за экран  ---*/
bool Field::checkScreenOff(Pieces *pieces) {
    char **figure = pieces->getFigure();
    short col = pieces->getX() / SIZE_CUBE;
    short str = pieces->getY() / SIZE_CUBE;

    //Проверка на выход за левую часть экрана
    if (col < 0) {
        for (int j = 0; j < col * -1; j++) {
            for (int i = 0; i < 5; i++) {
                if (figure[i][j]) return true;

            }
        }
    }
    //Проверка на выход за правую часть экрана
    if (col + 5 > this->col) {
        for (int j = 4; j > this->col - col - 1; j--) {
            for (int i = 0; i < 5; i++) {
                if (figure[i][j]) return true;
            }
        }
    }
    //Проверка на выход за пол
    if (str + 5 > this->str) {
        for (int i = 4; i > this->str - str - 1; i--) {
            for (int j = 0; j < 5; j++) {
                if (figure[i][j]) return true;
            }
        }
    }

    return false;

}


/*--- Очищает заполенные ряды и возвращает кол-во очищенных полей  ---*/
short Field::cleanRows() {
    short rows = 0;         //Кол-во очищенных рядов
    //Проходимся по каждой строчке
    for (int y = str - 1; y >= 0; y--) {
        bool clean = true;      //Очищать ли ряд?

        //Проверяем пустая ли строчка?
        for (int x = 0; x < col; x++) {
            if (!cells[y][x]) {
                clean = false;
                break;
            }
        }
        //Если ряд нужно очистить
        if (clean) {
            rows++;
            SDL_Delay(TIME_CLEAN);   //Ждём некоторое время
            //Очищаем ряды
            for (int x = 0; x < col; x++) {
                for (int y0 = y; y0 >= 1; y0--) {
                    cells[y0][x] = cells[y0 - 1][x];
                }
            }
        }
    }

    return rows;
}
