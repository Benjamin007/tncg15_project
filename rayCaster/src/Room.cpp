#include "Room.h"
#include <iostream>
#include <limits.h>
#include <math.h>
#include <memory>


#define EPSILON2 0.1

Room::Room(std::vector<Object*> light_container, std::vector<Object*> object_container, std::vector<Object*> cube_container)
{
    this->light_container = light_container;
    this->object_container = object_container;
    this->cube_container = cube_container;
    //ctor
}

Room::Room() {
    // init containers
    std::vector<Object*> object_container(0);
    std::vector<Object*> light_container(0);
    std::vector<Object*> cube_container(0);

    Wall *roof, *floor, *north, *south, *east, *west;

    glm::vec3 roofPos, floorPos, northPos, /* southPos ,*/ eastPos, westPos;
    glm::vec3 roofNorm, floorNorm, northNorm, /* southNorm ,*/ eastNorm, westNorm;

    float roomXMin, roomXMid, roomXMax;
    float roomYMin, roomYMid, roomYMax;
    float roomZMin, roomZMid, roomZMax;

    // global room coordinates
    roomXMin = -200;
    roomXMid = 0;
    roomXMax = 200;
    roomYMin = -200;
    roomYMid = 0;
    roomYMax = 200;
    roomZMin = -500;       //, defined as closest to screen NEAR plane defined as z = -20;
    roomZMid = -250;
    roomZMax = 0;

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


    roof    = new Wall(0, roofPos, roofNorm,
                       NULL, NULL, roomXMin, roomXMax, roomYMax, roomYMax,roomZMin, roomZMax);
    roof->setColor(glm::vec3(0.9,0.6,0.6));
    floor   = new Wall(1, floorPos, floorNorm,
                       NULL, NULL, roomXMin, roomXMax, roomYMin, roomYMin,roomZMin, roomZMax);
    floor->setColor(glm::vec3(0.6,0.6,0.6));
    north   = new Wall(2, northPos, northNorm,
                       NULL, NULL, roomXMin, roomXMax, roomYMin, roomYMax,roomZMin, roomZMin);

    north->setColor(glm::vec3(0.4,0.4,0.4));
    west    = new Wall(3, westPos, westNorm,
                       NULL, NULL, roomXMin, roomXMin, roomYMin, roomYMax,roomZMin, roomZMax);
    west->setColor(glm::vec3(0.6,0.9,0.6));
    east    = new Wall(4, eastPos, eastNorm,
                       NULL, NULL, roomXMax, roomXMax, roomYMin, roomYMax,roomZMin, roomZMax);
    east->setColor(glm::vec3(0.6,0.6,0.9));

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

    glm::vec3 lightPos = glm::vec3(roofPos.x,roofPos.y-0.003,roofPos.z);
    lightPos = roofPos;

    AreaLight *light = new AreaLight(0,lightPos,1.0f, roofNorm,100,100,
                        -50,50,roomYMax,roomYMax,roomZMid-50,roomZMid+50);
    //AreaLight light = new AreaLight();



    this->light_container.push_back(light);

    // add a cube inside the room
    int idCube = 20; // careful, the next id (idCube + 6) are taken!
    glm::vec3 posCube = glm::vec3(roomXMid, roomYMin+100, roomZMin + 50);
    float hCube = 50;
    float wCube = hCube;
    float x1Cube = posCube.x - wCube/2;
    float x2Cube = posCube.x + wCube/2;
    float yCube = posCube.y;
    float z1Cube = posCube.z - wCube/2;
    float z2Cube = posCube.z + wCube/2;
    Cube* cube = new Cube(idCube, posCube, hCube, wCube, x1Cube, x2Cube, yCube, z1Cube, z2Cube);
    //cube->printCube();
    this->cube_container.push_back(cube);
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

Intersection* Room::findIntersection(Ray* ray){
    // we consider every object in the scene

    // Later, check for cubes first.
    Intersection* intersection = findIntersection(ray, cube_container);
    if(intersection->getIsIntersecting()) {
        ray->setIntersection(intersection);
        return intersection;
    }
    // first check for lights.

    //std::cout << "finding intersection...";

    //std::cout << "looking through light sources...\n";
    delete intersection;
    intersection = findIntersection(ray, light_container);
    // if we found light, return the point (it can't intersect with a wall in front of the light)
    if(intersection->getIsIntersecting()) {
        AreaLight* lightObj = dynamic_cast<AreaLight*>(light_container.at(intersection->getIdObject()));
        intersection->setIsLightsource(true);
        intersection->setLe(lightObj->getLe());
        ray->setIntersection(intersection);
        //std::cout << "findIntersection: FOUND A LIGHT SOURCE!!!!!111!!!11!!!one!!!\n";
        return intersection;
    } // else, check for intersection with walls.


    //std::cout << "FAIL!\n looking through walls...";
    delete intersection;
    intersection = findIntersection(ray, object_container);
    ray->setIntersection(intersection);

    if(!intersection->getIsIntersecting()) {
        //std::cout << "We have a wall which we can't see... buggy indeed!\n";

    }

    //std::cout << "returning function...\n";
    // return this regardless!
    return intersection;
}


Intersection* Room::findIntersection(const Ray* ray, std::vector<Object*> container) {

    Intersection* intersection = new Intersection(false, 0, NULL, 0);
    std::vector<Object*>::iterator itObject;
    //Intersection* tmpInter = new Intersection(false, 0, NULL, 0);
    // we consider every object in the scene

    //for(int i = 0; i < object_container.size(); i++){
    for(itObject = container.begin(); itObject != container.end(); ++itObject){
        //std::cerr << "Wall is:" << (*itObject)->getObjectID();

        Intersection* tmpInter = ((*itObject)->getIntersection(ray));
        //tmpInter = object_container.at(i)->getIntersection(ray);
        if (tmpInter->getIsIntersecting()){
            // the ray collides with this object
            if((tmpInter->get_t() > 0.0 && tmpInter->get_t() < intersection->get_t()) || (tmpInter->get_t() > 0.0 && intersection->get_t() == 0.0)){
                // the object we are colliding with is nearer that the others one, or it is the first
                *intersection = *tmpInter;
            }
        }
        delete tmpInter;
    }
    return intersection;
}




bool comparePoints(glm::vec3 v1, glm::vec3 v2){
    //std::cout << "comparePoints: checking the diff..: ";
    float diff = glm::distance(v2, v1);
    //std::cout << diff << "\n";
    return (diff < EPSILON2);
}

float calcGeometry(Intersection* pointInter, Intersection* shadowInter, Ray* shadowRay) {
    float cosPoint, cosShadow, distance, result;
    cosPoint = glm::dot(pointInter->getNormal(), shadowRay->getDirection());
    cosShadow = glm::dot(shadowInter->getNormal(), -(shadowRay->getDirection()));
    distance = glm::distance(pointInter->getPoint(), shadowInter->getPoint());
    result = (cosPoint * cosShadow) / (distance * distance);
    return result;
}

glm::vec3 Room::calculateColor(Ray* ray){
    Intersection* intersection = ray->getIntersection();
    glm::vec3 pos = intersection->getPoint();
    glm::vec3 radiance = glm::vec3(0,0,0);

    // if the point light is a light, return the light!
    if(intersection->getIsLightsource()) {
        radiance = glm::vec3(1,1,1) * intersection->getLe();
        //std::cout << "calculateLight: we found a lightsource! returning the Le of ";
        //std::cout << intersection->getLe() << "\n";
        return radiance;
    } else {
        // else, send shadow rays to all light sources and check for light contributions!


        std::vector<Object*>::iterator itLight;
        //std::cout << "The point was not a light source! sending shadow ray...";
        for(itLight = light_container.begin(); itLight != light_container.end();++itLight) {
            AreaLight* tmpLight = dynamic_cast<AreaLight*>(*itLight);
            int counter = 0;

            if(intersection->getIdObject() == 0) {
                    // Here, we got a roof! We should debug all of these, because they should all be zero!
                    //std::cout << "Found a roof! " << FLT_MAX << " " << FLT_MIN;
            }

            for(int i = 0; i < NBSHADOWRAY; i++ ) {
                //glm::vec3 samplingLightPoint = tmpLight->getCenterPoint();
                glm::vec3 samplingLightPoint = tmpLight->getRandomPoint();
                Ray* shadowRay = new Ray(intersection->getPoint(), // origin
                                        samplingLightPoint - intersection->getPoint()); // direction
                Intersection* shadowInter = this->findIntersection(shadowRay);

                bool isComparePoints = comparePoints(shadowInter->getPoint(), samplingLightPoint);

                if(comparePoints(shadowInter->getPoint(), samplingLightPoint) && shadowInter->getIsIntersecting()) {
                    if(intersection->getIdObject() == 0) {
                        //std::cout << "BUG CASE! we got roof, but still found a light!\n";
                    }
                    float geometry = calcGeometry(intersection, shadowInter, shadowRay);
                    glm::vec3 rayRadiance = glm::vec3(1,1,1);
                    rayRadiance *= (tmpLight->getLe() / ((float) NBSHADOWRAY));
                    rayRadiance *= geometry;
                    radiance += rayRadiance;
                    //radiance += glm::vec3(1,1,1) * (tmpLight->getLe() / ((float) NBSHADOWRAY));
                    counter++;
                } else {
                    // this should be objects parallel to the light source :) problem is when we
                    // don't get here for object parallel to the light source :(
                    //std::cout << "We sent a shadow ray, but it couldn't find anything :/\n";
                }
                delete shadowRay;
            }
            //std::cout << "radiance is: (" << radiance.x << "," << radiance.y << "," << radiance.z << ")\n";
            //radiance = radiance * (float) ((float)NBSHADOWRAY / ((float) counter)) * tmpLight->getLe();
        }


        //radiance = radiance * 0.0f;


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
    glm::vec3 color = intersection->getColor();
    // sqrt to get colors to shape
    color.x = sqrt(color.x * radiance.x);
    color.y = sqrt(color.y * radiance.y);
    color.z = sqrt(color.z * radiance.z);

    color *= BRDF_CONSTANT; // scaling factor... Can contain the P from the Russian Roulette.

    // Monte Carlo Part...
    // UGLY HAX instead of checking if a child is defined, use probability stuff

    //if(!ray->getChild() == NULL) {


        //std::cout << "Room::CalculateColor -- Generating random outgoing ray!\n";

        float randomNum = (float) rand()/(float)RAND_MAX;

        if((randomNum < RUSSIAN_P && ray->getDepth() != 0) || ray->getDepth() > MAXBOUNCES + 1) {
            //std::cout << "total depth is " << ray->getDepth() << "\n";
            //delete ray;
            return DIRECT_CONSTANT * color;
        } else {

            float randPhi = rand() * 2.0*M_PI; // defined for whole azimoth.
            float randTheta   = rand() * M_PI * (1 + RUSSIAN_P); // only defined for half the inclination.
            float dirX = sin(randTheta) * cos(randPhi);
            float dirY = sin(randTheta) * sin(randPhi);
            float dirZ = cos(randTheta);
            glm::vec3 outgoingDir = glm::vec3(dirX,dirY,dirZ);
            outgoingDir = glm::normalize(outgoingDir + intersection->getNormal());

            float cosOutgoingAngle = glm::dot(outgoingDir, intersection->getNormal());

            // if the angle of the new ray and the normal of the surface is larger than pi/2 (negative)


            Ray* outgoingRay = new Ray(intersection->getPoint(), outgoingDir);
            outgoingRay->setDepth(ray->getDepth()+1);

            this->findIntersection(outgoingRay);
            ray->setChild(outgoingRay);

            // create a random output direction, throw it into the new ray

            // recursivly do stuff, and weight the incoming and outcoming light (hard coded BRDF);
            //std::cout << "doing recursive stuff! depth " << ray->getDepth() << " and going!\n";
            return DIRECT_CONSTANT * color ;//+  INDIRECT_CONSTANT * cosOutgoingAngle * this->calculateColor(outgoingRay);
        }

    //} else {
    //    return 0.9f * color; // indirect color is zero.
    //}


}


