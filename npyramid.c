#include "npyramid.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "calculaNormal.h"

nPyramid::nPyramid(){
    tamLado =  2; 
    alto = 3;
    escala = 1;
    numLados = 3;
    angle = ((360.0/numLados) * PI) / 180.0;
}

nPyramid::nPyramid(double tamLado, double alto, int numLados, double escala){
    this->alto = alto;
    this->tamLado = tamLado;
    this->numLados = numLados;
    this->escala = escala;
    angle = ((360.0/numLados) * PI) / 180.0;
}

void nPyramid::draw(){
    
    float color[4]={0,1,0,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color );

    glBegin(GL_TRIANGLE_FAN);
    {

        double V1[3] = {tamLado, alto, tamLado};
       
        glVertex3d(tamLado, alto, tamLado);

        for(int i = 0; i < numLados; i++){
          double V2[3] = {tamLado + escala * sin(angle * (i%numLados)), 0, tamLado + escala * cos(angle*(i%numLados))};
          double V3[3] = {tamLado + escala * sin(angle * ((i+1)%numLados)), 0, tamLado + escala * cos(angle*((i+1)%numLados))};
          double * sol = normal::calculaNormal(V1, V2, V3);
          glNormal3d(sol[0], sol[1], sol[2]);

          glVertex3d(tamLado + escala * sin(angle * (i%numLados)), 0, tamLado + escala * cos(angle*(i%numLados)));
          glVertex3d(tamLado + escala * sin(angle * ((i+1)%numLados)), 0, tamLado + escala * cos(angle*((i+1)%numLados)));   

        }  

    }
    glEnd();

    glBegin(GL_POLYGON);
    {

        double V1[3] = {tamLado + escala * sin(angle * 0), 0, tamLado + escala * cos(angle * 0)};
        double V2[3] = {tamLado + escala * sin(angle * 1), 0, tamLado + escala * cos(angle * 1)};
        double V3[3] = {tamLado + escala * sin(angle * 2), 0, tamLado + escala * cos(angle * 2)};
        double * sol = normal::calculaNormal(V3, V2, V1);
        glNormal3d(sol[0], sol[1], sol[2]);

        for(int i = (numLados - 1); i >= 0; i--){
          glVertex3d(tamLado + escala * sin(angle * (i)), 0, tamLado + escala * cos(angle*(i)));
        }

    }
    glEnd();

}