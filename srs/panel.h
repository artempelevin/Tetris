#ifndef PANEL_H
#define PANEL_H

#include "pieces.h"

//Боковая панель с ифнформацией 
class Panel {
private:
    std::string points;
    std::string maxPoints;
    Pieces *nextFigure;
public:
    Panel(Pieces *Figure);

    void setFigure(Pieces *Figure);

    Pieces *getFigure();

    std::string getPoint();

    std::string getMaxPoint();

    void addPoints(short points);
};

#endif