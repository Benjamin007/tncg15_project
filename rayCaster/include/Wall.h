#ifndef WALL_H
#define WALL_H

#include "Object.h"

#include "glm/glm/glm.hpp"
#include "Ray.h"
#include <stddef.h>
#include "math.h"

class Wall : public Object
{
    public:
        Wall(int id);
        Wall(int id, glm::vec3 pos, glm::vec3 norm, float h, float w, float x1, float x2, float y1, float y2, float z1, float z2);
         ~Wall();

         // check if the direction of the ray is parallel to the plan
        bool isParallel(const Ray* ray) const;

        float getBRDF() const;

//        void setBrdf(float brdf);

        // return the intersection point between a ray and a plane. If there is not, the field isIntersecting is false
        Intersection* getIntersection(const Ray* const ray) const;

    protected:
        // position of the point in the middle of the wall
        glm::vec3 position;

        glm::vec3 normal;
        float height;
        float width;

        // here are the 6 constraints value of the wall:
        float x1;
        float x2;
        float y1;
        float y2;
        float z1;
        float z2;

        float rho;
        float BRDF;

    private:
};

#endif // WALL_H
