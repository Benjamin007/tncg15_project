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
//    delete screen;
//    delete room;
//    delete tracer;
}

void TestCase::init() {

    this->screen = new Screen();
    this->room = new Room();
    this->tracer = new RayTracer(this->screen, this->room);

}

void TestCase::run(){

}
