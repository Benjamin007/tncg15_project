#include "Screen.h"
#include <iostream>
#include <fstream>
#include "TGAWriter.h"
#include "common/LoadTGA.h"

Screen::Screen()
{


    std::cout << "CREATING SCREEN!\n";

    this->width = WIDTH;
    this->height = HEIGHT;
    this->near = NEAR;


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

int Screen::getHeight() const {
    return this->height;
}
int Screen::getWidth() const {
    return this->width;
}
int Screen::getNear() const {
    return this->near;
}

void Screen::myPrint()
{
    for (int x = 0; x < WIDTH; x++) {
        std::cout << "\n";
        for (int y = 0; y < HEIGHT; y++) {
            screen[x][y]->myPrint();
        }
    }
}

void Screen::printToFile(std::string fileName) {
    std::ofstream myFile;
    myFile.open(fileName.c_str());
    myFile << WIDTH << " " << HEIGHT << "\n";
    //myFile << "[ \n";
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            std::string pixelString = screen[x][y]->toString();
            //std::cout << "Currently printing...:"  << pixelString;
            myFile << pixelString << " ";
        }
        myFile << "\n";
    }
    //myFile << "]";
    myFile.close();
}

// prints to out.tga
void Screen::printToTGA() {

    std::cout << "Started printToTGA\n";

    TGAWriter *writer = new TGAWriter();

    RBitmap data;

    data.height = this->getHeight();
    data.width = this->getWidth();

    data.data = new int*[WIDTH];
    for(int i = 0; i < WIDTH; ++i)
        data.data[i] = new int[HEIGHT];

    std::cout << "Created RBitmap, attempting to fill pixel data...\n";

    unsigned char *imageData = new unsigned char[width*height];

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {

            //std::cout << "Filling x:" << x << " y: " << y << " \n";
            int pixelData = this->screen[x][y]->getTGAData();
            data.data[x][y] = pixelData;
            imageData[(x-1)*width + y] = pixelData;
        }
    }

    SaveDataToTGA("out.tga",WIDTH,HEIGHT,24,imageData);


    //writer->write_truecolor_tga(&data);


    std::cout << "Finished filling pixel data!\n";

}

