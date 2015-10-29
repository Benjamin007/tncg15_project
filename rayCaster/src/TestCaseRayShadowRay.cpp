#include "TestCaseRayShadowRay.h"
#include "AreaLight.h"
#include "glm/glm/glm.hpp"
//#include "glm/glm/glm.hpp"


TestCaseRayShadowRay::TestCaseRayShadowRay()
{
    //ctor
}

TestCaseRayShadowRay::~TestCaseRayShadowRay()
{
    //dtor
}

void TestCaseRayShadowRay::run(){
    std::cout << "RayShadowRay test cases running...\n";
    std::cout << "Running case 2\n";
    this->testCase1();
    std::cout << "Running case 2\n";
    this->testCase2();

}

void TestCaseRayShadowRay::testCase1() {
        this->init();
    //glm::vec3 =((AreaLight)this->room->getLightContainer().at(0))->
    AreaLight* light = ((AreaLight*)this->room->getLightContainer().at(0));
    for(int i = 0; i < 4; i++){
        glm::vec3 randomPos = light->getRandomPoint();
        std::cout << "checking if x is proper...";
        if((light->x1 < randomPos.x) && (randomPos.x < light->x2)) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
        }

        std::cout << "checking if y is proper...";
        if((light->y1 < randomPos.y) && (randomPos.y < light->y2)) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
        }

        std::cout << "checking if z is proper...";
        if((light->z1 < randomPos.z) && (randomPos.z < light->z2)) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
            std::cout << "z1 < zvalue < z2? " << light->z1 << "<" << randomPos.z << "<" << light->z2 << std::endl << std::endl;
        }
    }
}

void TestCaseRayShadowRay::testCase2() {
    // we want to test what color we get from a random point in the room!
    std::cout << "running test case 2...";
    this->init();
    AreaLight* lightObject = dynamic_cast<AreaLight*>(this->room->getLightContainer().at(0));
    glm::vec3 lightPoint = lightObject->getRandomPoint();
    glm::vec3 origin = glm::vec3(0,0,0);
    glm::vec3 direction = normalize(lightPoint-origin);
    std::cout << "the direction of the shadow ray is " << direction.x << " " << direction.y << " " << direction.z << std::endl;
    Ray* ray = new Ray(origin, direction);
    Intersection* lightIntersect = new Intersection();
    lightIntersect = this->room->findIntersection(ray);
    //point = new glm::vec3(0,0,0);

    glm::vec3 light = this->room->calculateColor(ray);
    float length = glm::distance(light, glm::vec3(1,1,1));
    if( length > 0.01){
        std::cout << "failed..!\n";
    } else {
        std::cout << "success!\n";
    }
}

