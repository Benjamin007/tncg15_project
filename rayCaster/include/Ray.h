#ifndef RAY_H
#define RAY_H

#include "glm/glm/vec3.hpp"
#include "Intersection.h"

class Ray
{
    public:
        Ray();
        Ray(glm::vec3 o, glm::vec3 dir);
        Ray(glm::vec3 o, glm::vec3 dir, Intersection* inter);
        ~Ray();

        glm::vec3 getOrigin() const;
        glm::vec3 getDirection() const;

        glm::vec3 getColor();   // recursive function that will calculate total color, whop whop!
        glm::vec3 setColor(glm::vec3 color);

        float getMin_t() const;
        void setMin_t(float t);
        int getId_IntersectedObject() const;
        void setId_IntersectedObject(int i);
    protected:

        int pixelX, pixelY;
        glm::vec3 origin;
        glm::vec3 direction; // must be normalized
        glm::vec3 color;
        Intersection* intersection;
        Ray *child;


    private:
};

#endif // RAY_H
