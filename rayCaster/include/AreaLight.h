#ifndef AREALIGHT_H
#define AREALIGHT_H

#include <LightSource.h>


class AreaLight : public LightSource
{
    public:
        AreaLight();
        AreaLight(glm::vec3 pos, float Le, glm::vec3 normal,
                        float x1, float x2, float y1, float y2, float z1, float z2);
        virtual ~AreaLight();
        float const x1, x2;
        float const y1, y2;
        float const z1, z2;

    protected:

    glm::vec3 normal;

    private:
};

#endif // AREALIGHT_H
