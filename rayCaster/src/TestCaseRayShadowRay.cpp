#include "TestCaseRayShadowRay.h"
#include "AreaLight.h"
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
    this->init();
    //glm::vec3 =((AreaLight)this->room->getLightContainer().at(0))->
    AreaLight* light = ((AreaLight*)this->room->getLightContainer().at(0));
    for(int i = 0; i < 4; i++){
        glm::vec3 randomPos = light->getRandomPoint();
        std::cout << "x1 < xvalue < x2?" << " " << light->x1 << "<" << randomPos.x << "<" << light->x2 << std::endl;
        std::cout << "y1 < xvalue < y2? " << light->y1 << "<" << randomPos.y << "<" << light->y2 << std::endl;
        std::cout << "z1 < xvalue < z2? " << light->z1 << "<" << randomPos.z << "<" << light->z2 << std::endl << std::endl;
    }
}
