#ifndef SCREEN_H
#include "Pixel.h"
#define SCREEN_H

#define HEIGHT 10
#define WIDTH 10
#define NEAR 20



class Screen
{
    public:
        int getWidth() const;
        int getHeight() const;
        int getNear() const;
        Screen();
        void myPrint();
        void printToFile(std::string fileName);
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
