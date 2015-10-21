#ifndef RAY_H
#define RAY_H

#include <glm/vec3.hpp>

class Ray
{
    public:
        Ray();
        virtual ~Ray();
    protected:

    vec3 origin;
    vec3 direction;

    private:
};

#endif // RAY_H
