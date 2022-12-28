#include "Boid.h"

// la funzione si applica ad un boid e scorre tutti gli altri
// misurandone la distanza. Se il boid è dentro al raggio d'azione
// allora creo un "Vettore media" che indica la nuova direzione e intensità
// della velocità. Ritorno il vettore media velocità.
// Per farlo normalizziamo la differenza tra le posizioni e la moltiplichiamo
// per maxvelocity considerando un peso (maggiore se sei più vicino).
// Le singole variazioni sono sommate e divise infine per il numero di
// boid nel raggio (count).
BVector Boid::separation(const std::vector<Boid> boids)
{
  //sembra che count non serva
  //float count = 0;
  BVector sum;
  for (int i = 0; i < boids.size(); i++)
  {
    float d = position.dist(boids[i].position);
    if (d > 0 && d < SepRange)
    {
      BVector dev;
      dev.setvalue(0, 0);
      dev.vectorTwoSub(position, boids[i].position);
      dev.normalize();
      dev.scalarMul(1 - (d / SepRange));
      //dev.scalarMul(maxVel);
      //count++;
      sum.vectorSum(dev);
    }
  }

  /*if (count > 0)
  {
    sum.scalarDiv((float)count);
  }*/

  if (sum.norm() > 0)
  {
    // Steering = sum - Velocity
    sum.normalize();
    sum.scalarMul(maxVel);
    sum.vectorSub(velocity);
    sum.limitsize(maxAcc);
  }
  return sum;
}

//
BVector Boid::allignment(const std::vector<Boid> boids)
{
  BVector sum;
  for (int i = 0; i < boids.size(); i++)
  {
    float d = position.dist(boids[i].position);
    if (d > 0 && d < AllRange)
    {
      sum.vectorSum(boids[i].velocity);
    }
  }
  if (sum.norm() > 0)
  {
    sum.normalize();
    sum.angle(velocity);
    
  }
}

// Si applica ad un boid e ritorna "sum".
// Creo target(0,0) e lo sottraggo a un vettore in ingresso, così
// che diventi il negativo del punto verso cui tendo. Normalizzo,
// moltiplico per la velocità massima (così diventa target diventa velocità).
// sottraggo alla velocità del boid il vettore target, e ne limito la dimensione.
BVector Boid::seek(BVector v)
{ // v è il target
  BVector target;
  target.vectorSub(v);
  target.normalize(); // v viene normalizzato e reso una velocità
  target.scalarMul(maxVel);
  acceleration.vectorTwoSub(velocity, target); // si fa la differenza fra la direzione del boid e il target
  acceleration.limitsize(maxAcc);
  return acceleration;
  return acceleration;
}
