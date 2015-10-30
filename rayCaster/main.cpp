#include "TestCase.h"
#include "TestCaseIntersection.h"
#include "TestCaseIntersection2.h"
#include "TestCaseRayTracer.h"
#include "TestCaseRayShadowRay.h"
#include "TestCasePrintToFile.h"
#include "TestCaseCube.h"
#include <time.h>
#include <fstream>

#define NEAR 20




int main()
{

    std::ofstream myFile;
    /*
    myFile.open("inter_mem.txt", std::fstream::trunc);
    myFile << "";
    myFile.close();
    myFile.open("ray_mem.txt", std::fstream::trunc);
    myFile << "";
    myFile.close();
    */

    time_t start_time, end_time;

    time(&start_time);


    //TestCase *intersectionTest = new TestCaseIntersection();
    //TestCase *intersectionTest2 = new TestCaseIntersection2();
    TestCase *raytracerTest = new TestCaseRayTracer();
    //TestCase* shadowRayTest = new TestCaseRayShadowRay();
    //TestCase* cubeTest = new TestCaseCube();
//    TestCase* printTest = new TestCasePrintToFile();
    //intersectionTest->run();
    //intersectionTest2->run();
    raytracerTest->run();

    time(&end_time);

    std::cout << "time to render: " << difftime(end_time, start_time) << " seconds!\n";
    std::cout << "Pixels: " << HEIGHT << " x " << WIDTH << "\n";
    std::cout << "Bounces: " << MAXBOUNCES << ", prob: " << RUSSIAN_P << "\n";
    std::cout << "Sampling Rate: " << SUPER_SAMPLING_NUMBER << "\n";
    std::cout << "Shadow Rays: " << NBSHADOWRAY << "\n";
    std::cout << "Importance: DIRECT - " << DIRECT_CONSTANT << ", INDIRECT - " << INDIRECT_CONSTANT << "\n";
    std::cout << "BRDF-constant: " << BRDF_CONSTANT << "\n";



    //shadowRayTest->run();
    //cubeTest->run();
    //printTest.run();
    //delete intersectionTest;
    //delete intersectionTest2;
    delete raytracerTest;
    //delete shadowRayTest;
    //delete cubeTest;


    // ugly hax to make program not close on completion.
     std::cout << "Type a number and press enter to exit the program:   ";
     int r;
     std::cin>>r;   // wait until a number is given and enter is pressed

    return 0;

}
