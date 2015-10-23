#ifndef WALL_H
#define WALL_H

#include "Object.h"

#include "glm/glm/glm.hpp"
#include "Ray.h"
#include <stddef.h>

class Wall : public Object
{
    public:
        Wall(int* id);
        Wall(int* id, glm::vec3 pos, glm::vec3 norm, float h, float w);
         ~Wall();

         // check if the direction of the ray is parallel to the plan
        bool isIntersecting(Ray* ray) const;

        // return the intersection point between a ray and a plane. If there is not, the field isIntersecting is false
        Intersection* getIntersection(Ray* ray) const;

    protected:
        // position of the point in the middle of the wall
        glm::vec3 position;

        glm::vec3 normal;
        float height;
        float width;
    private:
};

#endif // WALL_H
