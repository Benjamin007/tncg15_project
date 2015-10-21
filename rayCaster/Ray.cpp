#include "Ray.h"

Ray::Ray()
{
    //ctor
    origin = glm::vec3(0.0, 0.0, 0.0);
    direction = glm::vec3(0.0, 0.0, 0.0);
}

Ray::Ray(glm::vec3 o, glm::vec3 dir){
    origin = o;
    direction = dir;
}

Ray::~Ray()
{
    //dtor
}
