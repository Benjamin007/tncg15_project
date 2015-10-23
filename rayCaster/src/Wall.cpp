#include "Wall.h"
#include "Ray.h"
#include "glm/glm/glm.hpp"

Wall::Wall(int* id):Object(id)
{
    //ctor
    glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
    position = pos;
    glm::vec3 norm = glm::vec3(0.0, 0.0, 0.0);
    normal = norm;
    height = 0;
    width = 0;
}

Wall::Wall(int* id, glm::vec3 pos, glm::vec3 norm, float h, float w):Object(id){
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


Intersection* Wall::getIntersection(Ray* ray) const{

    Intersection* inter = new Intersection();
    inter->setIsIntersecting(this->isIntersecting(ray));

    if(inter->getIsIntersecting() == false){
        inter->setIdObject(NULL);
        inter->set_t(0);
        return inter;
    }
    inter->setIdObject(this->id);

    // we find the implicit equation of the plane: ax + by + cz + d = 0
    // a, b and c are given to us by the normal, we calculate d by using position
    float d = -normal.x * position.x - normal.y * position.y - normal.z * position.z;

    // we inject the parametric equation of the ray into the implicit equation of the plane and we solve t
    float t = 0;
    glm::vec3 o = ray->getOrigin();
    glm::vec3 dir = ray->getDirection();
    t = (-d - normal.x * o.x - normal.y * o.y - normal.z * o.z ) / (normal.x * dir.x + normal.y * dir.y + normal.z * dir.z);

    // if the value is negative, the ray will intersect with a plane behind its origin, so we put t = 0 and we will not use this value
    if (t < 0){
    t = 0;
    }

    inter->set_t(t);

    return inter;

    //glm::vec3 intersection = o + t * dir;
    //return intersection;
}
