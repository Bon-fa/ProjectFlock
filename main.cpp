#include "Boid.h"
#include "BVector.h"

using namespace std;

int main ()
{
    BVector v1(2,5);
    BVector v2;
    Boid b(v1, v2);
    std::cout << b.acceleration.x << endl;
    std::cout << b.velocity.x << endl;
    std::cout << b.position.x << endl;
    std::cout << endl;
    std::cout << b.acceleration.y << endl;
    std::cout << b.velocity.y << endl;
    std::cout << b.position.y << endl;
}