#ifndef PIXEL_H
#define PIXEL_H

#include <string>

#include "glm/glm/glm.hpp"
#include "Ray.h"

class Pixel
{
    public:
        Pixel();
        Pixel(glm::vec3 pos, float width, float height);
        virtual ~Pixel();

        // setters and getters
        // orientation:
            // these are set during run time, should they be public const instead?
        glm::vec3 getPos();
        void setPos(glm::vec3 pos);
        float getHeight();
        void setHeight(float height);
        float getWidth();
        void setWidth(float width);

        // color
        float getRed();
        float getGreen();
        float getBlue();
        void setRed(float color);
        void setGreen(float color);
        void setBlue(float color);

        // ray

        Ray* getRay();
        void setRay(Ray* ray);

        // functions
        void myPrint();
        std::string toString();
        int getTGAData();
    protected:
        glm::vec3 pos; // these are set during run time, should they be public const instead?
        float height;// these are set during run time, should they be public const instead?
        float width;// these are set during run time, should they be public const instead?
        float red;
        float green;
        float blue;
        float alpha;

        Ray *ray;

    private:
};

#endif // PIXEL_H
