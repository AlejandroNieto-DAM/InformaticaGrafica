#include <math.h>
#include "calculaNormal.h"

namespace normal
{

  using namespace std;

  double *calculaNormal(double punto1[], double punto2[], double punto3[])
  {
    double A[3];
    double B[3];
    static double sol[3];

    for (int i = 0; i < 3; i++)
    {
      A[i] = punto3[i] - punto2[i];
      B[i] = punto1[i] - punto2[i];
    }

    sol[0] = (A[1] * B[2] - A[2] * B[1]);
    sol[1] = -(A[0] * B[2] - A[2] * B[0]);
    sol[2] = (A[0] * B[1] - A[1] * B[0]);

    double modS = sqrt((sol[0] * sol[0] + sol[1] * sol[1] + sol[2] * sol[2]));
    
    for (int i = 0; i < 3; i++)
    {
      sol[i] = sol[i] / modS;
    }

    return sol;
  }

};

//Hacemos una funciona ala que le pasamos la normal calculada
