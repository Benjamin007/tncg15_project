#ifndef RAYTRACER_H

#include "Screen.h"
#include "Room.h"
#include "Ray.h"
#include "Intersection.h"

#define RAYTRACER_H

class RayTracer
{
    public:
        RayTracer(Screen* screen, Room* room);
        RayTracer();
        void calculateScreen();
        virtual ~RayTracer();

    protected:
        Screen* screen;
        Room* room;
        std::vector<Ray*> rays;
    private:
};

#endif // RAYTRACER_H
