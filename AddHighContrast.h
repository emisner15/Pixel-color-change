#ifndef ADD_HIGH_CONTRAST_H
#define ADD_HIGH_CONTRAST_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class AddHighContrast: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            int red = point.getRed();
            int green = point.getGreen();
            int blue = point.getBlue();

            if(red > 127)
            {
                red = 255;
            }
            else red = 0;
            if(green > 127)
            {
                green = 255;
            }
            else green = 0;
            if(blue > 127)
            {
                blue = 255;
            }
            else blue = 0;

            point.setRed(red);
            point.setGreen(green);
            point.setBlue(blue);
        }
    }
};

#endif
