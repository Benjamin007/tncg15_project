#include "Room.h"
#include "Wall.h"
#include <iostream>
#include "glm/glm/glm.hpp"
#include "AreaLight.h"

#define NBSHADOWRAY 3
#define EPSILON2 0.01

Room::Room(std::vector<Object*> light_container, std::vector<Object*> object_container)
{
    this->light_container = light_container;
    this->object_container = object_container;
    //ctor
}

Room::Room() {
    // init containers
    std::vector<Object*> object_container(0);
    std::vector<Object*> light_container(0);

    Wall *roof, *floor, *north, *south, *east, *west;

    glm::vec3 roofPos, floorPos, northPos, /* southPos ,*/ eastPos, westPos;
    glm::vec3 roofNorm, floorNorm, northNorm, /* southNorm ,*/ eastNorm, westNorm;

    float roomXMin, roomXMid, roomXMax;
    float roomYMin, roomYMid, roomYMax;
    float roomZMin, roomZMid, roomZMax;

    int* roomID1 = new int(1);
    int* roomID2 = new int(2);
    int* roomID3 = new int(3);
    int* roomID4 = new int(4);
    int* roomID5 = new int(5);

    // global room coordinates
    roomXMin = -200;
    roomXMid = 0;
    roomXMax = 200;
    roomYMin = -100;
    roomYMid = 0;
    roomYMax = 100;
    roomZMin = -500;       //, defined as closest to screen NEAR plane defined as z = -20;
    roomZMid = -300;
    roomZMax = -100;

    // wall positions

    roofPos = glm::vec3(roomXMid, roomYMax, roomZMid);
    floorPos = glm::vec3(roomXMid, roomYMin, roomZMid);
    northPos = glm::vec3(roomXMid, roomYMid, roomZMin);
    //southPos = vec3(roomXMid, roomYMid, roomZMax);
    eastPos = glm::vec3(roomXMax, roomYMid, roomZMid);
    westPos = glm::vec3(roomXMin, roomYMid, roomZMid);

    // wall normals, axel bound walls

    roofNorm = glm::vec3(0,-1,0);
    floorNorm = glm::vec3(0,1,0);
    northNorm = glm::vec3(0,0,1);
    westNorm = glm::vec3(1,0,0);
    eastNorm = glm::vec3(-1,0,0);




//Wall::Wall(int* id, glm::vec3 pos, glm::vec3 norm, float h, float w, float x1, float x2, float y1, float y2, float z1, float z2):Object(id){


    roof    = new Wall(1, roofPos, roofNorm,
                       NULL, NULL, roomXMin, roomXMax, roomYMax, roomYMax,roomZMin, roomZMax);
    floor   = new Wall(2, floorPos, floorNorm,
                       NULL, NULL, roomXMin, roomXMax, roomYMin, roomYMin,roomZMin, roomZMax);
    north   = new Wall(3, northPos, northNorm,
                       NULL, NULL, roomXMin, roomXMax, roomYMin, roomYMax,roomZMin, roomZMin);
    west    = new Wall(4, westPos, westNorm,
                       NULL, NULL, roomXMin, roomXMin, roomYMin, roomYMax,roomZMin, roomZMax);
    east    = new Wall(5, eastPos, eastNorm,
                       NULL, NULL, roomXMax, roomXMax, roomYMin, roomYMax,roomZMin, roomZMax);


    this->object_container.push_back(roof);
    this->object_container.push_back(floor);
    this->object_container.push_back(north);
    this->object_container.push_back(east);
    this->object_container.push_back(west);

//      AreaLight(glm::vec3 pos, float Le, glm::vec3 normal,
//                        float x1, float x2, float y1, float y2, float z1, float z2);
//        virtual ~AreaLight();
//        float const x1, x2;
//        float const y1, y2;
//        float const z1, z2;

    AreaLight *light = new AreaLight(1,roofPos,1.0f, roofNorm,100,100,
                        -50,50,-50,50,roomZMin/3,roomZMax/3);
    //AreaLight light = new AreaLight();

    this->light_container.push_back(light);



}

Room::~Room()
{
    //dtor
}

std::vector<Object*> Room::getLightContainer() const{
    return this->light_container;
}

std::vector<Object*> Room::getObjectContainer() const{
    return this->object_container;
}

void Room::addObject(Object* object){
    object_container.push_back(object);
}

Intersection* Room::findIntersection(const Ray* ray){
    Intersection* intersection = new Intersection(false, 0, NULL, 0);
    // we consider every object in the scene

    // Later, check for cubes first.

    // first check for lights.

    //std::cout << "finding intersection...";

    //std::cout << "looking through light sources...\n";
    intersection = findIntersection(ray, light_container);
    // if we found light, return the point (it can't intersect with a wall in front of the light)
    intersection->setIsLightsource(true);
    if(intersection->getIsIntersecting()) {
        std::cout << "findIntersection: FOUND A LIGHT SOURCE!!!!!111!!!11!!!one!!!\n";
        return intersection;
    } // else, check for intersection with walls.


    //std::cout << "FAIL!\n looking through walls...";
    intersection = findIntersection(ray, object_container);
    intersection->setIsLightsource(false);

    std::cout << "returning function...\n";
    // return this regardless!
    return intersection;
}


Intersection* Room::findIntersection(const Ray* ray, std::vector<Object*> container) {

    Intersection* intersection = new Intersection(false, 0, NULL, 0);
    std::vector<Object*>::iterator itObject;
    Intersection* tmpInter = new Intersection(false, 0, NULL, 0);
    // we consider every object in the scene

    //for(int i = 0; i < object_container.size(); i++){
    for(itObject = container.begin(); itObject != container.end(); ++itObject){
        //std::cerr << "Wall is:" << (*itObject)->getObjectID();
        tmpInter = (*itObject)->getIntersection(ray);
        //tmpInter = object_container.at(i)->getIntersection(ray);
        if (tmpInter->getIsIntersecting()){
            // the ray collides with this object
            if((tmpInter->get_t() > 0.0 && tmpInter->get_t() < intersection->get_t()) || (tmpInter->get_t() > 0.0 && intersection->get_t() == 0.0)){
                // the object we are colliding with is nearer that the others one, or it is the first
                intersection = tmpInter;
            }
        }
    }
    return intersection;

}


bool comparePoints(glm::vec3 v1, glm::vec3 v2){
    float diff = glm::distance(v2, v1);
    return (diff < EPSILON2);
}

glm::vec3 Room::calculateLight(Intersection* intersection){
    glm::vec3 pos = intersection->getPoint();
    glm::vec3 radiance;

    if(intersection->getIsLightsource()) {
        radiance = radiance * intersection->getLe();
        std::cout << "calculateLight: we found a lightsource! returning the Le of ";
        std::cout << intersection->getLe() << "\n";
    }


    /*
    std::vector<Object*>::iterator itLight;
    for(itLight = light_container.begin(); itLight != light_container.end(); ++itLight){
        AreaLight* tmpLight = (AreaLight*)(*itLight);
        glm::vec3 samplingLightPoint = tmpLight->getRandomPoint();
        for(int i = 0; i < NBSHADOWRAY; i++){
            Ray* shadowRay = new Ray(pos, samplingLightPoint - pos);
            Intersection* inter = this->findIntersection(shadowRay);
            if(comparePoints(inter->getPoint(), samplingLightPoint)){
                radiance += tmpLight->getLe()/NBSHADOWRAY;
            }
        }
    }
    */
    return radiance;
}


