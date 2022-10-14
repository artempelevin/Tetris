#include <cstdlib>
#include <ctime>
#include "window.h"


SDL_Window *Window::getWin() { return win; }

/*--- Конструктор ---*/
Window::Window(std::string title, int height, int width) {
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Ошибка инициализации SDL..." << SDL_GetError() << std::endl;
    }
    win = SDL_CreateWindow(title.c_str(),
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           width,
                           height,
                           0);
    if (win == nullptr) {
        std::cout << "Ошибка создания окна..." << SDL_GetError() << std::endl;
    }

}

/*--- Обновление окна ---*/
void Window::update() {
    SDL_UpdateWindowSurface(win);
}

/*--- Закрытие окна ---*/
void Window::quit() {
    SDL_DestroyWindow(win);
    SDL_Quit();
}

