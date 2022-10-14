#ifdef WINDOWS
#include <SDL_keycode.h>
#include <SDL_timer.h>
#include <SDL.h>
#endif // WINDOWS
#ifdef LINUX

#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL.h>

#endif //LINUX

#include <iostream>
#include <typeinfo>

#include "window.h"
#include "field.h"
#include "canvas.h"
#include "pieces.h"
#include "setting.h"
#include "timer.h"
#include "panel.h"

int main(int argc, char *argv[]) {
    Window game("Tetris", HEIGHT, WIDTH + PANEL_WIDTH);   //Окно игры
    Canvas canvas(game.getWin());           //Холст для рисования
    SDL_Event windowEvent;                  //Обработчик событий

    Timer timer;                            //Таймер
    Field field;                            //Создаём игровое поле 
    Pieces *figure = addFigure();           //Создаём начальную фигуру
    Pieces *nextFigure = addFigure();       //Создаём следующиую фигуру                 
    Panel panel(nextFigure);                //Боковая панель с очками и след. фигурой

    while (true) {
        //Если нажата кнопка
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) break;         //Выход
            if (windowEvent.type == SDL_KEYDOWN) {                //Если нажаты кнопки
                Pieces *checkFigure = getFigure(figure);

                switch (windowEvent.key.keysym.sym) {
                    case SDLK_UP:           //Поворот
                        checkFigure->turn();
                        if (!field.checkScreenOff(checkFigure) && !field.checkColision(checkFigure))
                            figure->turn();
                        break;
                    case SDLK_DOWN:         //Вниз
                        checkFigure->moveDown();
                        if (!field.checkScreenOff(checkFigure) && !field.checkColision(checkFigure))
                            figure->moveDown();
                        break;
                    case SDLK_LEFT:         //Влево
                        checkFigure->moveLeft();
                        if (!field.checkScreenOff(checkFigure) && !field.checkColision(checkFigure))
                            figure->moveLeft();
                        break;
                    case SDLK_RIGHT:        //Вправо
                        checkFigure->moveRight();
                        if (!field.checkScreenOff(checkFigure) && !field.checkColision(checkFigure))
                            figure->moveRight();
                        break;
                }
            }
        } else {
            //Проверка на конец игры
            if (field.checkColision(figure)) {
                std::cout << "GameOver!";
                break;
            }

            short rows = field.cleanRows(); //Очищаем ряды, если надо    
            if (rows) panel.addPoints(rows * 15);
            canvas.render(field);           //Рендерим поле
            canvas.renderFigure(*figure);   //Рендерим фигуру
            canvas.renderPanel(panel);      //Рендерит панель

            game.update();                  //Обновляем экран

            //Каждые n-миллисекундр опускаем фигуру и проверяем её на столкновение
            if (timer.isPass(TIME_FRAME)) {
                Pieces *checkFigure = getFigure(figure);
                checkFigure->moveDown();
                //Если можно двигаться вниз
                if (!field.checkScreenOff(checkFigure) && !field.checkColision(checkFigure)) {
                    figure->moveDown();
                }
                    //Если нельзя, то оставляем фигуру на поле и создаём новую
                else {
                    field.setFigure(figure);
                    figure = nextFigure;
                    nextFigure = addFigure();
                    panel.setFigure(nextFigure);
                }
            }
        }
    }

    game.quit();

    return EXIT_SUCCESS;
}
