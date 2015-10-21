#include "Ray.h"

Ray::Ray()
{
    //ctor
    origin = vec3(0.0f, 0.0f, 0.0f);
    direction = vec3(0.0f, 0.0f, 0.0f);
}

Ray::Ray(vec3 o, vec3 dir){
    origin = o;
    direction = dir;
}

Ray::~Ray()
{
    //dtor
}
