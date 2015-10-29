#ifndef SCREEN_H
#include "Pixel.h"
#define SCREEN_H

// pixels in screen:
#define HEIGHT 2
#define WIDTH 2

// frustum variables:
#define NEAR -100
#define LEFT -100
#define RIGHT 100
#define TOP 100
#define BOTTOM -100




class Screen
{
    public:
        Screen();
        virtual ~Screen();

        // getters
        int getWidth() const;
        int getHeight() const;
        int getNear() const;

        // setters getters
        void assignRay(int x, int y, Ray* ray);
        Ray* getRay(int x, int y);

        void assignColor(int x, int y, glm::vec3 color);

        glm::vec3 getPixelPos(int x, int y);

        void myPrint();
        void printToFile(std::string matrixFileName,std::string dimFileName);
        void printToTGA();

    protected:
        int width;
        int height;
        int near;
        Pixel* screen[HEIGHT][WIDTH];
    private:
};

#endif // SCREEN_H
