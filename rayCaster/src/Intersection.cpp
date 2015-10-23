#include "Intersection.h"

Intersection::Intersection()
{
    //ctor
    isIntersecting = false;
    t = 0.0;
    idObject = new int(0);
}


Intersection::Intersection(bool isInter, float _t, int* id){
    this->isIntersecting = isInter;
    this->t = _t;
    this->idObject = id;
}

Intersection::Intersection(const Intersection& inter){
    this->isIntersecting = inter.isIntersecting;
    this->t = inter.t;
    idObject = new int;
    *idObject = *(inter.idObject);
}

Intersection::~Intersection()
{
    //dtor
}

bool Intersection::getIsIntersecting() const{
    return this->isIntersecting;
}

void Intersection::setIsIntersecting(bool boolInter){
    this->isIntersecting = boolInter;
}

float Intersection::get_t() const{
    return t;
}

void Intersection::set_t(float _t){
    this->t = _t;
}

int* Intersection::getIdObject() const{
    return idObject;
}

void Intersection::setIdObject(int* id){
    this->idObject = id;
}

Intersection& Intersection::operator = (const Intersection& inter){
    *(this->idObject) = *(inter.idObject);
    this->isIntersecting = inter.getIsIntersecting();
    this->t = inter.get_t();

    return *this;
}

