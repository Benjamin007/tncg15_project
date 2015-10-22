#include "Screen.h"
#include <iostream>
Screen::Screen()
{
    this->width = WIDTH;
    this->height = HEIGHT;



    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {

            this->screen[x][y] = new Pixel();

        }
    }

    //ctor
}

Screen::~Screen()
{
    //dtor
}

void Screen::myPrint()
{
    for (int x = 0; x < WIDTH; x++) {
        std::cout << "\n";
        for (int y = 0; y < WIDTH; y++) {
            screen[x][y]->myPrint();
        }
    }
}

