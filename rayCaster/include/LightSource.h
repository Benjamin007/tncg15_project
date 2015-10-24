#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H


class LightSource
{
    public:
        LightSource();
        LightSource(float Le);
        virtual ~LightSource();

        float getLe() const;
    protected:

    float Le;
    private:
};

#endif // LIGHTSOURCE_H
