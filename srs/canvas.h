#ifndef CANVAS_H
#define CANVAS_H

#ifdef WINDOWS
#include <SDL.h>
#endif  // WINDOWS
#ifdef LINUX

#include <SDL2/SDL.h>

#endif  // LINUX

#include "pieces.h"
#include "field.h"
#include "panel.h"

class Canvas {
private:
    SDL_Rect *rect;                         //Прямоугольник для отрисовки
    SDL_Surface *surface;                   //Поверхность для рисования

    void drawNum(short num, int x, int y);        //Рендерит цифру в указанных координатах
    void drawCell(short x, short y, short type);  //Рисует ячейку
public:
    Canvas(SDL_Window *win);

    void fillRect(int x, int y, int width, int height, Uint32 color);   //Ф-ция рисования прямоуг.

    void renderFigure(Pieces &pieces);              //Рендерит фиругу
    void render(Field &field);                      //Рендерит поле
    void renderPanel(Panel &panel);                 //Рендерит панель

};

#endif
