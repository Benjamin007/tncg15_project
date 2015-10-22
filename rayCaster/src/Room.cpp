#include "Room.h"



Room::Room(std::vector<LightSource*> light_container, std::vector<Object*> object_container)
{
    this->light_container = light_container;
    this->object_container = object_container;
    //ctor
}

Room::~Room()
{
    //dtor
}
