#include "TestCase.h"
#include "Room.h"

TestCase::TestCase()
{
    //this->init();
    //ctor
}

TestCase::~TestCase()
{
    //dtor
}

void TestCase::init() {

    this->screen = new Screen();
    this->room = new Room();
    this->tracer = new RayTracer(this->screen, this->room);

}
