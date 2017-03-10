#ifndef REMOVE_BLUE_EFFECT_H
#define REMOVE_BLUE_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class RemoveBlueEffect: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            point.setBlue(0);
        }
    }
};

#endif
