#ifndef SURFACEINTEGRATOR_H
#define SURFACEINTEGRATOR_H

#include "Room.h"
#include "Ray.h"
#include "RayTracer.h"
#include "Intersection.h"

class SurfaceIntegrator
{
    public:
        SurfaceIntegrator();
        virtual ~SurfaceIntegrator();

        // returns the radiance along a ray
        float Li(const Room* room, const RayTracer* raytracer, const Ray* ray, const Intersection &intersection) const;

    protected:
    private:
};

#endif // SURFACEINTEGRATOR_H
