#include "TestCaseRayShadowRay.h"
#include "AreaLight.h"
#include "glm/glm/glm.hpp"
//#include "glm/glm/glm.hpp"
#include <iostream>

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
        if(light->x1 < randomPos.x < light->x2) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
        }

        std::cout << "checking if y is proper...";
        if(light->y1 < randomPos.y < light->y2) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
        }

        std::cout << "checking if x is proper...";
        if(light->z1 < randomPos.z < light->z2) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
        }
    }
}

void TestCaseRayShadowRay::testCase2() {
    // we want to test what color we get from a random point in the room!

    this->init();
    glm::vec3 point;
    //point = new glm::vec3(0,0,0);

    glm::vec3 light = this->room->calculateLight(point);

    int div = 5;


}

