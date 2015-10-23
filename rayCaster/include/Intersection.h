#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "glm/glm/glm.hpp"

class Intersection
{
    public:
        Intersection();
        Intersection(bool isInter, float _t, int* id);
        Intersection(const Intersection& inter);
        virtual ~Intersection();

        bool getIsIntersecting() const;
        void setIsIntersecting(bool boolInter);
        float get_t() const;
        void set_t(float _t);
        int* getIdObject() const;
        void setIdObject(int* id);


        Intersection& operator = (const Intersection& inter);

    protected:
        // true if the ray intersecting a surface
        bool isIntersecting;
        // parametric distance between the origin of the ray and the intersectionPoint
        float t;
        // id of the object the ray collides with
        int* idObject;

    private:
};

#endif // INTERSECTION_H
