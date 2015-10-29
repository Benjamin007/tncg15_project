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

    // consider the 6 faces, and find the first one our ray is going to intersect
    tmpIntersection = ceilWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if((tmpIntersection->get_t() > 0.0 && tmpIntersection->get_t() < intersection->get_t())
            || (tmpIntersection->get_t() > 0.0 && intersection->get_t() == 0.0)){
            intersection = tmpIntersection;
            //std::cout << "Potential intersection with the ceilWall\n";
        }
    }

    tmpIntersection = floorWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if((tmpIntersection->get_t() > 0.0 && tmpIntersection->get_t() < intersection->get_t())
            || (tmpIntersection->get_t() > 0.0 && intersection->get_t() == 0.0)){
            intersection = tmpIntersection;
            //std::cout << "Potential intersection with the floorWall\n";
        }
    }

    tmpIntersection = northWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if((tmpIntersection->get_t() > 0.0 && tmpIntersection->get_t() < intersection->get_t())
            || (tmpIntersection->get_t() > 0.0 && intersection->get_t() == 0.0)){
            intersection = tmpIntersection;
            //std::cout << "Potential intersection with the northWall\n";
        }
    }

    tmpIntersection = westWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if((tmpIntersection->get_t() > 0.0 && tmpIntersection->get_t() < intersection->get_t())
            || (tmpIntersection->get_t() > 0.0 && intersection->get_t() == 0.0)){
            intersection = tmpIntersection;
            //std::cout << "Potential intersection with the westWall\n";
        }
    }

    tmpIntersection = southWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if((tmpIntersection->get_t() > 0.0 && tmpIntersection->get_t() < intersection->get_t())
            || (tmpIntersection->get_t() > 0.0 && intersection->get_t() == 0.0)){
            intersection = tmpIntersection;
            //std::cout << "Potential intersection with the southWall\n";
        }
    }

    tmpIntersection = eastWall->getIntersection(ray);
    if(tmpIntersection->getIsIntersecting()){
        if((tmpIntersection->get_t() > 0.0 && tmpIntersection->get_t() < intersection->get_t())
            || (tmpIntersection->get_t() > 0.0 && intersection->get_t() == 0.0)){
            intersection = tmpIntersection;
            //std::cout << "Potential intersection with the eastWall\n";
        }
    }

    return intersection;
}

void Cube::printCube(){
    std::cout << "the coordinates of the walls of the cube are pos.x pos.y pos.z x1 x2 y1 y2 z1 z2:\nThe floorWall "
    << this->floorWall->getPos().x << " " << this->floorWall->getPos().y << " " << this->floorWall->getPos().z << " "
    << this->floorWall->x1 << " " << this->floorWall->x2 << " " << this->floorWall->y1 << " " << this->floorWall->y2
    << " " << this->floorWall->z1 << " " << this->floorWall->z2 << std::endl;

    std::cout << "The ceilWall " << this->ceilWall->getPos().x << " " << this->ceilWall->getPos().y << " " <<
    this->ceilWall->getPos().z << " " << this->ceilWall->x1 << " " << this->ceilWall->x2 << " " << this->ceilWall->y1
    << " " << this->ceilWall->y2 << " " << this->ceilWall->z1 << " " << this->ceilWall->z2 << std::endl;

    std::cout << "The northWall " << this->northWall->getPos().x << " " << this->northWall->getPos().y << " " <<
    this->northWall->getPos().z << " " << this->northWall->x1 << " " << this->northWall->x2 << " " <<
    this->northWall->y1 << " " << this->northWall->y2 << " " << this->northWall->z1 << " " << this->northWall->z2 << std::endl;

    std::cout << "The westWall " << this->westWall->getPos().x << " " << this->westWall->getPos().y << " " <<
    this->westWall->getPos().z << " " << this->westWall->x1 << " " << this->westWall->x2 << " " << this->westWall->y1
    << " " << this->westWall->y2 << " " << this->westWall->z1 << " " << this->westWall->z2 << std::endl;

    std::cout << "The southWall " << this->southWall->getPos().x << " " << this->southWall->getPos().y << " " <<
    this->southWall->getPos().z << " " << this->southWall->x1 << " " << this->southWall->x2 << " " << this->southWall->y1
    << " " << this->southWall->y2 << " " << this->southWall->z1 << " " << this->southWall->z2 << std::endl;

    std::cout << "The eastWall " << this->eastWall->getPos().x << " " << this->eastWall->getPos().y << " "
    << this->eastWall->getPos().z << " " << this->eastWall->x1 << " " <<this->eastWall->x2 << " " <<
    this->eastWall->y1 << " " << this->eastWall->y2 << " " << this->eastWall->z1 << " " << this->eastWall->z2 << std::endl;
}
