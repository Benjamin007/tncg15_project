#include "Object.h"
#include "Ray.h"
#include "glm/glm/glm.hpp"

Object::Object(): BRDF(1.0){
    this->id = 0;
    this->pos = glm::vec3(0,0,0);

}

Object::Object(int id, glm::vec3 pos) : BRDF(1.0){
    this->id = id;
    this->pos = pos;
}

Object::~Object()
{
    //dtor
}

float const Object::getBRDF() {
    return this->BRDF;
}


// WARNING! This will return null if not an intersection
