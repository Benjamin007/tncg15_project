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

/*
TestCaseIntersection2::init() {
    TestCase::init();

}
*/

void TestCaseIntersection2::run() {

    std::cout << "starting test case Intersection 2!\n";

    //glm::vec3 origin, direction;

    Ray *testRay;

    Intersection *result;

    for(int x = 0; x < 1; x++) {
        for (int y = 0;y < 1;y++) {
            std::cout << "currntly x, y is: " << x << ", " << y << "\n";

            glm::vec3 origin = glm::vec3(0.0,0.0,0.0);
            //glm::vec3 direction = glm::vec3(((2-x),(2-y),-1.0);
            glm::vec3 direction = glm::vec3(2,0,-1.0);
            testRay = new Ray(origin, direction);
            result = new Intersection();
            result = TestCase::room->findIntersection(testRay);


            std::cout << "Current Vector is: ("
            << testRay->getDirection().x << ","
            << testRay->getDirection().y << ","
            << testRay->getDirection().z << ")\n";

            if(result->getIsIntersecting()){
                std::cout << "found intersecting point! It should be on NORTH Wall! checking...";
                std::cout << "\n idObject is: " << (result->getIdObject()) << "\n";
                if(result->getIdObject() == 3) {
                    std::cout << "SUCCESS!\n";
                } else {
                    std::cout << "FAIL!\n";
                }

            } else {
                std::cout << "ERROR: didn't find ANY wall!\n";
            }

        }
    }





}
