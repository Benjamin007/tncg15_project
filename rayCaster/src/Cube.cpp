#include "Cube.h"

Cube::Cube(int id, glm::vec3 pos, float h, float w, float x1, float x2, float y, float z1, float z2)
{
    this->id = id;
    //ctor
    glm::vec3 normFloorWall = glm::vec3(0.0, -1.0, 0.0);
    floorWall = new Wall(id+1, pos, normFloorWall, h, w, x1, x2, y, y, z1, z2);

    // creation ceilWall
    glm::vec3 normCeilWall = glm::vec3(0.0, 1.0, 0.0);
    ceilWall = new Wall(id+2, pos + glm::vec3(0.0, h, 0.0), normCeilWall, h, w, x1, x2, y + h, y + h, z1, z2);

    // creation northWall
    glm::vec3 normNorthWall = glm::vec3(0.0, 0.0, -1.0);
    northWall = new Wall(id+3, pos + glm::vec3(0.0, h/2, -w/2), normNorthWall, h, w, x1 ,x2, y, y + h, z1, z1);

    // creation westWall
    glm::vec3 normWestWall = glm::vec3(-1.0, 0.0, 0.0);
    westWall = new Wall(id+4, pos + glm::vec3(-w/2, h/2, 0.0), normWestWall, h, w, x1 ,x1, y, y + h, z1, z2);

    // creation southWall
    glm::vec3 normSouthWall = glm::vec3(0.0, 0.0, 1.0);
    southWall = new Wall(id+5, pos + glm::vec3(0.0, h/2, w/2), normSouthWall, h, w, x1 ,x2, y, y + h, z2, z2);

    // creation eastWall
    glm::vec3 normEastWall = glm::vec3(1.0, 0.0, 0.0);
    eastWall = new Wall(id+6, pos + glm::vec3(w/2, h/2, 0), normEastWall, h, w, x2 ,x2, y, y + h, z1, z2);
}

Cube::~Cube()
{
    //dtor
}

Intersection* Cube::getIntersection(Ray const* ray) const{
    Intersection* intersection = new Intersection();
    Intersection* tmpIntersection = new Intersection();

    intersection = floorWall->getIntersection(ray);

    // consider the 6 faces, and find the first one our ray is going to intersect
    tmpIntersection = ceilWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if(tmpIntersection->get_t() < intersection->get_t() && tmpIntersection->get_t() != 0){
            *intersection = *tmpIntersection;
        }
    }

    tmpIntersection = floorWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if(tmpIntersection->get_t() < intersection->get_t() && tmpIntersection->get_t() != 0){
            *intersection = *tmpIntersection;
        }
    }

    tmpIntersection = northWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if(tmpIntersection->get_t() < intersection->get_t() && tmpIntersection->get_t() != 0){
            *intersection = *tmpIntersection;
        }
    }

    tmpIntersection = westWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if(tmpIntersection->get_t() < intersection->get_t() && tmpIntersection->get_t() != 0){
            *intersection = *tmpIntersection;
        }
    }

    tmpIntersection = southWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if(tmpIntersection->get_t() < intersection->get_t() && tmpIntersection->get_t() != 0){
            *intersection = *tmpIntersection;
        }
    }

    tmpIntersection = eastWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if(tmpIntersection->get_t() < intersection->get_t() && tmpIntersection->get_t() != 0){
            *intersection = *tmpIntersection;
        }
    }

    return intersection;
}
