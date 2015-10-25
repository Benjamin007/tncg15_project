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
    /* initialize random seed: */
    srand (time(NULL));
}

AreaLight::~AreaLight()
{
    //dtor
}

float myRand(){

  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

glm::vec3 AreaLight::getRandomPoint(){
    float xRand = x1 + myRand() * (x2 - x1); // compute a random number between x1 and x2
    float yRand = y1 + myRand() * (y2 - y1);
    float zRand = z1 + myRand() * (z2 - z1);
    glm::vec3 vec = glm::vec3(xRand, yRand, zRand);
    return vec;
}
