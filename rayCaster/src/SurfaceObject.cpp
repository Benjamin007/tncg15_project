#include "SurfaceObject.h"

#define EPSILON 0.1


SurfaceObject::SurfaceObject() : SurfaceObject(0, glm::vec3(0,0,0),glm::vec3(0,0,0),0,0,0,0,0,0,0,0)

{
    //SurfaceObject(0, glm::vec3(0,0,0),glm::vec3(0,0,0),0,0,0,0,0,0,0,0);
    //this->x1 = 0;
    //ctor
}

SurfaceObject::SurfaceObject(int id, glm::vec3 pos, glm::vec3 norm,
                             float h, float w, float x1, float x2,
                             float y1, float y2, float z1, float z2) : Object(id, pos), x1(x1), x2(x2), y1(y1), y2(y2), z1(z1), z2(z2)
{
    normal = norm;
    height = h;
    width = w;
    //this->x1 = x1;
    //this->x2 = x2;
    //this->y1 = y1;
    //this->y2 = y2;
    //this->z1 = z1;
    //this->z2 = z2;
    //ctor

}


SurfaceObject::~SurfaceObject()
{
    //dtor
}

const float SurfaceObject::getBRDF() {
    return Object::BRDF;
}


bool SurfaceObject::isParallel(const Ray* ray) const{
    if (dot(ray->getDirection(), normal) < pow(10, -6) && dot(ray->getDirection(), normal) > -pow(10, -6) ){
    return true;
    }
    return false;
}


Intersection* SurfaceObject::getIntersection(const Ray* const ray) const{

    Intersection* inter = new Intersection();
    inter->setIsIntersecting(!(this->isParallel(ray)));

    if(inter->getIsIntersecting() == false){
        inter->setIdObject(NULL);
        inter->set_t(0);
        inter->setBRDF(0.0);
        return inter;
    }
    inter->setIdObject(this->id);

    // we find the implicit equation of the plane: ax + by + cz + d = 0
    // a, b and c are given to us by the normal, we calculate d by using position
    float d = -normal.x * pos.x - normal.y * pos.y - normal.z * pos.z;

    // we inject the parametric equation of the ray into the implicit equation of the plane and we solve t
    float t = 0;
    glm::vec3 o = ray->getOrigin();
    glm::vec3 dir = ray->getDirection();
    t = (-d - normal.x * o.x - normal.y * o.y - normal.z * o.z ) / (normal.x * dir.x + normal.y * dir.y + normal.z * dir.z);

    // if the value is negative, the ray will intersect with a plane behind its origin, so we put t = 0 and we will not use this value
    if (t <= 0){
    t = 0;
    }
    // if the point we get is not inside the wall
    glm::vec3 newPoint = o + t * dir;
    if((newPoint.x < (x1 -EPSILON) || newPoint.x > (x2 + EPSILON))
       || (newPoint.y < (y1 - EPSILON) || newPoint.y > (y2 + EPSILON))
       || (newPoint.z < (z1-EPSILON) || newPoint.z > (z2 +EPSILON))) {
        t = 0;
        inter->setIsIntersecting(false);
    }

    inter->set_t(t);
    inter->setBRDF(this->BRDF);
    inter->setColor(this->color);
    inter->setPoint(newPoint);
    return inter;

    //glm::vec3 intersection = o + t * dir;
    //return intersection;
}
