#include "Pixel.h"
#include <iostream>
using namespace std;
Pixel::Pixel()
{
    this->red = 255;
    this->blue = 0;
    this->green = 0;
    this->alpha = 255;
    //ctor
}

Pixel::~Pixel()
{
    //dtor
}

void Pixel::myPrint()
{
    char pixelValue = '.';

    if(this->red > 250) {
        pixelValue = '*';
    }

    //std::cout << pixelValue;
    std::cout << this->red << " " << this->green << " "<< this->blue << std::endl;
}
