#ifndef AREALIGHT_H
#define AREALIGHT_H

#include <SurfaceObject.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class AreaLight : public SurfaceObject
{
    public:
        AreaLight();
        AreaLight(int id, glm::vec3 pos, float Le, glm::vec3 normal, float h, float w,
                        float x1, float x2, float y1, float y2, float z1, float z2);
        virtual ~AreaLight();
        //float const x1, x2;
        //float const y1, y2;
        //float const z1, z2;

        glm::vec3 getRandomPoint();
        glm::vec3 getCenterPoint();
        float getLe() const;

    protected:

    float Le;

    private:
};

#endif // AREALIGHT_H
