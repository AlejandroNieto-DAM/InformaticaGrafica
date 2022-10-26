#include "cubo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>


Cubo::Cubo(){
    tamLado = 2;
}

Cubo::Cubo(float tamLado){
    tamLado = tamLado;
}

void Cubo::draw() {
    float color[4]={0.8,0.0,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color );
    glBegin(GL_QUAD_STRIP);
    {

        glNormal3f( 0, 0, 1);
        glVertex3f( tamLado, tamLado, tamLado );
        glVertex3f( 0, tamLado, tamLado );
        glVertex3f( tamLado, 0, tamLado );
        glVertex3f( 0, 0, tamLado );
        glNormal3f( 0.0, -1.0, 0.0 ); /*Inferior */
        glVertex3f( tamLado, 0, 0 );
        glVertex3f( 0, 0, 0 );
        glNormal3f(0, 0, -1 );
        glVertex3f( tamLado, tamLado, 0 );
        glVertex3f( 0, tamLado, 0 );
        glNormal3f( 0.0, 1.0, 0.0 ); /* Superior, horizontal */
        glVertex3f( tamLado, tamLado, tamLado );
        glVertex3f( 0, tamLado, tamLado );
    }
    glEnd ();

    glBegin( GL_QUADS );{ /* Costados */
        glNormal3f( 1, 0, 0);
        glVertex3f( tamLado, 0, 0 );
        glVertex3f( tamLado, tamLado, 0 );
        glVertex3f( tamLado, tamLado, tamLado );
        glVertex3f( tamLado, 0, tamLado );

        glNormal3f( -1, 0, 0);
        glVertex3f( 0, 0, 0 );
        glVertex3f( 0, 0, tamLado );
        glVertex3f( 0, tamLado, tamLado );
        glVertex3f( 0, tamLado, 0 ); 
    }

    glEnd();
}


