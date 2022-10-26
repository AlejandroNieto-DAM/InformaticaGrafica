#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "file_ply_stl.h"


using namespace std;

class Figure {
    protected:
        vector<float> vertices;
        vector<int> caras;
        vector<float> normales;
        vector<float> accesosNormales;
        float color[4];
        int drawType;

        void calculateNormal();

    public: 

        Figure();
        Figure(const char *nombre_archivo_pse, float color[], int drawType);

        void draw();

};

#endif