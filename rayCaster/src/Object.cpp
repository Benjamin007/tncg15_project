#include "Object.h"
#include "Ray.h"
#include "glm/glm/glm.hpp"

Object::Object(){

}

Object::Object(int id){
    this->id = id;
}

Object::~Object()
{
    //dtor
}

// WARNING! This will return null if not an intersection
