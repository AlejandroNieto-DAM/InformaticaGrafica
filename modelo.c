/*	Prácticas de Informática Gráfica

  Grupo C					Curso 2022-23

  Codigo base para la realización de las practicas de IG

  Estudiante:

=======================================================
  G. Arroyo, J.C. Torres
  Dpto. Lenguajes y Sistemas Informticos
  (Univ. de Granada)

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details
 http://www.gnu.org/copyleft/gpl.html

=======================================================/
modulo modelo.c
    Representación del modelo
    Funciones de dibujo
    Función Idle

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h> // Libreria de utilidades de OpenGL
#include "practicasIG.h"
//#include "cubo.h"
//#include "npyramid.h"
//#include "pyramid.h"

#include "figure.h"
#include "revolutionfigure.h"

#include "estructura.h"

#define PI 3.141592653589

int modo = GL_FILL;
int iluminacion = 1;
int modoVisualizacion = GL_FLAT;
float alturaGancho = -7, alturaG = -7;
float despBrazo = 0;
float angleG = 0;
float anguloGrua = 0;
float angleB = 0;
float anguloBrazo = 0;
float despGancho = 3, despG = 3;
bool animacion = 0;

void changeAnimacion()
{
  animacion = !animacion;
}

void addDespGancho()
{
  despGancho += 0.25;
  if (despGancho > 12)
    despGancho = 12;
}

void lessDespGancho()
{
  despGancho -= 0.25;
  if (despGancho < 0)
    despGancho = 0;
}

void addAlturaGancho()
{
  alturaGancho -= 0.10;
  if (alturaGancho < -9)
    alturaGancho = -9;
}

void lessAlturaGancho()
{
  alturaGancho += 0.10;
  if (alturaGancho > 0)
    alturaGancho = 0;
}

void addAnguloTorre()
{
  anguloGrua += 1;
  if (anguloGrua > 360)
    anguloGrua = 0;
}

void lessAnguloTorre()
{
  anguloGrua -= 1;
  if (anguloGrua < 0)
    anguloGrua = 360;
}

void addAnguloBrazo()
{
  anguloBrazo += 1;
  if (anguloBrazo > 360)
    anguloBrazo = 0;
}

void lessAnguloBrazo()
{
  anguloBrazo -= 1;
  if (anguloBrazo < 0)
    anguloBrazo = 360;
}

void setModo(int M)
{
  modo = M;
}

void cambiarIluminacion()
{
  // iluminacion = !iluminacion;
  float v = 1;
  anguloGrua += v;
}

void cambiarModoVisualizacion()
{
  if (modoVisualizacion == GL_FLAT)
  {
    modoVisualizacion = GL_SMOOTH;
  }
  else
  {
    modoVisualizacion = GL_FLAT;
  }
}

/**	void initModel()

Inicializa el modelo y de las variables globales


**/
void initModel()
{
}

class Ejes : Objeto3D
{
public:
  float longitud = 30;
  // Dibuja el objeto
  void draw()
  {
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    {
      glColor3f(0, 1, 0);
      glVertex3f(0, 0, 0);
      glVertex3f(0, longitud, 0);

      glColor3f(1, 0, 0);
      glVertex3f(0, 0, 0);
      glVertex3f(longitud, 0, 0);

      glColor3f(0, 0, 1);
      glVertex3f(0, 0, 0);
      glVertex3f(0, 0, longitud);
    }
    glEnd();
  }
};

Ejes ejesCoordenadas;
// Cubo cubo;
// Pyramid piramide;
// nPyramid cono(2, 5, 100, 1);

/*float color1[4] = {0.8,0.0,1,1};
float color2[4] = {0, 1, 0, 1};
float color3[4] = {0, 0, 1, 1};
Figure beethovenFlat("plys/beethoven.ply", color1, 0);
Figure bigDodge("plys/big_dodge.ply", color2, 1);
RevolutionFigure peon("plys/perfil.ply", color3, 0, 10);*/

/**	void Dibuja( void )

Procedimiento de dibujo del modelo. Es llamado por glut cada vez que se debe redibujar.

**/

void Dibuja(void)
{
  static GLfloat pos[4] = {5.0, 5.0, 10.0, 0.0}; // Posicion de la fuente de luz

  float color[4] = {0.8, 0.0, 1, 1};

  glPushMatrix(); // Apila la transformacion geometrica actual

  glClearColor(0.0, 0.0, 0.0, 1.0); // Fija el color de fondo a negro

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Inicializa el buffer de color y el Z-Buffer

  transformacionVisualizacion(); // Carga transformacion de visualizacion

  glLightfv(GL_LIGHT0, GL_POSITION, pos); // Declaracion de luz. Colocada aqui esta fija en la escena

  ejesCoordenadas.draw(); // Dibuja los ejes

  if (iluminacion == 1)
  {
    glEnable(GL_LIGHTING);
  }
  else
  {
    glDisable(GL_LIGHTING);
  }

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

  glPolygonMode(GL_FRONT_AND_BACK, modo);

  // COMIENZA EL CODIGO DE LA GRUA

  // ROTACION GRUA
  glRotatef(anguloGrua, 0, 1, 0);

  glPushMatrix();

  creaEstructura(0, 0, 0, 0, 10, 0, 2, 2, 5);
  glTranslatef(0, 10, 0);
  caja(1.6, 1, 1.6);
  glTranslatef(0, 1, 0);
  // ROTACION BRAZO
  glRotatef(anguloBrazo, 0, 1, 0);

  glPushMatrix();
  creaTorre(0, 0, 0, 0, 5, 0, 2, 2, 3);
  creaBrazo(-15, 0, 0, -1, 0, 0, 2, 9);
  creaEstructura(10, 0.5, 0, 1, 0.5, 0, 1, 2, 5);
  glTranslatef(9, -2, 0);
  caja(2, 2, 2);
  glTranslatef(-23, +2, 0);

  glPushMatrix();
  glTranslatef(despGancho, -0.25, 0);
  caja(2, 0.25, 2);

  glPushMatrix();
  cilindro(0, 0, 0, 0, alturaGancho, 0, 0.1);
  creaGancho(0, alturaGancho, 0, 1);
  glTranslatef(0, 0.25, 0);
  cilindro(0, 0, 0, 14 - despGancho, 5, 0, 0.1);
  glTranslatef(14 - despGancho, 5, 0);
  cilindro(0, 0, 0, 9, -5, 0, 0.1);

  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

  /*glShadeModel(GL_SMOOTH);
  glTranslatef(0, 0, 0);
  peon.draw();

  glShadeModel(GL_FLAT);
  glTranslatef(8, 0, 0);
  beethovenFlat.draw();


  glShadeModel(GL_SMOOTH);
  glTranslatef(13, 0, 0);
  bigDodge.draw();*/

  glPopMatrix(); // Desapila la transformacion geometrica

  glutSwapBuffers(); // Intercambia el buffer de dibujo y visualizacion
}

/**	void idle()

Procedimiento de fondo. Es llamado por glut cuando no hay eventos pendientes.

**/
bool rollingDesp = false;
bool rollingAltura = false;
bool rollingBrazo = false;
void idle(int v)
{

  glutPostRedisplay();        // Redibuja
  glutTimerFunc(30, idle, 0); // Vuelve a activarse dentro de 30 ms

  if (animacion == true)
  {

    if (despG < 18 and !rollingDesp)
    {
      addDespGancho();
      despG += 0.15;
    }
    else
    {
      rollingDesp = true;
    }

    if (despG > 0 and rollingDesp)
    {
      lessDespGancho();
      despG -= 0.15;
    }
    else
    {
      rollingDesp = false;
    }

    if (alturaG < 21 and !rollingAltura)
    {
      addAlturaGancho();
      alturaG += 0.25;
    }
    else
    {
      rollingAltura = true;
    }

    if (alturaG > 0 and rollingAltura)
    {
      lessAlturaGancho();
      alturaG -= 0.25;
    }
    else
    {
      rollingAltura = false;
    }

    if (despBrazo < 270 and !rollingBrazo)
    {
      addAnguloBrazo();
      despBrazo += 1;
    }
    else
    {
      rollingBrazo = true;
    }

    if (despBrazo > 0 and rollingBrazo)
    {
      lessAnguloBrazo();
      despBrazo -= 1;
    }
    else
    {
      rollingBrazo = false;
    }
  }
}
