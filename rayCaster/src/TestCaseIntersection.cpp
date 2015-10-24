#include "TestCaseIntersection.h"

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
#include "Intersection.h"
#include "SurfaceIntegrator.h"


using namespace std;
using namespace glm;

TestCaseIntersection::TestCaseIntersection()
{
    //ctor
}

TestCaseIntersection::~TestCaseIntersection()
{
    //dtor
}

void TestCaseIntersection::init() {

}

void TestCaseIntersection::run() {


    // init containers
    vector<Object*> object_container(0);
    vector<LightSource*> light_container(0);

    int* idNorthWall = new int(4);
    Wall* northWall = new Wall(idNorthWall);
    //object_container.push_back(northWall);

    AreaLight* light1 = new AreaLight();
    light_container.push_back(light1);

    Room* room = new Room(light_container, object_container);

    std::cout << "Created THE Room!\n";

    Screen* screen = new Screen();

    RayTracer* tracer = new RayTracer(screen, room);

    std::cout << "Created the Raytracer with screen and room!\n";

    cout << "Hello world!" << endl;
    Ray* ray1 = new Ray();

    // test a ray plan intersection
    vec3 origin = glm::vec3(0.0, 0.0, 0.0);
    vec3 direction = glm::vec3(0.5,0,0);
    direction = normalize(direction); // so in the renderer, to find the intersection point we need to normalise the direction!!!
    Ray* rayIntersectionWall = new Ray(origin, direction);
    vec3 positionIntersectionWall = glm::vec3(2.0, 0.0, 0.0);
    vec3 normalIntersectionWall = glm::vec3(-1.0, 0.0, 0.0);
    float heightIntersectionWall = 5;
    float widthIntersectionWall = 5;
    float x1IntersectionWall = 2;
    float x2IntersectionWall = 2;
    float y1IntersectionWall = -2.5; // half of heightIntersectionWall
    float y2IntersectionWall = 2.5;
    float z1IntersectionWall = -2.5; // half of width
    float z2IntersectionWall = 2.5;
    int* idIntersectionWall = new int(5);
    Wall* intersectionWall = new Wall(idIntersectionWall, positionIntersectionWall, normalIntersectionWall, heightIntersectionWall, widthIntersectionWall,
        x1IntersectionWall, x2IntersectionWall, y1IntersectionWall, y2IntersectionWall, z1IntersectionWall, z2IntersectionWall);
//    vec3 intersectionPoint = vec3(0.0, 0.0, 0.0);
//    Intersection* intersectionRayWallNorth = new Intersection();
//    if(intersectionWall->isIntersecting(rayIntersectionWall)){
//        intersectionRayWallNorth = intersectionWall->getIntersection(rayIntersectionWall);
//    }
//    intersectionPoint = origin + intersectionRayWallNorth->get_t() * direction;
    //cout << "Here we have the coordinates of an intersectPoint:" << intersectionPoint.x << " " << intersectionPoint.y << " " << intersectionPoint.z << endl;

    //# collide with room.

    // test collide with room: two walls are in the room, one just behind the other. The ray should collide the two walls in Room:findIntersection and
    // then only return the intersection with the first wall encountered
    vec3 positionIntersectionWall2 = glm::vec3(6.0, 150.0, 0.0);
    vec3 normalIntersectionWall2 = glm::vec3(-1.0, 0.0, 0.0);
    float heightIntersectionWall2 = 5;
    float widthIntersectionWall2 = 5;
    // this kind of formule workd only in a particular case
    float x1IntersectionWall2 = positionIntersectionWall2.x;
    float x2IntersectionWall2 = positionIntersectionWall2.x;
    float y1IntersectionWall2 = positionIntersectionWall2.y - heightIntersectionWall2/2; // half of heightIntersectionWall
    float y2IntersectionWall2 = positionIntersectionWall2.y + heightIntersectionWall2/2;
    float z1IntersectionWall2 = positionIntersectionWall2.z - widthIntersectionWall2/2; // half of width
    float z2IntersectionWall2 = positionIntersectionWall2.z + widthIntersectionWall2/2;
    int* idIntersectionWall2 = new int(6);
    Wall* intersectionWall2 = new Wall(idIntersectionWall2, positionIntersectionWall2, normalIntersectionWall2, heightIntersectionWall2, widthIntersectionWall2,
        x1IntersectionWall2, x2IntersectionWall2, y1IntersectionWall2, y2IntersectionWall2, z1IntersectionWall2, z2IntersectionWall2);
    room->addObject(intersectionWall);
    room->addObject(intersectionWall2);

    Intersection* intersectionRayWallNorth2 = new Intersection(false, 0.0, NULL, 0.0);
    intersectionRayWallNorth2 = room->findIntersection(rayIntersectionWall);

    glm::vec3 intersectionPoint2 = origin + intersectionRayWallNorth2->get_t() * direction;

    cout << "Here we have the coordinates of an intersectPoint t x y z:" << intersectionRayWallNorth2->get_t() << " " << intersectionPoint2.x <<
    " " << intersectionPoint2.y << " " << intersectionPoint2.z << endl;

}
