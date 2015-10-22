#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    public:
        Pixel();
        void myPrint();
        virtual ~Pixel();
    protected:

        int red;
        int green;
        int blue;
        int alpha;
    private:
};

#endif // PIXEL_H
