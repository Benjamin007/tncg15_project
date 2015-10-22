#ifndef ROOM_H
#include <vector>
#include "LightSource.h"
#include "Object.h"
#define ROOM_H





class Room
{
    public:
        Room(std::vector<LightSource*> light_container, std::vector<Object*> object_container);
        virtual ~Room();
    protected:
        std::vector<LightSource*> light_container;
        std::vector<Object*> object_container;
    private:
};

#endif // ROOM_H
