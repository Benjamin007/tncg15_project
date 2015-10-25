#include "TestCaseIntersection2.h"
#include <iostream>

TestCaseIntersection2::TestCaseIntersection2()
{
    TestCase::init();
}

TestCaseIntersection2::~TestCaseIntersection2()
{
    //dtor
}

void TestCaseIntersection2::run() {

    std::cout << "starting test case Intersection 2!\n";

    glm::vec3 origin, direction;
    origin = glm::vec3(0.0,0.0,0.0);
    direction = glm::vec3(0.0,0.0,-1.0);
    Ray *testRay = new Ray(origin, direction);
    Intersection *result = new Intersection(false, 0.0, NULL, 0.0);
    result = TestCase::room->findIntersection(testRay);

    if(result->getIsIntersecting()){
        std::cout << "found intersecting point! It should be on NORTH Wall!";
    } else {
        std::cout << "ERROR: didn't find ANY wall!\n";
        return;
    }


}
