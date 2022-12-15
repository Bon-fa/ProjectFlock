#ifndef BOID_H
#define BOID_H

#include <math.h>

#include <iostream>
#include <string>
#include <vector>

#include "BVector.h"

int SepRange=20;
int AllRange=50;
int CoheRange=50;

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

  void separation(const Boid& b);
  void allignment(const Boid& b);
  void cohesion(const Boid& b);

  BVector seek(BVector v);
};

#endif  // BOID_H