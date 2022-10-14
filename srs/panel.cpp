#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "panel.h"
#include "pieces.h"

Pieces *Panel::getFigure() { return nextFigure; }

std::string Panel::getPoint() { return points; }

std::string Panel::getMaxPoint() { return maxPoints; }

void Panel::setFigure(Pieces *Figure) {
    nextFigure = Figure;
}


Panel::Panel(Pieces *Figure) {
    //Считываем maxPoint из файла или зануляем их 
    std::ifstream in("max_points.txt"); // окрываем файл для чтения
    if (in.is_open()) {
        getline(in, maxPoints);
    } else {
        maxPoints = "0";
    }
    points = "0";

    nextFigure = Figure;
    in.close();
}


void Panel::addPoints(short points) {
    int allPoints = atoi(this->points.c_str());
    allPoints += points;
    this->points = std::to_string(allPoints);
    //Перезаписываем файл с max очками
    if (atoi(maxPoints.c_str()) < atoi(this->points.c_str())) {
        //Записываем очки в файл, если это новый рекорд        
        std::ofstream out;
        out.open("max_points.txt");
        if (out.is_open()) {
            out << this->points << std::endl;
        }
        maxPoints = this->points;
        out.close();
    }

}
