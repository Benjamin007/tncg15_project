#include "TestCase.h"
#include "TestCaseIntersection.h"
#include "TestCaseIntersection2.h"

#define NEAR 20




int main()
{

    TestCase *intersectionTest = new TestCaseIntersection();
    TestCase *intersectionTest2 = new TestCaseIntersection2();

    //intersectionTest->run();
    intersectionTest2->run();
    return 0;

}
