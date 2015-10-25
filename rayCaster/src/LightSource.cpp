#include "LightSource.h"

LightSource::LightSource()
{
    //ctor
    Le = 0;
}

LightSource::LightSource(float Le, glm::vec3 pos){
    this->Le = Le;
    this->pos = pos;
}

LightSource::~LightSource()
{
    //dtor
}

float LightSource::getLe() const{
    return Le;
}

glm::vec3 LightSource::getPosition(){
    return this->pos;
}
