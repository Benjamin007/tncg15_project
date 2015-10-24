#include "TestCaseRayTracer.h"

TestCaseRayTracer::TestCaseRayTracer()
{
    //ctor
}

TestCaseRayTracer::~TestCaseRayTracer()
{
    //dtor
}

void TestCaseRayTracer::run() {
    TestCase::init();
    TestCase::screen->printToFile("screen_matrix.txt","screen_matrix_dim.txt");

}
