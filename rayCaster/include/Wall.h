#ifndef WALL_H
#define WALL_H

#include "Object.h"

#include "glm/glm/glm.hpp"
#include "Ray.h"

class Wall : public Object
{
    public:
        Wall();
        virtual ~Wall();
        bool isIntersecting(Ray ray);
        glm::vec3 getIntersection(Ray ray);
    protected:
        glm::vec3 position;
        glm::vec3 normal;
        float height;
        float width;
    private:
};

#endif // WALL_H
