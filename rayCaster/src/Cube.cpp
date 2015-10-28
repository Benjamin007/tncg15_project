#include "Cube.h"

Cube::Cube(int id, glm::vec3 pos, float h, float w, float x1, float x2, float y1, float y2, float z)
{
    //ctor
    glm::vec3 normFloorWall = glm::vec3(0.0, 0.0, -1.0);
    floorWall = new Wall(id+1, pos, normFloorWall, h, w, x1, x2, y1, y2, z, z);

    // creation ceilWall
    glm::vec3 normCeilWall = glm::vec3(0.0, 0.0, 1.0);
    ceilWall = new Wall(id+2, pos + (0.0, 0.0, h), normCeilWall, h, w, x1, x2, y1, y2, z + h, z + h);

    // creation northWall
    glm::vec3 normNorthWall = glm::vec3(0.0, 1.0, 0.0);
    northWall = new Wall(id+3, pos + (0.0, w/2, h/2), normNorthWall, h, w, x1 ,x2, y2, y2, z, z + h);

    // creation westWall
    glm::vec3 normWestWall = glm::vec3(-1.0, 0.0, 0.0);
    westWall = new Wall(id+4, pos + (-w / 2, 0.0, h/2), normWestWall, h, w, x1 ,x1, y1, y2, z, z + h);

    // creation southWall
    glm::vec3 normSouthWall = glm::vec3(0.0, -1.0, 0.0);
    southWall = new Wall(id+5, pos + (0.0, -w / 2, h/2), normSouthWall, h, w, x1 ,x2, y1, y1, z, z + h);

    // creation eastWall
    glm::vec3 normEastWall = glm::vec3(1.0, 0.0, 0.0);
    eastWall = new Wall(id+6, pos + (+w / 2, 0.0, h/2), normEastWall, h, w, x2 ,x2, y1, y2, z, z + h);
}

Cube::~Cube()
{
    //dtor
}
