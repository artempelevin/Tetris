#ifndef SETTING_H
#define SETTING_H

/*  -------------------------------- ОСНОВНЫЕ РАЗМЕРЫ-----------------------------------   */
#define WIDTH           300             //Ширина приложения
#define HEIGHT          600             //Высота приложения
#define PANEL_WIDTH     150             //Ширина панели

/*  -------------------------------- ФЛАГИ ---------------------------------------------   */
#define BORDER          1               //Вкл/выкл границы ячеек 
#define FLARE           1               //Вкл/выкл блики 

/*  -------------------------------- РАЗМЕРЫ -------------------------------------------    */
#define SIZE_CUBE       25              //Размер одной ячейки
#define NUMBER_SIZE     4               //Размер блоков цифр
#define SIZE_BORDER     2               //Размер границы одной ячейки
#define SIZE_FLARE1     7               //Размер блика №1
#define SIZE_FLARE2     5               //Размер блика №2

/*  -------------------------------- ЦВЕТА ---------------------------------------------    */
#define COLOR_NUMBER    0x74e600         //Цвет цифр

#define COLOR_BACK      0x1A2028        //Цвет пустых ячеек
#define COLOR_BACK_BORD 0x09111B        //Цвет границ пустых ячеек 
#define COLOR_BACK_FLARE 0x171E27       //Цвет бликов пустых ячеек 

#define COLOR_1         0x9440D5        //Цвет фигуры №1 (I=)
#define COLOR_BORD_1    0x57158A        //Цвет границы для фигуры №1 (I=)
#define COLOR_FLARE_1   0xCE95F9        //Цвет блика для фигуры №1 (I=)

#define COLOR_2         0x1a1eb2        //Цвет фигуры №2 (I_)
#define COLOR_BORD_2    0x080B74        //Цвет границы для  фигуры №2 (I_)
#define COLOR_FLARE_2   0x7074F9        //Цвет блика для фигуры №2 (I_)

#define COLOR_3         0xff7f00        //Цвет фигуры №3 (_I)
#define COLOR_BORD_3    0xA65200        //Цвет границы для фигуры №3 (_I)
#define COLOR_FLARE_3   0xF9A24B        //Цвет блика для фигуры №3 (_I)

#define COLOR_4         0xffe100        //Цвет фигуры №4 (КУБ)
#define COLOR_BORD_4    0xA69200        //Цвет границы для фигуры №4 (КУБ)
#define COLOR_FLARE_4   0xF9E44B        //Цвет блика для фигуры №4 (КУБ)

#define COLOR_5         0x74e600        //Цвет фигуры №5 (Z)
#define COLOR_BORD_5    0x4B9600        //Цвет границы для фигуры №5 (Z)
#define COLOR_FLARE_5   0xA2F94B        //Цвет блика для фигуры №5 (Z)

#define COLOR_6         0xf70018        //Цвет фигуры №6 (Z-обратная)
#define COLOR_BORD_6    0xA1000F        //Цвет границы для фигуры №6 (Z-обратная)
#define COLOR_FLARE_6   0xF94B5C        //Цвет блика для фигуры №6 (Z-обратная)

#define COLOR_7         0x00a78b        //Цвет фигуры №7 (|)
#define COLOR_BORD_7    0x006D5A        //Цвет границы для фигуры №7 (|)
#define COLOR_FLARE_7   0x4BF9DC        //Цвет блика для фигуры №7 (|)

/*  -------------------------------- ВРЕМЕННЫЕ КОНСТАНТЫ -------------------------------    */
#define TIME_FRAME      450             //Время одного кадра
#define TIME_CLEAN      100             //Время очистки одного ряда

#endif