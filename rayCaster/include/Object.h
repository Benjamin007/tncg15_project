#ifndef OBJECT_H
#define OBJECT_H

#include "Ray.h"
#include "glm/glm/glm.hpp"

class Object
{
    public:
        Object();
        virtual bool isIntersecting(Ray ray) = 0;
        virtual glm::vec3 getIntersection(Ray ray) = 0;
        virtual ~Object();
    protected:
    private:
};

#endif // OBJECT_H
