#include "Wall.h"
#include "Ray.h"
#include "glm/glm/glm.hpp"

Wall::Wall()
{
    //ctor
}

Wall::~Wall()
{
    //dtor
}

bool Wall::isIntersecting(Ray ray) {
    return false;
}

glm::vec3 Wall::getIntersection(Ray ray) {
    return glm::vec3(0.5f);
}
