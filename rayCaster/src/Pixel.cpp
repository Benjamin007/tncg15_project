#include "Pixel.h"
#include <iostream>
using namespace std;
Pixel::Pixel()
{
    cout << "CREATING PIXEL!!!\n";

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
    std::cout << "[ " << this->red << " " << this->green << " " << this->blue << "]";
}
