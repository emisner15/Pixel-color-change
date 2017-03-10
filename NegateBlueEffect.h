#ifndef NEGATE_BLUE_EFFECT_H
#define NEGATE_BLUE_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class NegateBlueEffect: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            int a = 0;
            a = 255 - point.getBlue();
            point.setBlue(a);
        }
    }
};

#endif
