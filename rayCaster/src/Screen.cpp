#include "Screen.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Ray.h"

Screen::Screen()
{


    // SCREEN IS HARD CODED TO BE AXIS PARALLELL WITH XZ-PLANE.
    std::cout << "CREATING SCREEN!\n";

    this->width = WIDTH;
    this->height = HEIGHT;
    this->near = NEAR;

    float pixelWidth, pixelHeight;
    // the amount of coordinates a pixel will have.
    pixelWidth = (float) abs(LEFT - RIGHT) / ((float) WIDTH);
    pixelHeight =(float) abs(BOTTOM - TOP) / ((float) HEIGHT);

    int counter = 0;
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            glm::vec3 pos = glm::vec3(
                                        (float) pixelWidth/2 + LEFT    + ((float)x)*pixelWidth,
                                        (float) pixelHeight/2 + BOTTOM  + ((float)y)*pixelHeight,
                                        (float) NEAR);

            this->screen[x][y] = new Pixel(pos, pixelWidth, pixelHeight);
            counter++;
        }
    }

    //glm::vec3 testPixelPos = this->screen[4][4]->getPos();

    //std::cout << "TEST: pixel 5,5 has position: (" << testPixelPos.x << "," << testPixelPos.y << "," << testPixelPos.z << ")\n";

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

void Screen::assignRay(int x, int y, Ray *ray) {
    this->screen[x][y]->setRay(ray);
}

Ray* Screen::getRay(int x, int y) {
    this->screen[x][y]->getRay();
}


void Screen::assignColor(int x, int y, glm::vec3 color) {
    this->screen[x][y]->setRed(color.x);
    this->screen[x][y]->setGreen(color.y);
    this->screen[x][y]->setBlue(color.z);
}


glm::vec3 Screen::getPixelPos(int x, int y) {
    return this->screen[x][y]->getPos();
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

void Screen::printToFile(std::string matrixFileName, std::string dimFileName) {
    std::ofstream myFile, myDimFile;

    myDimFile.open(dimFileName.c_str());
    myDimFile << WIDTH << " " << HEIGHT << "\n";


    myFile.open(matrixFileName.c_str());
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

    // currently not working at all

    /*
    std::cout << "Started printToTGA\n";

    TGAWriter *writer = new TGAWriter();

    RBitmap data;
    RBitmapSingle dataSingle;

    data.height = this->getHeight();
    dataSingle.height = this->getHeight();
    data.width = this->getWidth();
    dataSingle.width = this->getWidth();

    data.data = new int*[WIDTH];
    for(int i = 0; i < WIDTH; ++i)
        data.data[i] = new int[HEIGHT];

    dataSingle.data = new int[WIDTH*HEIGHT*3];

    std::cout << "Created RBitmap, attempting to fill pixel data...\n";

    unsigned char *imageData = new unsigned char[width*height];

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {

            //std::cout << "Filling x:" << x << " y: " << y << " \n";
            int pixelData = this->screen[x][y]->getTGAData();
            data.data[x][y] = pixelData;
            imageData[x + (y-1)*width] = pixelData;
            dataSingle.data[x+(y-1)*width + 0] = (int) 255.0*(this->screen[x][y]->getBlue());
            dataSingle.data[x+(y-1)*width + 1] = (int) 255.0*(this->screen[x][y]->getGreen());
            dataSingle.data[x+(y-1)*width + 2] = (int) 255.0*(this->screen[x][y]->getRed());


        }
    }

    // bmp code from internet:

    int SizeValue = WIDTH * HEIGHT;

    unsigned char* buf = new unsigned char[ 3 * SizeValue ];

    int c = 0;

    for ( int i = 0; i < WIDTH; i++ )
    {
        for ( int j = 0; j < HEIGHT; j++ )
        {
            unsigned char valRed =
                this->screen[ i ][ j ]->getRed() == 0 ? 0xFF : 0x00;
            unsigned char valGreen =
                this->screen[ i ][ j ]->getGreen() == 0 ? 0xFF : 0x00;
            unsigned char valBlue =
                this->screen[ i ][ j ]->getBlue() == 0 ? 0xFF : 0x00;

            buf[ c + 0 ] = (unsigned char) valRed;
            buf[ c + 1 ] = (unsigned char) valGreen;
            buf[ c + 2 ] = (unsigned char) valBlue;

            c += 3;
        }
    }

    //data.data=buf;











    std::cout << "Attempting to save to the TGA!\n";


    //SaveDataToTGA("out.tga",WIDTH,HEIGHT,24,imageData);
    //SaveDataToTGA("out.tga",WIDTH,HEIGHT,24,buf);


    //writer->write_truecolor_tga(&data);
    writer->myWriteTGA(&dataSingle);



    std::cout << "Finished filling pixel data!\n";

*/


}

