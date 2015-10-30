#include "TestCaseCube.h"

TestCaseCube::TestCaseCube()
{
    //ctor
}

TestCaseCube::~TestCaseCube()
{
    //dtor
}

void TestCaseCube::run() {
    this->init();
    glm::vec3 origin = glm::vec3(10.0, 0.0, -250);
    glm::vec3 direction = glm::vec3(5.0, 5.0, -250) - origin; // directed toward the center of the cube
    Ray* rayCube = new Ray(origin, direction);
    Intersection* cubeIntersection = new Intersection();
    cubeIntersection = this->room->findIntersection(rayCube);
    if(cubeIntersection->getIsIntersecting()){
        std::cout << "The point of intersection between the ray and the object " << cubeIntersection->getIdObject() << " is\n"
        << cubeIntersection->getPoint().x << " " << cubeIntersection->getPoint().y << " " << cubeIntersection->getPoint().z << std::endl;
        std::cout << cubeIntersection->getColor().x << " " << cubeIntersection->getColor().y << " " << cubeIntersection->getColor().z << " \n";
    }
    else{
        std::cout << "No intersection between the cube and the ray :-/\n";
    }

}
