#ifndef ROOM_H
#include <vector>
#include "LightSource.h"
#include "Object.h"
#define ROOM_H

#include "Ray.h"
#include "Intersection.h"
#include <stddef.h>

class Room
{
    public:
        Room(std::vector<LightSource*> light_container, std::vector<Object*> object_container);
        virtual ~Room();

        std::vector<Object*> getObjectContainer() const;

        void addObject(Object* object);

        // return the intersection of the ray with the first object the rayon will meet in the room
        Intersection* findIntersection(Ray* ray);
    protected:
        std::vector<LightSource*> light_container;
        std::vector<Object*> object_container;
    private:
};

#endif // ROOM_H
