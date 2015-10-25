#include "TestCase.h"
#include "TestCaseIntersection.h"
#include "TestCaseIntersection2.h"
#include "TestCaseRayTracer.h"
#include "TestCaseRayShadowRay.h"

#define NEAR 20




int main()
{

    TestCase *intersectionTest = new TestCaseIntersection();
    TestCase *intersectionTest2 = new TestCaseIntersection2();
    TestCase *raytracerTest = new TestCaseRayTracer();
    TestCase* shadowRayTest = new TestCaseRayShadowRay();
    //intersectionTest->run();
    //intersectionTest2->run();
    //raytracerTest->run();
    shadowRayTest->run();
    return 0;

}
