#include "TestCase.h"
#include "TestCaseIntersection.h"
#include "TestCaseIntersection2.h"
#include "TestCaseRayTracer.h"
#include "TestCaseRayShadowRay.h"
#include "TestCasePrintToFile.h"
#include "TestCaseCube.h"
#include <fstream>

#define NEAR 20




int main()
{

    std::ofstream myFile;
    myFile.open("inter_mem.txt", std::fstream::trunc);
    myFile << "";
    myFile.close();
    myFile.open("ray_mem.txt", std::fstream::trunc);
    myFile << "";
    myFile.close();




    TestCase *intersectionTest = new TestCaseIntersection();
    TestCase *intersectionTest2 = new TestCaseIntersection2();
    TestCase *raytracerTest = new TestCaseRayTracer();
    TestCase* shadowRayTest = new TestCaseRayShadowRay();
    TestCase* cubeTest = new TestCaseCube();
//    TestCase* printTest = new TestCasePrintToFile();
    //intersectionTest->run();
    //intersectionTest2->run();
    raytracerTest->run();
    //shadowRayTest->run();
    //cubeTest->run();
    //printTest.run();
    delete intersectionTest;
    delete intersectionTest2;
    delete raytracerTest;
    delete shadowRayTest;
    //delete cubeTest;

    return 0;

}
