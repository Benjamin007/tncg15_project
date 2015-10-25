#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "glm/glm/glm.hpp"

class LightSource
{
    public:
        LightSource();
        LightSource(float Le, glm::vec3 pos);
        virtual ~LightSource();

        float getLe() const;

        glm::vec3 getPosition();
    protected:

    float Le;
    glm::vec3 pos;
    private:
};

#endif // LIGHTSOURCE_H
