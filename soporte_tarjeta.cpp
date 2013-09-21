#include <ooml/core.h>
#include <ooml/components.h>
#include <ooml/parts.h>

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    double a,b,c,d,e,f, distancia_borde, d_tornillo;

    b = 154.2;
    a = 123.4;
    c = 177.5;
    d = 139.3;
    e = 138.9;
    f = 177.4;
    distancia_borde = 5;
    d_tornillo = 4;


    Component tarjeta =
            Cube (distancia_borde*2 + a + b, c + distancia_borde*2, 2, false).color(0.1,1,0.3)
            - Cylinder (d_tornillo/2, 10).translate(distancia_borde,distancia_borde,0) //1
            - Cylinder (d_tornillo/2, 10).translate(distancia_borde+ a,distancia_borde,0) //2
            - Cylinder (d_tornillo/2, 10).translate(distancia_borde+ a + b,distancia_borde,0) //3
            - Cylinder (d_tornillo/2, 10).translate(distancia_borde+ a + b,distancia_borde + c,0) //4
            - Cylinder (d_tornillo/2, 10).translate(distancia_borde+ a + b - d,distancia_borde + c,0) //5
            - Cylinder (d_tornillo/2, 10).translate(distancia_borde+ a + b - d- e,distancia_borde + c,0) //6
            + Cylinder (5,15).rotate(90,0,0).translate(50,175,7).color(0.2,0.2,0.2) //diodo
            + Cylinder (5,15).rotate(90,0,0).translate(100,175,7).color(0.2,0.2,0.2) //diodo
            + Cylinder (5,15).rotate(90,0,0).translate(200,175,7).color(0.2,0.2,0.2) //diodo
            + Cylinder (5,15).rotate(90,0,0).translate(250,175,7).color(0.2,0.2,0.2) //diodo

            ;

    Component soporte_tarjeta1 =
              Cube(e+d_tornillo+8,10,15)
            - Cube((e+d_tornillo+8)-24,12,10).translate(0,0,5)
            - Cylinder (d_tornillo/2, 20).translate(e/2,0,0)
            - Cylinder (d_tornillo/2, 20).translate(-e/2,0,0)
            - Cube (16.1,15,4.1).translate(e/2-2,0,-5.5)
            - Cube (10,12,4.1).translate (-(e+d_tornillo+8)/2+85,0,-5.5)
            - Cylinder (d_tornillo/2, 20).translate (-(e+d_tornillo+8)/2+85,0,-5.5)
                        ;

    Component soporte_tarjeta2 =
              Cube(d+d_tornillo+8,10,15)
            - Cube((d+d_tornillo+8)-24,12,10).translate(0,0,5)
            - Cylinder (d_tornillo/2, 20).translate(e/2,0,0)
            - Cylinder (d_tornillo/2, 20).translate(-e/2,0,0)
            - Cube (16.1,14,11.1).translate(d/2+1.8,0,2)
            + Cube (4,10,3.95).translate(e/2+8,0,-5.5)
            - Cube (10,12,4.1).translate (-(d+d_tornillo+8)/2+57,0,-5.5)
            - Cylinder (d_tornillo/2, 20).translate (-(d+d_tornillo+8)/2+57,0,-5.5)
                                    ;

     Component soporte_tarjeta3 =
            Cube(a+d_tornillo+8, 10, 15)
            - Cylinder (d_tornillo/2, 20).translate(a/2,0,0)
            - Cylinder (d_tornillo/2, 20).translate(-a/2,0,0)
             - Cube (10,12,4.1).translate ((a+d_tornillo+8)/2-85,0,-5.5)
             - Cylinder (d_tornillo/2, 20).translate ((a+d_tornillo+8)/2-85,0,0)
             - Cube(16.1,12,11.1).translate(-(a+d_tornillo+8)/2+8,0,2)
            ;

     Component soporte_tarjeta4 =
            Cube(b+d_tornillo+8, 10, 15)
            - Cylinder (d_tornillo/2, 20).translate(b/2,0,0)
            - Cylinder (d_tornillo/2, 20).translate(-b/2,0,0)
             - Cube (10,12,4.1).translate (-(b+d_tornillo+8)/2+57,0,-5.5)
             - Cylinder (d_tornillo/2, 20).translate (-(b+d_tornillo+8)/2+57,0,0)
             - Cube(16.1,12,4.1).translate((b+d_tornillo+8)/2-8,0,-5.5)
            ;

      Component soporte_tarjeta5 =
              Cube(190,10,15)
              - Cylinder(d_tornillo/2, 20).translate(190/2-5,0,0)
              - Cylinder(d_tornillo/2, 20).translate(-190/2+5,0,0)
              - Cube(11,11,11.1).translate(-190/2+5,0,2)
              - Cube(11,11,11.1).translate(190/2-5,0,2)
              - Cube(11,11,3).translate(190/2-8,0,6.1)
              ;

      Component soporte_tarjeta6 =
              Cube(190,10,15)
              - Cylinder(d_tornillo/2, 20).translate(190/2-5,0,0)
              - Cylinder(d_tornillo/2, 20).translate(-190/2+5,0,0)
              - Cube(11,11,11.1).translate(-190/2+5,0,2)
              - Cube(11,11,11.1).translate(190/2-5,0,2)
              ;

    //Component total = tarjeta + soporte_tarjeta.translate(distancia_borde-(d_tornillo/2)-0.5,distancia_borde*2+f-10,0);
    Component total = soporte_tarjeta4.rotate(90,0,0);



        IndentWriter writer;
        writer << total;

    ofstream file("soporte_tarjeta.scad");
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
