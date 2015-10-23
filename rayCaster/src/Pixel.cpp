#include "Pixel.h"
#include <iostream>
#include <sstream>
using namespace std;
Pixel::Pixel()
{
    //cout << "CREATING PIXEL!!!\n";

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
