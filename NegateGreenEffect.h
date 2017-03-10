#ifndef NEGATE_GREEN_EFFECT_H
#define NEGATE_GREEN_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class NegateGreenEffect: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            int a = 0;
            a = 255 - point.getGreen();
            point.setGreen(a);
        }
    }
};

#endif
