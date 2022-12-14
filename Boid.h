#ifndef BOID_H
#define BOID_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "BVector.h"



class Boid
{
    public:
        float sepCoef;
        float cohCoef;
        float aliCoef;
        float maxVel;
        float maxAcc;

        BVector position;
        BVector velocity;
        BVector acceleration;

        Boid() {}
        Boid(BVector r, BVector v){
        acceleration = BVector(0,0);
        v.setRandomValue();
        velocity.x = v.x;
        velocity.y = v.y;
        position = BVector(r.x, r.y);
        }



};

#endif // BOID_H