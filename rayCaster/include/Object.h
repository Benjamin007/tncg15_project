#ifndef OBJECT_H
#define OBJECT_H

#include "Ray.h"
#include "glm/glm/glm.hpp"
#include "Intersection.h"

class Object
{
    public:
        Object();
        Object(int id);
        virtual  Intersection* getIntersection(const Ray* const ray) const = 0;
        virtual ~Object();
    protected:
        int id;
    private:
};

#endif // OBJECT_H
