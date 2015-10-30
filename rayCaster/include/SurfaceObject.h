#ifndef SURFACEOBJECT_H
#define SURFACEOBJECT_H

#include "CONSTANTS.h"
#include <Object.h>


class SurfaceObject : public Object
{
    public:
        SurfaceObject();
        SurfaceObject(int id, glm::vec3 pos, glm::vec3 norm, float h, float w, float x1, float x2, float y1, float y2, float z1, float z2);
        virtual ~SurfaceObject();

        // FUNCTIONS

         // check if the direction of the ray is parallel to the plan
        bool isParallel(const Ray* ray) const;
        // return the intersection point between a ray and a plane. If there is not, the field isIntersecting is false
        Intersection* getIntersection(const Ray* const ray) const;
        const float getBRDF();

                // here are the 6 constraints value of the wall:
        const float x1,x2;
        const float y1, y2;
        const float z1, z2;

    protected:
        glm::vec3 normal;
        float height;
        float width;

    private:
};

#endif // SURFACEOBJECT_H
