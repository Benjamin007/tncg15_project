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

    screen->myPrint();

    RayTracer* tracer = new RayTracer(screen, room);

    std::cout << "Created the Raytracer with screen and room!\n";


    vec3 merde = glm::vec3(1,1,1);

    cout << "Hello world!" << endl;
    Ray* ray = new Ray();

    //# collide with room.


    return 0;

}
