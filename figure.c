#include "figure.h"
#include <vector>
#include <iostream>
#include <GL/glut.h>
#include "calculaNormal.h"


Figure::Figure(){
    
}

Figure::Figure(const char *nombre_archivo_pse, float color[], int drawType)
{
    ply::read(nombre_archivo_pse, vertices, caras);
    for (int i = 0; i < 4; i++)
    {
        this->color[i] = color[i];
    }

    this->drawType = drawType;
    calculateNormal();
}

void Figure::calculateNormal()
{

    if (drawType == 1)
    {
        normales.reserve(vertices.size());
        accesosNormales.reserve(vertices.size() / 3);

        for (int i = 0; i < normales.size(); i++)
        {
            normales[i] = 0;
        }

        for (int i = 0; i < accesosNormales.size(); i++)
        {
            accesosNormales[i] = 0;
        }

        for (int i = 0; i < caras.size(); i += 3)
        {
            double V1[3] = {vertices[caras[i] * 3], vertices[(caras[i] * 3) + 1], vertices[(caras[i] * 3) + 2]};
            double V2[3] = {vertices[caras[i + 1] * 3], vertices[(caras[i + 1] * 3) + 1], vertices[(caras[i + 1] * 3) + 2]};
            double V3[3] = {vertices[caras[i + 2] * 3], vertices[(caras[i + 2] * 3) + 1], vertices[(caras[i + 2] * 3) + 2]};
            double *sol = normal::calculaNormal(V1, V2, V3);

            normales[caras[i] * 3] += sol[0];
            normales[(caras[i] * 3) + 1] += sol[1];
            normales[(caras[i] * 3) + 2] += sol[2];

            normales[caras[i + 1] * 3] += sol[0];
            normales[(caras[i + 1] * 3) + 1] += sol[1];
            normales[(caras[i + 1] * 3) + 2] += sol[2];

            normales[caras[i + 2] * 3] += sol[0];
            normales[(caras[i + 2] * 3) + 1] += sol[1];
            normales[(caras[i + 2] * 3) + 2] += sol[2];

            accesosNormales[caras[i]] += 1.0;
            accesosNormales[caras[i + 1]] += 1.0;
            accesosNormales[caras[i + 2]] += 1.0;
            
        }
    }
    else
    {

        normales.reserve(caras.size());

        for (int i = 0; i < caras.size(); i += 3)
        {
            double V1[3] = {vertices[caras[i] * 3], vertices[(caras[i] * 3) + 1], vertices[(caras[i] * 3) + 2]};
            double V2[3] = {vertices[caras[i + 1] * 3], vertices[(caras[i + 1] * 3) + 1], vertices[(caras[i + 1] * 3) + 2]};
            double V3[3] = {vertices[caras[i + 2] * 3], vertices[(caras[i + 2] * 3) + 1], vertices[(caras[i + 2] * 3) + 2]};
            double *sol = normal::calculaNormal(V1, V2, V3);

            normales[i] = sol[0];
            normales[i + 1] = sol[1];
            normales[i + 2] = sol[2];
        }
    }
}

void Figure::draw()
{

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

    glBegin(GL_TRIANGLES);
    {

        for (int i = 0; i < caras.size(); i += 3)
        {

            if (drawType == 1)
            {
                glNormal3d(normales[caras[i] * 3] / accesosNormales[caras[i]], normales[(caras[i] * 3) + 1] / accesosNormales[caras[i]], normales[(caras[i] * 3) + 2] / accesosNormales[caras[i]]);
                glVertex3d(vertices[caras[i] * 3], vertices[(caras[i] * 3) + 1], vertices[(caras[i] * 3) + 2]);
            
                glNormal3d(normales[caras[i + 1] * 3] / accesosNormales[caras[i + 1]], normales[(caras[i + 1] * 3) + 1] / accesosNormales[caras[i + 1]], normales[(caras[i + 1] * 3) + 2] / accesosNormales[caras[i + 1]]);
                glVertex3d(vertices[caras[i + 1] * 3], vertices[(caras[i + 1] * 3) + 1], vertices[(caras[i + 1] * 3) + 2]);
               
                glNormal3d(normales[caras[i + 2] * 3] / accesosNormales[caras[i + 2]], normales[(caras[i + 2] * 3) + 1] / accesosNormales[caras[i + 2]], normales[(caras[i + 2] * 3) + 2] / accesosNormales[caras[i + 2]]);
                glVertex3d(vertices[caras[i + 2] * 3], vertices[(caras[i + 2] * 3) + 1], vertices[(caras[i + 2] * 3) + 2]);

            }
            else
            {
                glNormal3d(normales[i], normales[i + 1], normales[i + 2]);
                glVertex3d(vertices[caras[i] * 3], vertices[(caras[i] * 3) + 1], vertices[(caras[i] * 3) + 2]);
                glVertex3d(vertices[caras[i + 1] * 3], vertices[(caras[i + 1] * 3) + 1], vertices[(caras[i + 1] * 3) + 2]);
                glVertex3d(vertices[caras[i + 2] * 3], vertices[(caras[i + 2] * 3) + 1], vertices[(caras[i + 2] * 3) + 2]);
            }
        }
    }
    glEnd();
}
