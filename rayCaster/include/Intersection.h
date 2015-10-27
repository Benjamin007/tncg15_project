#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "glm/glm/glm.hpp"

class Intersection
{
    public:
        Intersection();
        Intersection(bool isInter, float _t, int id, float brdf);
        Intersection(const Intersection& inter);
        virtual ~Intersection();

        bool getIsIntersecting() const;
        void setIsIntersecting(bool boolInter);

        bool getIsLightsource() const;
        void setIsLightsource(bool isLightSource) ;
        float get_t() const;
        void set_t(float _t);
        int getIdObject() const;
        void setIdObject(int id);
        float getBRDF() const;
        void setBRDF(float brdf);
        float getLe() const;
        void setLe(float Le);

        glm::vec3 getPoint();
        void setPoint(glm::vec3 newPoint);

        Intersection& operator = (const Intersection& inter);

    protected:
        // true if the ray intersecting a surface
        bool isIntersecting;
        // parametric distance between the origin of the ray and the intersectionPoint
        float t;
        // id of the object the ray collides with
        int idObject;

        float BRDF; // just lambertian reflector for the moment

        // if the point of intersection is on a light source, we store the power of the light
        float Le;

        glm::vec3 point;

        bool isLightSource;

    private:
};

#endif // INTERSECTION_H
