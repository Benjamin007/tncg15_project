#include "RayTracer.h"
#include <iostream>
#include <iomanip> // for set precision
#include <stdlib.h>

#include "Intersection.h"

RayTracer::RayTracer(Screen* screen, Room* room)
{
    this->screen = screen;
    this->room = room;
    this->rays = std::vector<Ray*>(0);
    //this->rays = std::vector<Ray*>(screen->getWidth()*screen->getHeight());

    this->calculateScreen();
    //ctor
}

RayTracer::RayTracer()
{

    this->screen = new Screen();
    this->room = new Room();
    this->rays = std::vector<Ray*>(0); // not used xD

    this->calculateScreen();
    //ctor
}

RayTracer::~RayTracer()
{
    //dtor
}

glm::vec3 calculateLight(Intersection* result,Ray* ray);

void RayTracer::calculateScreen() {

    std::cout << "RayTracer::calculateScreen running...\n";

    int width = this->screen->getWidth(); // the width shouldn't be uneven! ;)
    int height = this->screen->getHeight();

    glm::vec3 camera_pos, pixel_pos;

    camera_pos = glm::vec3(0,0,0);

    //int x = -width/2;
    //int y = -height/2;

    // for each pixel in screen, cast a ray into the scene! Check what color each ray get, and color the pixel with that color.

    // this is currently inefficient, but for starters, we assign rays first, then traverse again, for more readable code.
    // for each pixel in screen
    for(int x = 0; x < width;x++) {
        for (int y = 0; y < height;y++) {
            // cast a ray into the scene
            pixel_pos = this->screen->getPixelPos(x,y);
            //pixel_pos = glm::vec3(x,y,screen->getNear());
            Ray* ray = new Ray(camera_pos, glm::normalize(pixel_pos-camera_pos));
            this->screen->assignRay(x,y,ray);
        }
    }

    int* wallCounter = new int[5];

    for (int i = 0; i < 5;i++){
        wallCounter[i] = 0;
    }

    int counter = 0;

    // for each pixel in screen
    for(int x = 0; x < width;x++) {
        for (int y = 0; y < height;y++) {
            // access each ray and calculate the color!
            Ray* ray = this->screen->getRay(x,y);

            Intersection* result = this->room->findIntersection(ray);
            glm::vec3 dir = ray->getDirection();
            glm::vec3 rayPos = ray->getOrigin();
            //std::cout << "RayTracer::calculateScreen checked ray has direction:\n";
            //std::cout << "(" << dir.x << "," << dir.y << "," << dir.z << ")\n";


            if(result->getIsIntersecting()) {
                //std::cout << "RayTracer::calculateScreen got its first hit!\n";
                //TODO: THIS IS A DUMMY FUNCTION!!!
                wallCounter[result->getIdObject()-1]++;
                //glm::vec3 color = calculateLight(result, ray);
                glm::vec3 color = this->room->calculateColor(result);
                // ugly hacks, if we can't find the light source, give us the fake room!
                //std::cout << color. << " is length of color! \n\n\n";
                float length = glm::distance(glm::vec3(0,0,0),color);

                if(length < 0.0005) {
                    //std::cout << "applying fake color!\n";
                    //color = calculateLight(result, ray);
                }

                this->screen->assignColor(x,y,color);

            } else {
                std::cout << "WE DIDN'T GET A HIT! WERID AF!\n";
                std::cout << "We need to debug this part!\n";
                std::cout << "The ray is: (" << dir.x << "," << dir.y << "," << dir.z << ")!\n";
                std::cout << "pixel pos of " << x << "," << y <<  "is: (";
                pixel_pos = this->screen->getPixelPos(x,y);
                std::cout << pixel_pos.x << "," << pixel_pos.y << "," << pixel_pos.z << ")\n";
                result = this->room->findIntersection(ray);

                glm::vec3 intersectionPoint = ray->getOrigin() + ray->getDirection() * result->get_t();


                std::cout << "Intersection Point: (" << std::fixed << std::setprecision(30) << pixel_pos.x << "," << pixel_pos.y << "," << pixel_pos.z << ")\n";




            }


        }
    }

    std::cout << "we calculated with the walls this much:\n";
    std::cout << "Wall 1:" << wallCounter[0] << "\n";
    std::cout << "Wall 2:" << wallCounter[1] << "\n";
    std::cout << "Wall 3:" << wallCounter[2] << "\n";
    std::cout << "Wall 4:" << wallCounter[3] << "\n";
    std::cout << "Wall 5:" << wallCounter[4] << "\n";

}

// dummy color scheme, just get light based on Z-value and circular Y value
glm::vec3 calculateLight(Intersection* result, Ray* ray) {
    glm::vec3 interPoint = ray->getOrigin() + ray->getDirection() * result->get_t();
    //std::cout << "calculated intersection point is: (" << interPoint.x << "," << interPoint.y << "," << interPoint.z << ")\n";
    //std::cout << "they collided with wall nr: " << result->getIdObject() << "\n";
    float z_coeff, y_coeff = 0.5f;

    z_coeff = 0.5f-0.5f*((abs(200.0f+interPoint.z)/200.0f));
    y_coeff = 0.5f-0.5f*((abs(interPoint.y)/400.0f));

    float light = 0.5f * z_coeff + 0.5f * y_coeff;

    //std::cout << "calculated color is: " << light << ";\n";

    return glm::vec3(light, light, light);

}

