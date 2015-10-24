#include "Ray.h"
//#include <glm>
Ray::Ray()
{
    //ctor

    origin = glm::vec3(0.0f, 0.0f, 0.0f);
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
    intersection = new Intersection();
    child = NULL;
}

Ray::Ray(glm::vec3 o, glm::vec3 dir){
    origin = o;
    direction = normalize(dir);
    intersection  = new Intersection();
    child = NULL;
}

Ray::Ray(glm::vec3 o, glm::vec3 dir, Intersection* inter){
    origin = o;
    direction = normalize(dir);
    intersection  = inter;
    child = NULL;
}

Ray::~Ray()
{
    //dtor
    delete intersection;
}

glm::vec3 Ray::getOrigin() const{
    return origin;
}

glm::vec3 Ray::getDirection() const{
    return direction;
}

glm::vec3 Ray::getColor() {   // recursive function that will calculate total color, whop whop!
    if(this->child == NULL) {
        return this->color;
    }
}
glm::vec3 Ray::setColor(glm::vec3 color) {
    this->color = color;
};

