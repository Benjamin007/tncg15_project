#ifndef WALL_H
#define WALL_H

//#include "Object.h"
#include "SurfaceObject.h"

#include "glm/glm/glm.hpp"
#include "Ray.h"
#include <stddef.h>
#include "math.h"

class Wall : public SurfaceObject
{
    public:
        //Wall();
        Wall(int id);
        Wall(int id, glm::vec3 pos, glm::vec3 norm, float h, float w, float x1, float x2, float y1, float y2, float z1, float z2);
         ~Wall();


//        void setBrdf(float brdf);

    protected:

        float rho;
        float BRDF;

    private:
};

#endif // WALL_H
