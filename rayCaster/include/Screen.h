#ifndef SCREEN_H
#include "Pixel.h"
#define SCREEN_H

// pixels in screen:
#define HEIGHT 10
#define WIDTH 10

// frustum variables:
#define NEAR 20
#define LEFT -200
#define RIGHT 200
#define TOP 200
#define BOTTOM -200




class Screen
{
    public:
        int getWidth() const;
        int getHeight() const;
        int getNear() const;
        Screen();
        void myPrint();
        void printToFile(std::string matrixFileName,std::string dimFileName);
        void printToTGA();
        virtual ~Screen();
    protected:
        int width;
        int height;
        int near;
        Pixel* screen[HEIGHT][WIDTH];
    private:
};

#endif // SCREEN_H
