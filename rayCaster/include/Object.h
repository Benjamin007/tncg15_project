#ifndef OBJECT_H
#define OBJECT_H

#include "Ray.h"
#include "glm/glm/glm.hpp"
#include <iostream>

class Object
{
    public:
        Object();
        Object(int id, glm::vec3 pos);
        virtual  Intersection* getIntersection(const Ray* const ray) const = 0;
        virtual ~Object();

        const float getBRDF();
        glm::vec3 const getColor();
        void setColor(glm::vec3 color);
        glm::vec3 getPos() const;
        int getId() const;

    protected:
        int id;
        glm::vec3 pos;
        glm::vec3 color;
        const float BRDF;
    private:
};

#endif // OBJECT_H
