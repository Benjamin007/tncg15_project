#include "Intersection.h"

Intersection::Intersection()
{
    //ctor
    isIntersecting = false;
    t = 0.0;
    idObject = 0;
    BRDF = 0.0;
}


Intersection::Intersection(bool isInter, float _t, int id, float brdf){
    this->isIntersecting = isInter;
    this->t = _t;
    this->idObject = id;
    this->BRDF = brdf;
}

Intersection::Intersection(const Intersection& inter){
    this->isIntersecting = inter.isIntersecting;
    this->t = inter.t;
    //idObject = new int;
    this->idObject = inter.idObject;
    this->BRDF = inter.BRDF;
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

int Intersection::getIdObject() const{
    return idObject;
}

void Intersection::setIdObject(int id){
    this->idObject = id;
}

float Intersection::getBRDF() const{
    return BRDF;
}

void Intersection::setBRDF(float brdf){
    this->BRDF = brdf;
}

float Intersection::getLe() const{
    return this->Le;
}

void Intersection::setLe(float Le){
    this->Le = Le;
}

Intersection& Intersection::operator = (const Intersection& inter){
    this->idObject = inter.idObject;
    this->isIntersecting = inter.getIsIntersecting();
    this->t = inter.get_t();

    return *this;
}

glm::vec3 Intersection::getPoint(){
    return point;
}

void Intersection::setPoint(glm::vec3 newPoint){
    this->point = newPoint;
}


