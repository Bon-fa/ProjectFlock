#include "Boid.h"

//la funzione si applica ad un boid e scorre tutti gli altri
//misurandone la distanza. Se il boid è dentro al raggio d'azione
//allora creo un "Vettore media" che indica la nuova direzione e intensità
//della velocità. Ritorno il vettore media.
//Per farlo normalizziamo la differenza tra le posizioni e la moltiplichiamo
//per maxvelocity considerando un peso (maggiore se sei più vicino).
//Le singole variazioni sono sommate e divise infine per il numero di
//boid nel raggio (count).
BVector Boid::separation(const std::vector<Boid> boids) 
{
  float count = 0;
  BVector sum;
  for (int i = 0; i < boids.size(); i++)
  {
    float d = position.dist(boids[i].position);
    if (d > 0 && d < SepRange)
    {
      BVector dev;
      dev.setvalue(0,0);
      dev.vectorTwoSub(position, boids[i].position);
      dev.normalize();
      dev.scalarMul(1-d/SepRange);
      dev.scalarMul(maxVel);
      count++;
      sum.vectorSum(dev);
    }
  }
  sum.scalarDiv(count);
  return sum;
}


//Si applica ad un boid e ritorna lo "steer".
//Creo target e lo sottraggo a un vettore in ingresso, così
//che diventi il negativo del punto verso cui tendo. Normalizzo,
//moltiplico per la velocità massima (così diventa velocità). 
//sottraggo alla velocità del boid il nuovo vettore, e ne limito la dimensione.
BVector Boid::seek(BVector v)
{ // v è il target
  BVector target;
  target.vectorSub(v);
  target.normalize(); // v viene normalizzato e reso una velocità
  target.scalarMul(maxVel);
  acceleration.vectorTwoSub(velocity, target); // si fa la differenza fra la direzione del boid e il target
  acceleration.limitsize(maxAcc);
  return acceleration;
}