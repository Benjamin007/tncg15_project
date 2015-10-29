#include "Intersection.h"

Intersection::Intersection()
{
    //ctor
    isIntersecting = false;
    isLightSource = false;
    t = 0.0;
    idObject = 0;
    BRDF = 0.0;
    this->normal = glm::vec3(0,0,0);
}


Intersection::Intersection(bool isInter, float _t, int id, float brdf){ // should we add Color?
    this->isIntersecting = isInter;
    this->isLightSource = false;
    this->t = _t;
    this->idObject = id;
    this->BRDF = brdf;
    this->color = glm::vec3(0,0,0); // default color...
    this->normal = glm::vec3(0,0,0);
}

Intersection::Intersection(const Intersection& inter){
    this->isIntersecting = inter.isIntersecting;
    this->t = inter.t;
    //idObject = new int;
    this->idObject = inter.idObject;
    this->BRDF = inter.BRDF;
    this->normal = inter.normal;
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

bool Intersection::getIsLightsource() const{
    return this->isLightSource;
}

void Intersection::setIsLightsource(bool isLightSource){
    this->isLightSource = isLightSource;
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

glm::vec3 Intersection::getColor() const{
    return color;
}

void Intersection::setColor(glm::vec3 color){
    this->color = color;
}

// normal
glm::vec3 Intersection::getNormal() {
    return normal;
}
void Intersection::setNormal(glm::vec3 normal){
    this->normal = normal;
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
    this->BRDF = inter.BRDF;
    this->Le = inter.Le;
    this->isLightSource = inter.isLightSource;
    this->point = inter.getPoint();
    this->color = inter.getColor();

    return *this;
}

glm::vec3 Intersection::getPoint() const{
    return point;
}

void Intersection::setPoint(glm::vec3 newPoint){
    this->point = newPoint;
}


