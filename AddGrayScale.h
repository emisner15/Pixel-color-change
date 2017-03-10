#ifndef ADD_GRAY_SCALE_H
#define ADD_GRAY_SCALE_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class AddGrayScale: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            int red = point.getRed();
            int green = point.getGreen();
            int blue = point.getBlue();
            int avg;

            avg = (red + green + blue)/3;

            point.setRed(avg);
            point.setGreen(avg);
            point.setBlue(avg);
        }
    }
};

#endif
