#include "SurfaceIntegrator.h"
#include "AreaLight.h"

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

    // if the light hit an area source, we add this light
    L += intersection.getLe();

    // add the contribution of each light source
    std::vector<Object*>::iterator itLightSource;
    for(itLightSource = (room->getLightContainer()).begin(); itLightSource != (room->getLightContainer()).end(); ++itLightSource){
        // if(the light source is visible from the intersectionPoint(launch shadow ray!))
        AreaLight* light = dynamic_cast<AreaLight*>(*itLightSource);
        float Li = light->getLe(); // not  correct, only a proportion of the light emitted by the lightsource will reach our point

        // we have lambertian reflector, so some of the incident light will always leave into the direction w0
        L += brdf * Li;// * dot(wi, n);
    }

    // will launch ray for specular reflection and refraction...

    return L;
}
