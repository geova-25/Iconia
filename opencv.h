#ifndef OPENCV_H
#define OPENCV_H
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class OpenCV
{
public:
    OpenCV();
    void cargarImagen();



private:
    bool verificar_igualdad(int i, int j);
    int* encuentre_vacio();
    int sacarMayor(Mat img, int x, int y);
    bool verificar_desigualdad(int i, int j);
    int promedio1(int red, int green, int blue);
    int promedio2(int red, int green, int blue);
    void puntos(Mat img1,Mat img2);
    void acercar(int pixel);
    void encuentre_cuadrado(int x, int y);
    int resultadoPro;
    int listaFun[];
    bool bandera=false;
    bool banderaColor=true;
    int mayor=0;
    bool parecido=true;
    Mat img;
    Mat img2;

};

#endif // OPENCV_H
