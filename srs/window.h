#ifndef WINDOWS_H
#define WINDOWS_H

#ifdef WINDOWS
#include <SDL_video.h>
#include <SDL.h>
#endif // WINDOWS
#ifdef LINUX

#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>

#endif // LINUX

#include <iostream>

class Window {
private:
    SDL_Window *win;
public:
    Window(std::string title, int height, int width);

    SDL_Window *getWin();

    void update();          //Обновление экрана
    void quit();            //Закрытие окна
};

#endif
