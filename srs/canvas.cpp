#ifdef WINDOWS                      // WINDOWS
#include <SDL_rect.h>
#include <SDL_stdinc.h>
#include <SDL_surface.h>
#include <SDL_timer.h>
#else                               //LINUX

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>

#endif

#include <iostream>
#include <string>

#include "canvas.h"
#include "setting.h"
#include "timer.h"
#include "panel.h"
#include "numbers.h"

/*--- Конструктор ---*/
Canvas::Canvas(SDL_Window *win) {
    surface = SDL_GetWindowSurface(win);
    if (surface == nullptr) {
        std::cout << "Ошибка инициализации SDL..." << SDL_GetError() << std::endl;
    }
    rect = new SDL_Rect;
}

/*--- Рисования прямоугольника ---*/
void Canvas::fillRect(int x, int y, int width, int height, Uint32 color) {
    this->rect->x = x;
    this->rect->y = y;
    this->rect->h = height;
    this->rect->w = width;
    SDL_FillRect(surface, rect, color);
}

/*--- Рисует ячейку ---*/
void Canvas::drawCell(short x, short y, short type) {
    int colors[8] = {COLOR_BACK, COLOR_1, COLOR_2, COLOR_3, COLOR_4, COLOR_5, COLOR_6, COLOR_7};
    int bordColors[8] = {COLOR_BACK_BORD, COLOR_BORD_1, COLOR_BORD_2, COLOR_BORD_3, COLOR_BORD_4, COLOR_BORD_5,
                         COLOR_BORD_6, COLOR_BORD_7};
    int flareColors[8] = {COLOR_BACK_FLARE, COLOR_FLARE_1, COLOR_FLARE_2, COLOR_FLARE_3, COLOR_FLARE_4, COLOR_FLARE_5,
                          COLOR_FLARE_6, COLOR_FLARE_7};

    //С рамкой
    if (BORDER) {
        fillRect(x, y, SIZE_CUBE, SIZE_CUBE, bordColors[type]);
        fillRect(x + SIZE_BORDER, y + SIZE_BORDER, SIZE_CUBE - (2 * SIZE_BORDER), SIZE_CUBE - (2 * SIZE_BORDER),
                 colors[type]);
    } else {
        fillRect(x, y, SIZE_CUBE, SIZE_CUBE, colors[type]);
    }
    //С бликами
    if (FLARE) {
        fillRect(x + 2 * SIZE_BORDER, y + 2 * SIZE_BORDER, SIZE_FLARE1, SIZE_FLARE1, flareColors[type]);
        fillRect(x + 2 * SIZE_BORDER + SIZE_FLARE1, y + 2 * SIZE_BORDER, SIZE_FLARE2, SIZE_FLARE2, flareColors[type]);
        fillRect(x + 2 * SIZE_BORDER, y + 2 * SIZE_BORDER + SIZE_FLARE1, SIZE_FLARE2, SIZE_FLARE2, flareColors[type]);
    }


}

/*--- Рендер текущей фигуры игрока ---*/
void Canvas::renderFigure(Pieces &pieces) {
    int x = pieces.getX();
    int y = pieces.getY();
    char **figure = pieces.getFigure();
    int x0 = x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (figure[i][j]) {
                drawCell(x0, y, figure[i][j]);
            }
            x0 += SIZE_CUBE;
        }
        x0 = x;
        y += SIZE_CUBE;
    }
}


/*--- Рендер игрового поля ---*/
void Canvas::render(Field &field) {
    char **cells = field.getCells();
    short x = 0, y = 0;
    for (int i = 0; i < field.getStr(); i++) {
        for (int j = 0; j < field.getCol(); j++) {
            drawCell(x, y, cells[i][j]);
            x += SIZE_CUBE;
        }
        x = 0;
        y += SIZE_CUBE;
    }
}

/*--- Рендерит цифру в указанных координатах ---*/
void Canvas::drawNum(short num, int x, int y) {
    char number[5][5];

    //Копируем букву в массив
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            number[i][j] = numbers[num][i][j];
        }
    }

    short x0 = x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (number[i][j])
                fillRect(x0, y, NUMBER_SIZE, NUMBER_SIZE, COLOR_NUMBER);
            x0 += NUMBER_SIZE;
        }
        x0 = x;
        y += NUMBER_SIZE;
    }

}


/*--- Рендерит панель ---*/
void Canvas::renderPanel(Panel &panel) {
    //Рисуем задник
    fillRect(WIDTH, 0, PANEL_WIDTH, HEIGHT, COLOR_BACK);

    //Рисуем следующую фигуру
    int x = WIDTH + 15;
    int y = 20;
    char **figure = panel.getFigure()->getFigure();
    int x0 = x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            drawCell(x0, y, figure[i][j]);
            x0 += SIZE_CUBE;
        }
        x0 = x;
        y += SIZE_CUBE;
    }

    //Рсиуем текущие очки 
    std::string point = panel.getPoint();
    x0 = WIDTH + 15;
    y += NUMBER_SIZE * 5;
    for (int i = 0; point.c_str()[i] != 0; i++) {
        short num = point.c_str()[i] - 48;
        drawNum(num, x0, y);
        x0 += NUMBER_SIZE * 4;
    }

    //Рисуем максимальные очки
    point = panel.getMaxPoint();
    x0 = WIDTH + 15;
    y += NUMBER_SIZE * 8;
    for (int i = 0; point.c_str()[i] != 0; i++) {
        short num = point.c_str()[i] - 48;
        drawNum(num, x0, y);
        x0 += NUMBER_SIZE * 4;
    }

}

