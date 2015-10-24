#include "LightSource.h"

LightSource::LightSource()
{
    //ctor
    Le = 0;
}

LightSource::LightSource(float Le){
    this->Le = Le;
}

LightSource::~LightSource()
{
    //dtor
}

float LightSource::getLe() const{
    return Le;
}
