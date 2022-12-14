#ifndef FIGURES_H
#define FIGURES_H

char figures[7][5][5] = {
        // I=
        {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 1, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
        },
        // I_
        {
                {0, 0, 0, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 2, 2, 0},
                {0, 0, 0, 0, 0}
        },
        // _I
        {
                {0, 0, 0, 0, 0},
                {0, 0, 3, 0, 0},
                {0, 0, 3, 0, 0},
                {0, 3, 3, 0, 0},
                {0, 0, 0, 0, 0}
        },
        // Куб
        {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 4, 4, 0, 0},
                {0, 4, 4, 0, 0},
                {0, 0, 0, 0, 0}
        },
        // Z
        {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 5, 5, 0},
                {0, 5, 5, 0, 0},
                {0, 0, 0, 0, 0}
        },
        //Z - обратная
        {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 6, 6, 0, 0},
                {0, 0, 6, 6, 0},
                {0, 0, 0, 0, 0}
        },
        // I
        {
                {0, 0, 7, 0, 0},
                {0, 0, 7, 0, 0},
                {0, 0, 7, 0, 0},
                {0, 0, 7, 0, 0},
                {0, 0, 0, 0, 0}
        }
};

#endif