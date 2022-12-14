#ifndef BVECTOR_H
#define BVECTOR_H

class BVector
{
public:
    float x;
    float y;
    float z;
    
    BVector() {}                      // costruttore interno con zero informazioni in ingresso
    BVector(float xComp, float yComp) // costruttore con info in ingresso
    {
        x = xComp;
        y = yComp;
    }

    void setvalue (float a, float b); //setta x e y dei vettori non inizializzati
    void vectorSum(const BVector &v); //somma tra vettore in analisi e un secondo
    void vectorSub(const BVector &v); //sottrazione tra vettore in analisi e un secondo
    BVector vectorTwoSub (const BVector &v, const BVector &u); //sottrazione tra due vettori
    float vectorSProd(const BVector &v); //prodotto scalare
    void scalarSum(float s); //somma componenti e scalare
    void scalarSub(float s); //sottrazione fra componenti e scalare
    void scalarMul(float s); //moltiplicazione di un vettore con uno scalare
    void scalarDiv(float s); //divisione di un vettore con uno scalare

    void limitsize(); //limita la dimensione di un vettore
    float dist(const BVector &v); //calcola la distanza tra due vettori
    float norm(); //norma di un vettore
    float angle(const BVector &v); //angolo compreso tra due vettori
    void normalize(); //?
};
#endif