#include "AreaLight.h"

AreaLight::AreaLight():SurfaceObject()
{
    //ctor
}

AreaLight::AreaLight(int id, glm::vec3 pos, float Le, glm::vec3 normal, float h, float w,
                        float x1, float x2, float y1, float y2, float z1, float z2)
                        : SurfaceObject(id,pos,normal,h,w,x1,x2,y1,y2,z1,z2)
{
    this->Le = Le;
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

float AreaLight::getLe() const {
    return this->Le;
}
