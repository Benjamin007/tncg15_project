#include <iostream>
#include <vector>
#include "RayTracer.h"
#include "Ray.h"

#include "Object.h"
#include "Wall.h"
#include "LightSource.h"
#include "AreaLight.h"

#include "Room.h"
#include "Screen.h"
#include "glm/glm/vec3.hpp"

#define NEAR 20

using namespace std;
using namespace glm;

int main()
{

    // init containers
    vector<Object*> object_container(1);
    vector<LightSource*> light_container(1);

    Wall* northWall = new Wall();
    object_container.push_back(northWall);

    AreaLight* light1 = new AreaLight();
    light_container.push_back(light1);

    Room* room = new Room(light_container, object_container);

    std::cout << "Created THE Room!\n";

    Screen* screen = new Screen();

    //screen->myPrint();

    RayTracer* tracer = new RayTracer(screen, room);

    std::cout << "Created the Raytracer with screen and room!\n";

    cout << "Hello world!" << endl;
    Ray* ray1 = new Ray();

    // test a ray plan intersection
    vec3 origin = glm::vec3(0.0, 0.0, 0.0);
    vec3 direction = glm::vec3(1,0,0);
    Ray* rayIntersectionWall = new Ray(origin, direction);
    vec3 positionIntersectionWall = glm::vec3(2.0, 0.0, 0.0);
    vec3 normalIntersectionWall = glm::vec3(-1.0, 0.0, 0.0);
    float heightIntersectionWall = 5;
    float widthIntersectionWall = 5;
    Wall* intersectionWall = new Wall(positionIntersectionWall, normalIntersectionWall, heightIntersectionWall, widthIntersectionWall);
    vec3 intersectionPoint = vec3(0.0, 0.0, 0.0);
    if(intersectionWall->isIntersecting(rayIntersectionWall)){
        intersectionPoint = intersectionWall->getIntersection(rayIntersectionWall);
    }

    cout << "Here we have the coordinates of an intersectPoint:" << intersectionPoint.x << " " << intersectionPoint.y << " " << intersectionPoint.z << endl;

    //# collide with room.


    return 0;

}
