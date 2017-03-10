#ifndef REMOVE_RED_EFFECT_H
#define REMOVE_RED_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class RemoveRedEffect: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            point.setRed(0);
        }
    }
};

#endif
