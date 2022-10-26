#ifndef _NPYRAMID_H
#define _NPYRAMID_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "modelo.h"

#define PI 3.141592653589

class nPyramid: public Objeto3D {
  private:
    double tamLado;
    double alto;
    double escala;
    int numLados;
    double angle;
    
  public:

    nPyramid();

    nPyramid(double tamLado, double alto, int numLados, double escala);

    void draw();
    
};

#endif