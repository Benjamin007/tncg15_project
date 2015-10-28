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
        Room(std::vector<Object*> light_container, std::vector<Object*> object_container);
        Room(); // default constructer that creates 5 walls and a light.
        virtual ~Room();

        std::vector<Object*> getObjectContainer() const;

        std::vector<Object*> getLightContainer() const;

        void addObject(Object* object);

        // return the intersection of the ray with the first object the rayon will meet in the room
        Intersection* findIntersection(const Ray* ray);

        glm::vec3 calculateColor(Intersection* intersection);
    protected:
        std::vector<Object*> light_container;
        std::vector<Object*> object_container;
    private:
        Intersection* findIntersection(const Ray* ray, std::vector<Object*> container);
};

#endif // ROOM_H
