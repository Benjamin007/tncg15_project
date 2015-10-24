#ifndef PIXEL_H
#define PIXEL_H
#include <string>

class Pixel
{
    public:
        Pixel();
        void myPrint();
        std::string toString();
        int getTGAData();
        virtual ~Pixel();
        float getRed();
        float getGreen();
        float getBlue();
    protected:

        float red;
        float green;
        float blue;
        float alpha;
    private:
};

#endif // PIXEL_H
