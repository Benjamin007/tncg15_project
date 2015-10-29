#ifndef ROOM_H
#include <vector>
#include "glm/glm/glm.hpp"
#include "AreaLight.h"
#include "Wall.h"
#define ROOM_H

#include "Ray.h"
#include "Intersection.h"
#include <stddef.h>
#include "Room.h"
#include "Cube.h"
#include "CONSTANTS.h"

class Room
{
    public:
        Room(std::vector<Object*> light_container, std::vector<Object*> object_container, std::vector<Object*> cube_container);
        Room(); // default constructer that creates 5 walls and a light.
        virtual ~Room();

        std::vector<Object*> getObjectContainer() const;
        std::vector<Object*> getLightContainer() const;
        std::vector<Object*> getCubeContainer() const;

        void addObject(Object* object);

        // return the intersection of the ray with the first object the rayon will meet in the room
        Intersection* findIntersection(Ray* ray);

        glm::vec3 calculateColor(Ray* ray);
    protected:
        std::vector<Object*> light_container;
        std::vector<Object*> object_container;
        std::vector<Object*> cube_container;
    private:
        Intersection* findIntersection(const Ray* ray, std::vector<Object*> container);
};

#endif // ROOM_H
