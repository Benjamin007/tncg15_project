#include "TestCase.h"
#include "TestCaseIntersection.h"
#include "TestCaseIntersection2.h"
#include "TestCaseRayTracer.h"
#include "TestCaseRayShadowRay.h"
#include "TestCasePrintToFile.h"
#include "TestCaseCube.h"

#define NEAR 20




int main()
{

    TestCase *intersectionTest = new TestCaseIntersection();
    TestCase *intersectionTest2 = new TestCaseIntersection2();
    TestCase *raytracerTest = new TestCaseRayTracer();
    TestCase* shadowRayTest = new TestCaseRayShadowRay();
    TestCase* cubeTest = new TestCaseCube();
//    TestCase* printTest = new TestCasePrintToFile();
    //intersectionTest->run();
    //intersectionTest2->run();
    //raytracerTest->run();
    //shadowRayTest->run();
    cubeTest->run();
    //printTest.run();
    return 0;

}
