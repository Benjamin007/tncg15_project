#ifndef OBJECT_H
#define OBJECT_H

#include "Ray.h"
#include "glm/glm/glm.hpp"
#include "Intersection.h"

class Object
{
    public:
        Object();
        Object(int id, glm::vec3 pos);
        virtual  Intersection* getIntersection(const Ray* const ray) const = 0;
        virtual ~Object();

        const float getBRDF();

    protected:
        int id;
        glm::vec3 pos;
        const float BRDF;
    private:
};

#endif // OBJECT_H
