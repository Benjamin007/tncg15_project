#include "SurfaceIntegrator.h"

SurfaceIntegrator::SurfaceIntegrator()
{
    //ctor
}

SurfaceIntegrator::~SurfaceIntegrator()
{
    //dtor
}

float SurfaceIntegrator::Li(const Room* room, const RayTracer* raytracer, const Ray* ray, const Intersection &intersection) const{
    float L = 0.0;

    // we check the brdf at the intersection point
    float brdf = intersection.getBRDF();
    glm::vec3 w0 = -ray->getDirection();

    return L;
}
