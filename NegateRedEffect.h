#ifndef NEGATE_RED_EFFECT_H
#define NEGATE_RED_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class NegateRedEffect: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            int a = 0;
            a = 255 - point.getRed();
            point.setRed(a);
        }
    }
};

#endif
