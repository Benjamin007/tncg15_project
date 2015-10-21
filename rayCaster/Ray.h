#ifndef RAY_H
#define RAY_H

#include "./common/VectorUtils3.h"

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
