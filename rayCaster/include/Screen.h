#ifndef SCREEN_H
#include "Pixel.h"
#define SCREEN_H

#include "CONSTANTS.h"
// pixels in screen:







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
