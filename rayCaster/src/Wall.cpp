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
    this->x1 = 0;
    this->x2 = 0;
    this->y1 = 0;
    this->y2 = 0;
    this->z1 = 0;
    this->z2 = 0;
    rho = 0.8;
    BRDF = rho/M_PI;
}

Wall::Wall(int* id, glm::vec3 pos, glm::vec3 norm, float h, float w, float x1, float x2, float y1, float y2, float z1, float z2):Object(id){
    position = pos;
    normal = norm;
    height = h;
    width = w;
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->z1 = z1;
    this->z2 = z2;
    rho = 0.8;
    BRDF = rho/M_PI;
}

Wall::~Wall()
{
    //dtor
}


bool Wall::isParallel(Ray* ray) const{
    if (dot(ray->getDirection(), normal) == 0){
    return true;
    }
    return false;
}

float Wall::getBRDF() const{
    return BRDF;
}

//void Wall::setBrdf(float brdf){
//    this->BRDF = brdf;
//}


Intersection* Wall::getIntersection(Ray* ray) const{

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
    float d = -normal.x * position.x - normal.y * position.y - normal.z * position.z;

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
    if((newPoint.x < x1 || newPoint.x > x2) || (newPoint.y < y1 || newPoint.y > y2) || (newPoint.z < z1 || newPoint.z > z2)){
        t = 0;
        inter->setIsIntersecting(false);
    }

    inter->set_t(t);
    inter->setBRDF(this->getBRDF());

    return inter;

    //glm::vec3 intersection = o + t * dir;
    //return intersection;
}
