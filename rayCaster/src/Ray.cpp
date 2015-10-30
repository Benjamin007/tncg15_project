#include "Ray.h"
#include <iostream>
#include <fstream>
//#include <glm>
Ray::Ray()
{
    //ctor

    origin = glm::vec3(0.0f, 0.0f, 0.0f);
    direction = glm::vec3(0.0f, 0.0f, 0.0f);
    intersection = new Intersection();
    child = NULL;
    this->depth = 0;
}

Ray::Ray(glm::vec3 o, glm::vec3 dir){
    //printToFile("+1 ");
    //std::cout << "Creating a Ray!\n";
    origin = o;
    direction = normalize(dir);
    intersection  = new Intersection();
    child = NULL;
    this->depth = 0;
}

Ray::Ray(glm::vec3 o, glm::vec3 dir, Intersection* inter){
    //printToFile("+1 ");
    //std::cout << "Creating a Ray!\n";
    origin = o;
    direction = normalize(dir);
    intersection  = inter;
    child = NULL;
}

Ray::~Ray()
{
    //std::cout << "Ray::Deleting myself! T.T\n";
    //printToFile("-1 ");
    //dtor
    delete intersection;
    //std::cout << "Ray::Deleting child!\n";
    delete child;
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

void Ray::setChild(Ray* ray) {
    this->child = ray;
}

Ray* Ray::getChild() const {
    return this->child;
}

void Ray::setDepth(int depth) {
    this->depth = depth;
}

int Ray::getDepth() const {
    return this->depth;
}


Intersection* Ray::getIntersection() const {
    return this->intersection;
}
void Ray::setIntersection(Intersection* intersection) {
    delete this->intersection;
    this->intersection = intersection;
}

void Ray::printToFile(std::string c) {
    std::ofstream myFile;
    myFile.open("ray_mem.txt", std::fstream::app);
    myFile << c;
}

