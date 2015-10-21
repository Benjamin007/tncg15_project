#include "Ray.h"
//#include <glm>
Ray::Ray()
{
    //ctor
    origin = glm::vec3(0.0f, 0.0f, 0.0f);
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
}

Ray::Ray(glm::vec3 o, glm::vec3 dir){
    o = o * o;
    origin = o;
    direction = dir;
}

Ray::~Ray()
{
    //dtor
}
