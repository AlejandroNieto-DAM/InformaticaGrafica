#include "pyramid.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

Pyramid::Pyramid()
{
    tamLado = 2;
    alto = 2;
}

Pyramid::Pyramid(float tamLado, float alto)
{
    tamLado = tamLado;
    alto = alto;
}

void Pyramid::draw()
{

    float color[4] = {1, 0, 0, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

    glBegin(GL_TRIANGLE_STRIP);
    {

        glNormal3d(0, 0, 1);
        glVertex3d(tamLado, 0, tamLado);
        glVertex3d(tamLado / 2, alto, tamLado / 2);
        glVertex3d(0, 0, tamLado);
        glNormal3d(0, -1, 0);
        glVertex3d(0, 0, 0);
        glVertex3d(tamLado, 0, tamLado);
        glNormal3d(0, -1, 0);
        glVertex3d(0, 0, 0);
        glVertex3d(tamLado, 0, 0);
        glNormal3d(0, 0, -1);
        glVertex3d(0, 0, 0);
        glVertex3d(tamLado / 2, alto, tamLado / 2);
    }

    glEnd();

    glBegin(GL_TRIANGLES);
    {
        glNormal3d(1, 0, 0);
        glVertex3d(tamLado, 0, 0);
        glVertex3d(tamLado / 2, alto, tamLado / 2);
        glVertex3d(tamLado, 0, tamLado);

        glNormal3d(-1, 0, 0);
        glVertex3d(0, 0, 0);
        glVertex3d(tamLado / 2, alto, tamLado / 2);
        glVertex3d(0, 0, tamLado);
    }
    glEnd();
}
