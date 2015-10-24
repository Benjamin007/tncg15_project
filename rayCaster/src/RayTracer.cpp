#include "RayTracer.h"

RayTracer::RayTracer(Screen* screen, Room* room)
{
    this->screen = screen;
    this->room = room;
    this->rays = std::vector<Ray*>(screen->getWidth()*screen->getHeight());

    this->calculateScreen();
    //ctor
}

RayTracer::RayTracer()
{

    this->screen = new Screen();
    this->room = new Room;
    this->rays = std::vector<Ray*>(screen->getWidth()*screen->getHeight());

    this->calculateScreen();
    //ctor
}

RayTracer::~RayTracer()
{
    //dtor
}

void RayTracer::calculateScreen() {

    int width = this->screen->getWidth(); // the width shouldn't be uneven! ;)
    int height = this->screen->getHeight();

    glm::vec3 camera_pos, pixel_pos;

    camera_pos = glm::vec3(0,0,0);

    //int x = -width/2;
    //int y = -height/2;

    for(int x = -width/2; x < width/2;x++) {
        for (int y = -height/2; y < height/2;y++) {

            pixel_pos = glm::vec3(x,y,screen->getNear());
            Ray* ray = new Ray(camera_pos, glm::normalize(pixel_pos));

            rays.push_back(ray);


        }
    }

}
