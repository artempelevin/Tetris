#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
    int time;    //Время c запуска таймера
public:
    Timer();

    bool isPass(int millisecond);
};

#endif