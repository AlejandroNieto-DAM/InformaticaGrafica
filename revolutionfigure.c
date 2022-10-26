#include "revolutionfigure.h"
#include <vector>
#include <iostream>
#include <GL/glut.h>
#include "calculaNormal.h"
#include <math.h>

using namespace std;

RevolutionFigure::RevolutionFigure(const char *nombre_archivo_pse, float color[], int drawType, int nCaras)
{
    vector<float> firstVertices;
    ply::read_vertices(nombre_archivo_pse, firstVertices);
    for (int i = 0; i < 4; i++)
    {
        this->color[i] = color[i];
    }

    int m = firstVertices.size() / 3;
    numVerticesIniciales = firstVertices.size();

    for (int i = 0; i < nCaras; i++)
    {

        float angle = ((2 * i * PI) / (nCaras - 1));

        for (int j = 0; j < m; j++)
        {
            vertices.push_back(firstVertices[j * 3] * sinf(angle));
            vertices.push_back(firstVertices[(j * 3) + 1]);
            vertices.push_back(firstVertices[j * 3] * cosf(angle));
        }
    }

    for (int i = 0; i < nCaras - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int k = i * m + j;
            if (i == nCaras - 2)
            {
                caras.push_back(k);
                caras.push_back((k + m) % m);
                caras.push_back((k + m + 1) % m);

                caras.push_back(k);
                caras.push_back((k + m + 1) % m);
                caras.push_back(k + 1);
            }
            else
            {
                caras.push_back(k);
                caras.push_back(k + m);
                caras.push_back(k + m + 1);

                caras.push_back(k);
                caras.push_back(k + m + 1);
                caras.push_back(k + 1);
            }
        }
    }

    this->drawType = drawType;

    calculateNormal();
}

void RevolutionFigure::draw()
{

    Figure::draw();

    /*glBegin(GL_POLYGON);
    {

        glNormal3d(0, 1, 0);

        for(int i = numVerticesIniciales - 3; i < vertices.size(); i+= numVerticesIniciales){

            glVertex3d(vertices[i], vertices[i + 1], vertices[i + 2]);

        }



    }
    glEnd ();


    glBegin(GL_POLYGON);
    {

        glNormal3d(0, -1, 0);

        for(int i = vertices.size() - numVerticesIniciales; i >= 0; i-=numVerticesIniciales){
            glVertex3d(vertices[i], vertices[i + 1], vertices[i + 2]);

        }

    }
    glEnd ();*/
}