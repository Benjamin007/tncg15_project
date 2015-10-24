#ifndef TESTCASEINTERSECTION_H
#define TESTCASEINTERSECTION_H

#include <TestCase.h>


class TestCaseIntersection : public TestCase
{
    public:
        TestCaseIntersection();
        virtual ~TestCaseIntersection();
        virtual void run();
        virtual void init();
    protected:
    private:
};

#endif // TESTCASEINTERSECTION_H
