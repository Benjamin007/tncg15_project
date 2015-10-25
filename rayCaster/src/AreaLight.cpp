#include "AreaLight.h"

AreaLight::AreaLight():x1(0), x2(0), y1(0), y2(0), z1(0), z2(0)
{
    //ctor
}

AreaLight::AreaLight(glm::vec3 pos, float Le, glm::vec3 normal,
                        float x1, float x2, float y1, float y2, float z1, float z2)
                        : LightSource(Le, pos), normal(normal), x1(x1), x2(x2), y1(y1), y2(y2), z1(z1), z2(z2)
{
    //ctor
}

AreaLight::~AreaLight()
{
    //dtor
}
