#include "Pixel.h"
#include <iostream>
#include <sstream>
using namespace std;
Pixel::Pixel()
{
    //cout << "CREATING PIXEL!!!\n";

    this->red = 1.0f;
    this->blue = 0;
    this->green = 0;
    this->alpha = 1.0f;

    //pos and size;
    this->pos = glm::vec3(0,0,0);
    this->width = 1;
    this->height = 1;

    this->ray = NULL;
    //ctor
}

Pixel::Pixel(glm::vec3 pos, float height, float width)
{
    //cout << "CREATING PIXEL!!!\n";

    // set the pos and size
    this->pos = pos;
    this->height = height;
    this->width = width;

    // set default color to red!
    this->red = 1.0f;
    this->blue = 0;
    this->green = 0;
    this->alpha = 1.0f;

    this->ray = NULL;
    //ctor
}

Pixel::~Pixel()
{
    //dtor
}

// orientation access functions

void Pixel::setPos(glm::vec3 pos) {
    this->pos = pos;
}

glm::vec3 Pixel::getPos() {
    return this->pos;
}
// these are set during run time, should they be public const instead?
float Pixel::getHeight()
{
    return this->height;
}
void Pixel::setHeight(float height)
{
    this->height = height;
}
float Pixel::getWidth() {
    return this->width;
}
void Pixel::setWidth(float width) {
    this->width = width;
}



// color access functions
float Pixel::getRed()
{
    return this->red;
    //dtor
}

void Pixel::setRed(float red)
{
    this->red = red;
}

float Pixel::getGreen()
{
    return this->green;
    //dtor
}
void Pixel::setGreen(float green)
{
    this->green = green;
}
float Pixel::getBlue()
{
    return this->blue;
    //dtor
}
void Pixel::setBlue(float blue)
{
    this->blue = blue;
}

Ray* Pixel::getRay() {
    return this->ray;
}

void Pixel::setRay(Ray *ray) {
    this->ray = ray;
}





void Pixel::myPrint()
{
    std::cout << "[ " << this->red << " " << this->green << " " << this->blue << "]";
}

int Pixel::getTGAData() {


    //std::cout << "calling Pixel::getTGAData!\n";
    int result = 0;

    //std::cout << "Getting TGA data from pixel!\n";
    result = result + this->red * 255 *255;
    //std::cout << "added red... result is: " << result << "\n";
    result = result + this->green * 255;
    //std::cout << "added green... result is: " << result << "\n";
    result = result + this->blue * 255;
    //std::cout << "added blue... result is: " << result << "\n";

    return result;

}


std::string Pixel::toString()
{
    std::string output;
    ostringstream ss;
    ss.clear();
    ss << this->red << " " << this->green << " " << this->blue;
    output = ss.str();
    const char* result = output.c_str();
    return result;

    /*
    std::stringstream sstm;
    sstm.str("");
    sstm << "[ " << this->red << " " << this->green << " " << this->blue << "]";

    string output;
    output = "[ ";
    output += std:: this->red;
    output += " ";
    output += this->green;
    output += " ";
    output += this->blue;
    output += "]";

    sstm >> output;
    return output;
    */
}
