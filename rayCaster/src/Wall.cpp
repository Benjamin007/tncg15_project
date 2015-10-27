#include "Wall.h"
#include "SurfaceObject.h"
#include "Ray.h"
#include "glm/glm/glm.hpp"

Wall::Wall(int id):SurfaceObject(id,glm::vec3(0.0, 0.0, 0.0),glm::vec3(0.0, 0.0, 0.0),0,0,0,0,0,0,0,0)
{
    //ctor
    /*
    glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
    pos = pos;
    glm::vec3 norm = glm::vec3(0.0, 0.0, 0.0);
    normal = norm;
    height = 0;
    width = 0;
    this->x1 = 0;
    this->x2 = 0;
    this->y1 = 0;
    this->y2 = 0;
    this->z1 = 0;
    this->z2 = 0;
    */
    rho = 0.8;
    BRDF = rho/M_PI;
}

Wall::Wall(int id, glm::vec3 pos, glm::vec3 norm, float h, float w, float x1, float x2, float y1, float y2, float z1, float z2):
    SurfaceObject(id, pos,norm,h,w,x1,x2,y1,y2,z1,z2){
    rho = 0.8;
    BRDF = rho/M_PI;
}

Wall::~Wall()
{
    //dtor
}



//void Wall::setBrdf(float brdf){
//    this->BRDF = brdf;
//}

