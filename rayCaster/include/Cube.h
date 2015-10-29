#ifndef CUBE_H
#define CUBE_H

#include <Object.h>
#include <Wall.h>


class Cube : public Object
{
    public:
        // the user give the information for the southWall, and the others ones are build from it
        // be careful with the id...
        // normal given in argument directed toward the outside of the cube!
        // the cube is created in the aligment of the world frame
        // just one y because our floorWall should be in a y plan!
        Cube(int id, glm::vec3 pos, float h, float w, float x1, float x2, float y, float z1, float z2);
        virtual ~Cube();

        Intersection* getIntersection(const Ray* const ray) const;

        void printCube();
    protected:


    private:
        int id;
        Wall* ceilWall;
        Wall* floorWall;
        Wall* northWall;
        Wall* eastWall;
        Wall* westWall;
        Wall* southWall;
};

#endif // CUBE_H
