#include "TestCase.h"
#include "TestCaseIntersection.h"
#include "TestCaseIntersection2.h"
#include "TestCaseRayTracer.h"

#define NEAR 20




int main()
{

    TestCase *intersectionTest = new TestCaseIntersection();
    TestCase *intersectionTest2 = new TestCaseIntersection2();
    TestCase *raytracerTest = new TestCaseRayTracer();
    //intersectionTest->run();
    //intersectionTest2->run();
    raytracerTest->run();
    return 0;

}
