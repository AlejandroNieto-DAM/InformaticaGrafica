#ifndef REVOLUTION_FIGURE_H
#define REVOLUTION_FIGURE_H

#include <iostream>
#include "file_ply_stl.h"
#include "figure.h"

#define PI 3.141592653589

using namespace std;

class RevolutionFigure : public Figure {
    protected:
        int nCaras;
        int numVerticesIniciales;

    public:

        RevolutionFigure(const char *nombre_archivo_pse, float color[], int drawType, int nCaras);
        void draw();

};

#endif