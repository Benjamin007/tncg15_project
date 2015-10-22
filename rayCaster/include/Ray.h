#ifndef RAY_H
#define RAY_H

#include "glm/glm/vec3.hpp"

class Ray
{
    public:
        Ray();
        Ray(glm::vec3 o, glm::vec3 dir);
        ~Ray();

        glm::vec3 getOrigin() const;
        glm::vec3 getDirection() const;
    protected:

        glm::vec3 origin;
        glm::vec3 direction;

    private:
};

#endif // RAY_H
