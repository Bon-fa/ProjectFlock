#ifndef BOID_H
#define BOID_H

#include <math.h>

#include <iostream>
#include <string>
#include <vector>

#include "BVector.h"

float SepRange=20;
float AllRange=50;
float CoheRange=50;

class Boid {
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
  Boid(BVector r) {
    acceleration = BVector(0, 0);
    velocity.setRandomValue();
    position = BVector(r.x, r.y);
  }

  BVector separation(const std::vector<Boid> boids);
  BVector allignment(const std::vector<Boid> boids);
  BVector cohesion(const std::vector<Boid> boids);

  BVector seek(BVector v);
};

#endif  // BOID_H