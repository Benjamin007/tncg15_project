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
    protected:

        int red;
        int green;
        int blue;
        int alpha;
    private:
};

#endif // PIXEL_H
