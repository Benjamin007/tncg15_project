#include "Screen.h"
#include <iostream>
Screen::Screen()
{


    std::cout << "CREATING SCREEN!\n";

    this->width = WIDTH;
    this->height = HEIGHT;


    int counter = 0;
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {

            this->screen[x][y] = new Pixel();
            counter++;
        }
    }

    std::cout << "we created " << counter << " pixels!\n";
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

