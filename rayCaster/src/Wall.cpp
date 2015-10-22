#include "Wall.h"
#include "Ray.h"
#include "glm/glm/glm.hpp"

Wall::Wall()
{
    //ctor
    glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
    position = pos;
    glm::vec3 norm = glm::vec3(0.0, 0.0, 0.0);
    normal = norm;
    height = 0;
    width = 0;
}

Wall::Wall(glm::vec3 pos, glm::vec3 norm, float h, float w){
    position = pos;
    normal = norm;
    height = h;
    width = w;
}

Wall::~Wall()
{
    //dtor
}


bool Wall::isIntersecting(Ray* ray) const{
    if (dot(ray->getDirection(), normal) == 0){
    return false;
    }
    return true;
}


glm::vec3 Wall::getIntersection(Ray* ray) const{
    // we find the implicit equation of the plan: ax + by + cz + d = 0
    // a, b and c are given to us by the normal, we calculate d by using position
    float d = -normal.x * position.x - normal.y * position.y - normal.z * position.z;

    // we inject the parametric equation of the ray into the implicit equation of the plan and we solve t
    float t;
    glm::vec3 o = ray->getOrigin();
    glm::vec3 dir = ray->getDirection();
    t = (-d - normal.x * o.x - normal.y * o.y - normal.z * o.z ) / (normal.x * dir.x + normal.y * dir.y + normal.z * dir.z);

    // if the value is negative, the ray will intersect with a plan behind its origin, so we put t = 0 and we will not use this value
    if (t < 0){
    t = 0;
    }

    glm::vec3 intersection = o + t * dir;
    return intersection;
}
