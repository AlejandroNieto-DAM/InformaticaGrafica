#ifndef __CUBO_H
#define __CUBO_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "modelo.h"

class Cubo : public Objeto3D {
  
  private:
    float tamLado;
  
  public:
    Cubo();

    Cubo(float tamLado);

    void draw();
  
};

#endif
