#ifndef _PYRAMID_H
#define _PYRAMID_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "modelo.h"

class Pyramid: public Objeto3D
{
  private:
    float tamLado;
    float alto;

  public:
  
    Pyramid();

    Pyramid(float tamLado, float alto);

    void draw();

};

#endif


