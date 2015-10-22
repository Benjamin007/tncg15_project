#ifndef SCREEN_H
#include "Pixel.h"
#define SCREEN_H

#define HEIGHT 50
#define WIDTH 50



class Screen
{
    public:
        Screen();
        void myPrint();
        virtual ~Screen();
    protected:
        int width;
        int height;
        Pixel* screen[HEIGHT][WIDTH];
    private:
};

#endif // SCREEN_H
