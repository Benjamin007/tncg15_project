#ifndef OBJECT_H
#define OBJECT_H

#include "Ray.h"
#include "glm/glm/glm.hpp"
#include "Intersection.h"

class Object
{
    public:
        Object();
        Object(int* id);
        virtual bool isIntersecting(Ray* ray) const = 0;
        virtual  Intersection* getIntersection(Ray* ray) const = 0;
        virtual ~Object();
    protected:
        int* id;
    private:
};

#endif // OBJECT_H
