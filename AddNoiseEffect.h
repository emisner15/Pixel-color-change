#ifndef ADD_NOISE_EFFECT_H
#define ADD_NOISE_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
using namespace std;

class AddNoiseEffect: public SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points)
    {
        for(auto &point : points)
        {
            int ran1 = rand() % 21;
            int ran2 = rand() % 21;
            int ran3 = rand() % 21;

            if(ran1 > 10)
            {
                ran1 = ran1 - 20;
                point.setRed(point.getRed() + ran1);
            }
            if(ran2 > 10)
            {
                ran2 = ran2 - 20;
                point.setGreen(point.getGreen() + ran2);
            }
            if(ran3 > 10)
            {
                ran3 = ran3 - 20;
                point.setBlue(point.getBlue() + ran3);
            }
            else
            {
                point.setRed(point.getRed() + ran1);
                point.setGreen(point.getGreen() + ran2);
                point.setBlue(point.getBlue() + ran3);
            }
        }
    }
};

#endif
