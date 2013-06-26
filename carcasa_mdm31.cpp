#include <ooml/core.h>
#include <ooml/components.h>
//#include <ooml/parts.h>

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    double ancho_interior = 24;
    double alto_interior = 6;
    double distancia_entre_tornillos = 28.2;
    double diametro_agujeros = 2.5;
    double ancho_exterior = 34;
    double alto_exterior = 7.5;
    double ancho_max_con = 24;
    double ancho_min_con = 21;
    double alto_con = 6;
    double largo_interior = 3.5;
    double largo_exterior = 2.5;
    double largo_con = 5;
    double largo_carcasa = 35;
    double metrica = 3; //metrica tornillos carcasa


    Component mdm31 = RoundedTablet(ancho_exterior+1,alto_exterior+2,largo_exterior+0.6,1).color(1,1,1).translate(0,0,0) //pestañas para tornillos
            + RoundedTablet(ancho_max_con,alto_con,largo_con,2).translate(0,0,largo_con/2+largo_exterior/2).color(1,1,1) //cuerpo conector
            - Cylinder(diametro_agujeros/2,alto_exterior+1).translate(distancia_entre_tornillos/2,0,0).color(1,1,1) //agujero derecho
            - Cylinder(diametro_agujeros/2,alto_exterior+1).translate(-distancia_entre_tornillos/2,0,0).color(1,1,1) //agujero izdo
            + Cube(ancho_interior,alto_interior,largo_interior).translate(0,0,-(largo_interior/2+largo_exterior/2)).color(1,1,1) //bloque pines interior

            ;

    Component carcasamdm31 = Cube(ancho_exterior+4,largo_carcasa/2,alto_interior+8).translate(0,largo_carcasa/4-largo_exterior/2-1,0)
            & Cube(ancho_exterior/2,largo_carcasa/2,alto_interior+8).translate(0,(largo_carcasa/4)+largo_carcasa/2-largo_exterior/2-2,0)
            ;

    Component completo = carcasamdm31
            + Cube(ancho_exterior/2+2,largo_carcasa/3,alto_interior+8).translate(0,(largo_carcasa/6)+largo_carcasa-largo_exterior/2-1-largo_carcasa/6,0)
            - Cube(ancho_exterior/2-3,largo_carcasa-10,alto_exterior+2).rotate(0,0,0).translate(0,largo_carcasa/2+7,0)
            - Cylinder(5.7,35).translate(0,0,-30).rotate(90,0,0)
            - Cylinder(diametro_agujeros/2,alto_exterior+100).translate(distancia_entre_tornillos/2,0,0).rotate(90,0,0).color(1,1,1) //agujero derecho
            - Cylinder(diametro_agujeros/2+1,alto_exterior+17).translate(distancia_entre_tornillos/2,0,-15).rotate(90,0,0).color(1,1,1) //agujero derecho ancho
            - Cylinder(diametro_agujeros/2,alto_exterior+100).translate(-distancia_entre_tornillos/2,0,0).rotate(90,0,0).color(1,1,1) //agujero izdo
            - Cylinder(diametro_agujeros/2+1,alto_exterior+17).translate(-distancia_entre_tornillos/2,0,-15).rotate(90,0,0).color(1,1,1) //agujero izdo ancho
            - Cube(ancho_interior+1,largo_carcasa/2-3,alto_interior+2).translate(0,largo_carcasa/4-largo_exterior/2+.5,-2) //hueco cables pegado conn
            - Cylinder(metrica/2+0.2,50).rotate(0,0,90).translate(ancho_interior/3+1,largo_carcasa/2,0) //tornillo carcasa 1
            - Cylinder(metrica/2+0.2,50).rotate(0,0,90).translate(-ancho_interior/3-1,largo_carcasa/2,0) //tornillo carcasa 2
            - Cylinder(metrica/2+1.5,10).rotate(0,0,90).translate(ancho_interior/3+1,largo_carcasa/2,8) //tornillo carcasa 1
            - Cylinder(metrica/2+1.5,10).rotate(0,0,90).translate(-ancho_interior/3-1,largo_carcasa/2,8) //tornillo carcasa 2

            -Cube(300,300,20).translate(0,0,10)
            - mdm31.rotate(90,0,0).translate(0,0.3,0)


    ;

        IndentWriter writer;
        writer << completo;

    ofstream file("carcasa_mdm31.scad");
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
