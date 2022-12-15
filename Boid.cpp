#include "Boid.h"

 void Boid::separation(const Boid& b)
 {
    int count=0;
    
    for(i=0, i<, i++){
     float d= position.dist(b.position);   
    
    if(d>0 && d<SepRange){

    }
    }
 }





  void allignment(const Boid& b);
  void cohesion(const Boid& b);

BVector Boid::seek(BVector v){ //v è il target
    BVector target;
    target.vectorSub(v);
    target.normalize();          //v viene normalizzato e reso una velocità
    target.scalarMul(maxVel);
    acceleration.vectorTwoSub(velocity, target);  //si fa la differenza fra la direzione del boid e il target
    acceleration.limitsize(maxAcc);
    return acceleration;
}