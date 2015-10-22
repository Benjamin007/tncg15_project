#ifndef RAYTRACER_H

#include "Screen.h"
#include "Room.h"

#define RAYTRACER_H



class RayTracer
{
    public:
        RayTracer(Screen* screen, Room* room);
        virtual ~RayTracer();
    protected:
        Screen* screen;
        Room* room;
    private:
};

#endif // RAYTRACER_H
