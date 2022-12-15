#include "BVector.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

void BVector::setvalue(float a, float b) {
  x = a;
  y = b;
}

void BVector::vectorSum(const BVector &v) {
  x += v.x;
  y += v.y;
}

void BVector::vectorSub(const BVector &v) {
  x -= v.x;
  y -= v.y;
}

BVector BVector::vectorTwoSub(const BVector &v, const BVector &u) {
  BVector sub(v.x - u.x, v.y - u.y);
  return sub;  // std::move(sub) al posto di 'sub'
}

float BVector::vectorSProd(const BVector &v) {
  float SProd = x * v.x + y * v.y;
  return SProd;
}

void BVector::scalarSum(float s) {
  x += s;
  y += s;
}

void BVector::scalarSub(float s) {
  x -= s;
  y -= s;
}

void BVector::scalarMul(float s) {
  x *= s;
  y *= s;
}

void BVector::scalarDiv(float s) {
  x /= s;
  y /= s;
}

void BVector::limitsize(double max) {

    float n = norm();
    if (n > max)
    {
        setvalue(x * max / n, y * max / n);
    }
  
}

float BVector::dist(const BVector &v) {
  float d = sqrt(pow(x - v.x, 2) + pow(y - v.y, 2));
  return d;
}

float BVector::norm() {
  float n = sqrt(pow(x, 2) + pow(y, 2));
  return n;
}

float BVector::angle(const BVector &v) {
  if (x == 0 && y == 0) {
    return 0.0f;
  }
  if (v.x == 0 && v.y == 0) {
    return 0.0f;
  }

  // per questi non sappiamo se usare float o double
  float scalprod = x * v.x + y * v.y;
  float normx = sqrt(x * x + y * y);
  float normv = sqrt(v.x * v.x + v.y * v.y);
  float cosphi = scalprod / (normx * normv);
  float phi = acos(cosphi);  // ci restituisce un angolo in RADIANTI!!
  return phi;
}

void BVector::normalize() {
  float n = norm();
  if (n > 0) {
    setvalue(x / n, y / n);
  } else {
    setvalue(x, y);
  }
}

void BVector::setRandomValue()  // velocità random tra -1 e 1
{
  srand(time(NULL));
  x = rand() % 3 - 1;
  y = rand() % 3 - 1;
}