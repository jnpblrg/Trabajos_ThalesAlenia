#include <ooml/core.h>
#include <ooml/components.h>
//#include <ooml/parts.h>

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    double altura_tornillo, largo, ancho, distancia_tornillo, grosor;

    altura_tornillo = 6;
    largo = 15;
    distancia_tornillo = 10; //confirmar
    ancho = 6;
    grosor = 2;


    Component escuadra =

            Cube(largo, ancho, grosor )
            + Cube (grosor, ancho, altura_tornillo+5).translate(-(largo/2+grosor/2),0,(altura_tornillo+5)/2-grosor/2)
            - RoundedTablet (8,3,grosor+2,3).translate(2,0,0)
            - Cylinder (1.5, grosor +2).rotate(0,90,0).translate(-(largo/2+grosor/2),0, altura_tornillo)
            + Cube (5, ancho, 1.9).translate(-5.8,0,-3.7).rotate(0,45,0)

            ;



        IndentWriter writer;
        writer << escuadra;

    ofstream file("escuadra_subd15.scad");
    if (file){
        //generate OpenScad code of the translated cube and save it into file;
        file << writer;
        file.close();
    }else{
        cerr << "Error, cannot open the file" << endl;
    }

    cout << "Done" << endl;

    return 0;
}
