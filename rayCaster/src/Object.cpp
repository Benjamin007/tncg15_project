#include "Object.h"

Object::Object(): BRDF(1.0){
    this->id = 0;
    this->pos = glm::vec3(0,0,0);

    this->color = glm::vec3(0.6,0.6,0.6);

}

Object::Object(int id, glm::vec3 pos) : BRDF(1.0){
    this->id = id;
    this->pos = pos;
    this->color = glm::vec3(0.6,0.6,0.6);
}

Object::~Object()
{
    //dtor
}

float const Object::getBRDF() {
    return this->BRDF;
}

glm::vec3 const Object::getColor() {
    return this->color;
}
void Object::setColor(glm::vec3 color) {
    this->color = color;
}


// WARNING! This will return null if not an intersection
