#ifndef TESTCASE_H
#define TESTCASE_H
#include "Room.h"
#include "Screen.h"
#include "RayTracer.h"
#include <iostream>

class TestCase
{
    public:

        Room *room;
        Screen *screen;
        RayTracer *tracer;




        TestCase();
        virtual ~TestCase();
        virtual void init();
        virtual void run() = 0;
    protected:
    private:
};

#endif // TESTCASE_H
