#include <ooml/core.h>
#include <ooml/components.h>
#include <ooml/parts.h>

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    double distancia_tornillos_x, distancia_tornillos_y, diam_deutsch, diam_tornillos, ancho, alto, grosor_max, diam_deutsch_ext, ancho_electronica, largo_electronica;

    distancia_tornillos_x = 145.5;
    distancia_tornillos_y = 35.5;
    diam_deutsch = 24;
    diam_tornillos = 5;
    ancho = 165;
    alto = 55.5;
    grosor_max = 3;
    diam_deutsch_ext = 30;
    ancho_electronica = 53;
    largo_electronica = 95;

    Component deutsch = Cube(ancho, alto, grosor_max*2) //cuerpo
            - Cylinder(diam_tornillos/2,grosor_max*2+1).translate(distancia_tornillos_x/2,distancia_tornillos_y/2,0) //tornillo (superior dcha)
            - Cylinder(diam_tornillos/2,grosor_max*2+1).translate(-distancia_tornillos_x/2,distancia_tornillos_y/2,0) //tornillo (superior izda)
            - Cylinder(diam_tornillos/2,grosor_max*2+1).translate(distancia_tornillos_x/2,-distancia_tornillos_y/2,0) //tornillo (inferior dcha)
            - Cylinder(diam_tornillos/2,grosor_max*2+1).translate(-distancia_tornillos_x/2,-distancia_tornillos_y/2,0) //tornillo (inferior izda)
            - Cylinder(diam_deutsch/2,grosor_max+2).translate(0,0,-grosor_max/2-0.5) //agujero deutsch
            - Cylinder(diam_deutsch_ext/2,grosor_max+0.5).translate(0,0,grosor_max/2+0.5) //agujero deutsch exterior
            + Cube(ancho, alto, grosor_max*2).translate(0,0,grosor_max*2) //cuerpo
            - RoundedTablet(ancho-10, alto-10, grosor_max*2+1,5).translate(0,0,grosor_max*2) //cuerpo
            + Cube(5,alto,grosor_max*2+ancho_electronica).translate(largo_electronica/2-2.5+5,0,grosor_max*2+ancho_electronica/2) //soporte exterior derecho
            + Cube(5,alto,grosor_max*2).translate(largo_electronica/4-2.5,0,grosor_max*2)
            + Cube(5,alto,grosor_max*2+ancho_electronica).translate(-(largo_electronica/2-2.5+5),0,grosor_max*2+ancho_electronica/2) //soporte exterior izdo
            + Cube(5,alto,grosor_max*2).translate(-(largo_electronica/4-2.5),0,grosor_max*2)
            + Cube(largo_electronica,5,ancho_electronica).translate(0,-(alto/2-2.5),ancho_electronica/2+grosor_max*3) //soporte pcb
            - Cube(largo_electronica-20,6,ancho_electronica-10).translate(0,-(alto/2-2.5),ancho_electronica/2+grosor_max*3+5.1)
            + Cube ((ancho-largo_electronica)/2,5,grosor_max*2).translate((ancho-largo_electronica)/4+largo_electronica/2,0,2*grosor_max)
            + Cube ((ancho-largo_electronica)/2,5,grosor_max*2).translate(40,0,2*grosor_max)
            + Cube ((ancho-largo_electronica)/2,5,grosor_max*2).translate(-((ancho-largo_electronica)/4+largo_electronica/2),0,2*grosor_max)
            + Cube ((ancho-largo_electronica)/2,5,grosor_max*2).translate(-40,0,2*grosor_max)
            - Cube (largo_electronica+11,alto*2,alto*2).rotate(45,0,0).translate(0,45,70)

            ;


        IndentWriter writer;
        writer << deutsch;

    ofstream file("deutsch.scad");
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
